#pragma once

#include "vec3.h"

class ILight {
private:
	vec3 color;
public:
	ILight(const vec3& color): color(color) {}

	const vec3& get_color() const { return color; }
	virtual const vec3 direction_to_light(const vec3& start) const = 0;
};

