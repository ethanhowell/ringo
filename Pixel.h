#pragma once

#include "vec3.h"

class Pixel {
public:
	int x, y;
	vec3 color;
	Pixel(int x, int y, vec3 color) : x(x), y(y), color(color) {}
};

