// Filename: buttonEvent.cxx
// Created by:  drose (01Mar00)
// 
////////////////////////////////////////////////////////////////////

#include "buttonEvent.h"

////////////////////////////////////////////////////////////////////
//     Function: ButtonEvent::output
//       Access: Public
//  Description: 
////////////////////////////////////////////////////////////////////
void ButtonEvent::
output(ostream &out) const {
  out << "button " << _button;
  if (_down) {
    out << " down";
  } else {
    out << " up";
  }
  out << " with " << _mods;
}
