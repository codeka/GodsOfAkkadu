#ifndef TERRAIN3D_H
#define TERRAIN3D_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/wrapped.hpp>

class Terrain3D : public godot::Node3D {
	GDCLASS(Terrain3D, Node3D);

public:
	Terrain3D();
	~Terrain3D();

protected:
	static void _bind_methods();
};

#endif  // TERRAIN3D_H
