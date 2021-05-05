#pragma once

#include "vec3.h"

class LightInterface {
private:
	vec3 color;
public:
	LightInterface(const vec3& color): color(color) {}

	const vec3& get_color() { return color; }
	virtual const vec3 get_direction(const vec3& start) = 0;
};

