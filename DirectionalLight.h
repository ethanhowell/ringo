#pragma once
#include "LightInterface.h"
class DirectionalLight: public LightInterface {
private:
	vec3 direction;

public:
	DirectionalLight(const vec3& direction, const vec3& color) : LightInterface(color), direction(direction) {}

	const vec3 direction_to_light(const vec3& start) { return direction; }
};

