// Filename: physicsManager.h
// Created by:  charles (14Jun00)
// 
////////////////////////////////////////////////////////////////////

#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include <pandabase.h>
#include <pointerTo.h>

#include "physical.h"
#include "linearForce.h"
#include "angularForce.h"
#include "linearIntegrator.h"
#include "angularIntegrator.h"
#include "physicalNode.h"

#include <list>
#include <vector>

////////////////////////////////////////////////////////////////////
//       Class : PhysicsManager
// Description : Physics don't get much higher-level than this.
//               Attach as many Physicals (particle systems, etc..)
//               as you want, pick an integrator and go.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDAPHYSICS PhysicsManager {
private:
  // NOTE that the physicals container is NOT reference counted.
  // this does indeed mean that you are NOT supposed to use this
  // as a primary storage container for the physicals.  This is so
  // because physicals, on their death, ask to be removed from their
  // current physicsmanager, if one exists, relieving the client from
  // the task and also allowing for dynamically created and destroyed
  // physicals.
  vector< Physical * > _physicals;
  vector< PT(LinearForce) > _linear_forces;
  vector< PT(AngularForce) > _angular_forces;

  PT(LinearIntegrator) _linear_integrator;
  PT(AngularIntegrator) _angular_integrator;

public:
  PhysicsManager(void);
  virtual ~PhysicsManager(void);

  INLINE void attach_linear_integrator(LinearIntegrator *i);
  INLINE void attach_angular_integrator(AngularIntegrator *i);
  INLINE void attach_physical(Physical *p);
  INLINE void attach_physicalnode(PhysicalNode *p);
  INLINE void add_linear_force(LinearForce *f);
  INLINE void add_angular_force(AngularForce *f);
  INLINE void clear_linear_forces(void);
  INLINE void clear_angular_forces(void);
  INLINE void clear_physicals(void);

  void remove_physical(Physical *p);
  void remove_linear_force(LinearForce *f);
  void remove_angular_force(AngularForce *f);
  void do_physics(float dt);

  friend class Physical;
};

#include "physicsManager.I"

#endif // PHYSICSMANAGER_H
