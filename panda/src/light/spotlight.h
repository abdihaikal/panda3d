// Filename: spotlight.h
// Created by:  mike (09Jan97)
//
////////////////////////////////////////////////////////////////////
//
#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
//
////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////
#include <pandabase.h>

#include <graphicsStateGuardian.h>
#include <luse.h>
#include <map>
#include <namedNode.h>
#include <frustum.h>
#include "light.h"
#include <projectionNode.h>

////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//       Class : Spotlight
// Description :
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA Spotlight : public Light, public ProjectionNode
{
  public:

    Spotlight( const string& name = "" );
    ~Spotlight( void ) { }

    virtual void apply( GraphicsStateGuardian* gsg ) {
      gsg->apply_light( this );
    }

    virtual void output( ostream &out ) const;
    virtual void write( ostream &out, int indent_level = 0 ) const;

    INLINE float get_exponent( void ) const;
    INLINE void set_exponent( float exponent );

    float get_cutoff_angle( void ) const;

    INLINE Colorf get_specular( void ) const;
    INLINE void set_specular( const Colorf& color );

    INLINE float get_constant_attenuation( void ) const;
    INLINE void set_constant_attenuation( float att );

    INLINE float get_linear_attenuation( void ) const;
    INLINE void set_linear_attenuation( float att );

    INLINE float get_quadratic_attenuation( void ) const;
    INLINE void set_quadratic_attenuation( float att );

    bool make_image(Texture* texture, float radius = 0.7);
    NamedNode* make_geometry(float intensity = 0.05, float length = 20.0,
	int num_facets = 36);

  protected:

    float                               _exponent;
    Colorf                              _specular;
    float				_constant_attenuation;
    float				_linear_attenuation;
    float				_quadratic_attenuation;

  public:

    static TypeHandle get_class_type( void ) {
      return _type_handle;
    }
    static void init_type( void ) {
      Light::init_type();
      ProjectionNode::init_type();
      register_type( _type_handle, "Spotlight",
			   Light::get_class_type(),
			   ProjectionNode::get_class_type() );
    }
    virtual TypeHandle get_type( void ) const {
      return get_class_type();
    }
    virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
    virtual TypeHandle get_light_type( void ) const {
      return get_class_type();
    }

  private:

    static TypeHandle                   _type_handle;
};

INLINE ostream &operator << (ostream &out, const Spotlight &light) {
  light.output(out);
  return out;
}

#include "spotlight.I"

#endif
