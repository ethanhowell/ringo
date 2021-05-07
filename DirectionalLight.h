#pragma once

#include "ILight.h"

class DirectionalLight: public ILight {
private:
	vec3 direction;

public:
	DirectionalLight(const vec3& direction, const vec3& color) : ILight(color), direction(direction) {}

	const vec3 direction_to_light(const vec3& start) const override { return direction; }
};

