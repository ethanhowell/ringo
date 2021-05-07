#pragma once

#include <vector>

#include "ILight.h"
#include "Triangle.h"
#include "vec3.h"

struct Intersection {
	double time;
	Triangle shape;
};

class Ray {
	vec3 start, direction;

public:
	Ray(vec3 start, vec3 direction);

	vec3 at(double time);
	Intersection closest_intersection(const std::vector<Triangle>& objects);
	bool intersects_object(const std::vector<Triangle>& objects);
	vec3 get_color(const std::vector<Triangle*>& objects, const std::vector<ILight*>& lights);
};

