// Filename: textureTransition.cxx
// Created by:  drose (06Feb99)
// 
////////////////////////////////////////////////////////////////////

#include "config_sgattrib.h"

#include "textureTransition.h"
#include "textureAttribute.h"

#include <indent.h>
#include <datagram.h>
#include <datagramIterator.h>
#include <bamReader.h>
#include <bamWriter.h>

TypeHandle TextureTransition::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::make_copy
//       Access: Public, Virtual
//  Description: Returns a newly allocated TextureTransition just like
//               this one.
////////////////////////////////////////////////////////////////////
NodeTransition *TextureTransition::
make_copy() const {
  return new TextureTransition(*this);
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::make_attrib
//       Access: Public, Virtual
//  Description: Returns a newly allocated TextureAttribute.
////////////////////////////////////////////////////////////////////
NodeAttribute *TextureTransition::
make_attrib() const {
  return new TextureAttribute;
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::set_value_from
//       Access: Protected, Virtual
//  Description: Copies the value from the other transition pointer,
//               which is guaranteed to be another TextureTransition.
////////////////////////////////////////////////////////////////////
void TextureTransition::
set_value_from(const OnOffTransition *other) {
  const TextureTransition *ot;
  DCAST_INTO_V(ot, other);
  _value = ot->_value;
  nassertv(_value != (Texture *)NULL);
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::compare_values
//       Access: Protected, Virtual
//  Description: 
////////////////////////////////////////////////////////////////////
int TextureTransition::
compare_values(const OnOffTransition *other) const {
  const TextureTransition *ot;
  DCAST_INTO_R(ot, other, false);
  return (int)(_value - ot->_value);
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::output_value
//       Access: Protected, Virtual
//  Description: Formats the value for human consumption on one line.
////////////////////////////////////////////////////////////////////
void TextureTransition::
output_value(ostream &out) const {
  nassertv(_value != (Texture *)NULL);
  out << *_value;
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::write_value
//       Access: Protected, Virtual
//  Description: Formats the value for human consumption on multiple
//               lines if necessary.
////////////////////////////////////////////////////////////////////
void TextureTransition::
write_value(ostream &out, int indent_level) const {
  nassertv(_value != (Texture *)NULL);
  indent(out, indent_level) << *_value << "\n";
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::write_datagram
//       Access: Public
//  Description: Function to write the important information in
//               the particular object to a Datagram
////////////////////////////////////////////////////////////////////
void TextureTransition::
write_datagram(BamWriter *manager, Datagram &me)
{
  OnOffTransition::write_datagram(manager, me);
  manager->write_pointer(me, _value);
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::fillin
//       Access: Protected
//  Description: Function that reads out of the datagram (or asks
//               manager to read) all of the data that is needed to
//               re-create this object and stores it in the appropiate
//               place
////////////////////////////////////////////////////////////////////
void TextureTransition::
fillin(DatagramIterator& scan, BamReader* manager)
{
  OnOffTransition::fillin(scan, manager);
  manager->read_pointer(scan, this);
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::complete_pointers
//       Access: Public
//  Description: Takes in a vector of pointes to TypedWriteable
//               objects that correspond to all the requests for 
//               pointers that this object made to BamReader.
////////////////////////////////////////////////////////////////////
int TextureTransition::
complete_pointers(vector_typedWriteable &plist, BamReader*)
{
  if(plist[0] == TypedWriteable::Null)
  {
    if (sgattrib_cat->is_debug()) {
      sgattrib_cat->debug()
	<< get_type().get_name() << " received null Texture," 
	<< " turning off" << endl;
    }
    _value = (Texture *)NULL;
    set_off();
  }
  else
  {
    _value = DCAST(Texture, plist[0]);
  }

  return 1;
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::make_TextureTransition
//       Access: Protected
//  Description: Factory method to generate a TextureTransition object
////////////////////////////////////////////////////////////////////
TypedWriteable* TextureTransition::
make_TextureTransition(const FactoryParams &params)
{
  TextureTransition *me = new TextureTransition;
  BamReader *manager;
  Datagram packet;

  parse_params(params, manager, packet);
  DatagramIterator scan(packet);

  me->fillin(scan, manager);
  return me;
}

////////////////////////////////////////////////////////////////////
//     Function: TextureTransition::register_with_factory
//       Access: Public, Static
//  Description: Factory method to generate a TextureTransition object
////////////////////////////////////////////////////////////////////
void TextureTransition::
register_with_read_factory(void)
{
  BamReader::get_factory()->register_factory(get_class_type(), make_TextureTransition);
}
