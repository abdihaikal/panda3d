// Filename: intDataAttribute.cxx
// Created by:  drose (27Mar00)
// 
////////////////////////////////////////////////////////////////////

#include "intDataAttribute.h"
#include "intDataTransition.h"

// Tell GCC that we'll take care of the instantiation explicitly here.
#ifdef __GNUC__
#pragma implementation
#endif

TypeHandle IntDataAttribute::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: IntDataAttribute::make_copy
//       Access: Public, Virtual
//  Description: 
////////////////////////////////////////////////////////////////////
NodeAttribute *IntDataAttribute::
make_copy() const {
  return new IntDataAttribute(*this);
}

////////////////////////////////////////////////////////////////////
//     Function: IntDataAttribute::make_initial
//       Access: Public, Virtual
//  Description: 
////////////////////////////////////////////////////////////////////
NodeAttribute *IntDataAttribute::
make_initial() const {
  return new IntDataAttribute;
}
