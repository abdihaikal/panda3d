// Filename: config_util.cxx
// Created by:  cary (04Jan00)
// 
////////////////////////////////////////////////////////////////////

#include "config_util.h"
#include "clockObject.h"
#include "typeHandle.h"
#include "configurable.h"
#include "namable.h"
#include "referenceCount.h"
#include "typedReferenceCount.h"
#include "keyboardButton.h"
#include "mouseButton.h"
#include "factoryParam.h"
#include "datagram.h"
#include "writeable.h"
#include "typedWriteable.h"
#include "typedWriteableReferenceCount.h"
#include "writeableParam.h"
#include "bamReaderParam.h"
#include "writeableConfigurable.h"
#include "get_config_path.h"

#include <dconfig.h>

ConfigureDef(config_util);
NotifyCategoryDef(util, "");

ConfigureFn(config_util) {
//  ClockObject::init_ptr();
  TypedObject::init_type();
  Configurable::init_type();
  Namable::init_type();
  ReferenceCount::init_type();
  TypedReferenceCount::init_type();
  KeyboardButton::init_keyboard_buttons();
  MouseButton::init_mouse_buttons();
  FactoryParam::init_type();
  Datagram::init_type();
  Writeable::init_type();
  TypedWriteable::init_type();
  WriteableParam::init_type();
  BamReaderParam::init_type();
  TypedWriteableReferenceCount::init_type();
  WriteableConfigurable::init_type();
}


// Set this true to enable tracking of ReferenceCount pointer
// allocation/deallcation via the MemoryUsage object.  This is
// primarily useful for detecting memory leaks.  It has no effect when
// compiling in NDEBUG mode.

// This variable is no longer defined here; instead, it's a member of
// MemoryUsage.

//const bool track_memory_usage = config_util.GetBool("track-memory-usage", false);

const DSearchPath &
get_model_path() {
  static DSearchPath *model_path = NULL;
  return get_config_path("model-path", model_path);
}

const DSearchPath &
get_texture_path() {
  static DSearchPath *texture_path = NULL;
  return get_config_path("texture-path", texture_path);
}

const DSearchPath &
get_sound_path() {
  static DSearchPath *sound_path = NULL;
  return get_config_path("sound-path", sound_path);
}
