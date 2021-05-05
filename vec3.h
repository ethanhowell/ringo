#pragma once
struct vec3 {
	double x, y, z;

	vec3(): x(0), y(0), z(0) {}

	vec3(const vec3& other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}
};

