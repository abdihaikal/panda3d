// Filename: baseForce.cxx
// Created by:  charles (08Aug00)
// 
////////////////////////////////////////////////////////////////////

#include "baseForce.h"

TypeHandle BaseForce::_type_handle;

////////////////////////////////////////////////////////////////////
//    Function : BaseForce
//      Access : protected
// Description : constructor
////////////////////////////////////////////////////////////////////
BaseForce::
BaseForce(bool active) :
  _force_node(NULL), _active(active) {
}

////////////////////////////////////////////////////////////////////
//    Function : BaseForce
//      Access : protected
// Description : copy constructor
////////////////////////////////////////////////////////////////////
BaseForce::
BaseForce(const BaseForce &copy) :
  TypedReferenceCount(copy) {
  _active = copy._active;
  _force_node = (ForceNode *) NULL;
}

////////////////////////////////////////////////////////////////////
//    Function : ~BaseForce
//      Access : public, virtual
// Description : destructor
////////////////////////////////////////////////////////////////////
BaseForce::
~BaseForce(void) {
}
