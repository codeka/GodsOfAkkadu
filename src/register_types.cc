
#include "register_types.h"
#include "terrain/terrain3d.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel level) {
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Terrain3D>();
}

void uninitialize_gdextension_types(ModuleInitializationLevel level) {
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
	// Initialization
	GDExtensionBool GDE_EXPORT example_library_init(
			GDExtensionInterfaceGetProcAddress get_proc_address,
			GDExtensionClassLibraryPtr library,
			GDExtensionInitialization *initialization)	{
		GDExtensionBinding::InitObject init_obj(get_proc_address, library, initialization);
		init_obj.register_initializer(initialize_gdextension_types);
		init_obj.register_terminator(uninitialize_gdextension_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
