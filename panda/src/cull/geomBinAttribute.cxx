// Filename: geomBinAttribute.cxx
// Created by:  drose (07Apr00)
// 
////////////////////////////////////////////////////////////////////

#include "geomBinAttribute.h"
#include "geomBinTransition.h"

#include <graphicsStateGuardianBase.h>
#include <indent.h>

TypeHandle GeomBinAttribute::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::get_handle
//       Access: Public, Virtual
//  Description: Returns the handle of the associated transition.
////////////////////////////////////////////////////////////////////
TypeHandle GeomBinAttribute::
get_handle() const {
  return GeomBinTransition::get_class_type();
}

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::make_copy
//       Access: Public, Virtual
//  Description: Returns a newly allocated GeomBinAttribute just like
//               this one.
////////////////////////////////////////////////////////////////////
NodeAttribute *GeomBinAttribute::
make_copy() const {
  return new GeomBinAttribute(*this);
}

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::make_initial
//       Access: Public, Virtual
//  Description: Returns a newly allocated GeomBinAttribute
//               corresponding to the default initial state.
////////////////////////////////////////////////////////////////////
NodeAttribute *GeomBinAttribute::
make_initial() const {
  return new GeomBinAttribute;
}

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::set_value_from
//       Access: Protected, Virtual
//  Description: Copies the value from the indicated transition
//               pointer, which is guaranteed to be of type
//               GeomBinTransition.
////////////////////////////////////////////////////////////////////
void GeomBinAttribute::
set_value_from(const OnOffTransition *other) {
  const GeomBinTransition *ot;
  DCAST_INTO_V(ot, other);
  _value = ot->_value;
  _draw_order = ot->_draw_order;
  nassertv(_value != (GeomBin *)NULL);
}

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::compare_values
//       Access: Protected, Virtual
//  Description: 
////////////////////////////////////////////////////////////////////
int GeomBinAttribute::
compare_values(const OnOffAttribute *other) const {
  const GeomBinAttribute *ot;
  DCAST_INTO_R(ot, other, false);
  if (_value != ot->_value) {
    return (int)(_value - ot->_value);
  }
  return _draw_order - ot->_draw_order;
}

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::output_value
//       Access: Protected, Virtual
//  Description: Formats the value for human consumption on one line.
////////////////////////////////////////////////////////////////////
void GeomBinAttribute::
output_value(ostream &out) const {
  nassertv(_value != (GeomBin *)NULL);
  out << *_value << ":" << _draw_order;
}

////////////////////////////////////////////////////////////////////
//     Function: GeomBinAttribute::write_value
//       Access: Protected, Virtual
//  Description: Formats the value for human consumption on multiple
//               lines if necessary.
////////////////////////////////////////////////////////////////////
void GeomBinAttribute::
write_value(ostream &out, int indent_level) const {
  nassertv(_value != (GeomBin *)NULL);
  indent(out, indent_level) << *_value << ":" << _draw_order << "\n";
}
