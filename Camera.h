#pragma once

#include "vec3.h"

class Camera {
public:
	double get_fov() const; // in degrees
	vec3 get_u() const;
	vec3 get_v() const;
	vec3 get_n() const;
	vec3 get_look_from() const;
};

