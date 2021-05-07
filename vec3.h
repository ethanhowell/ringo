#pragma once

#include <math.h>

class vec3 {
private:
	double x, y, z;

public:
	vec3(): x(0), y(0), z(0) {}

	vec3(double x, double y, double z): x(x), y(y), z(z) {}

	vec3(const vec3& other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}

	~vec3() {}

	vec3 cross(const vec3& other) const {
		vec3 result;
		result.x = y * other.z - z * other.y;
		result.y = -(x * other.z - z * other.x);
		result.z = x * other.y - y * other.x;
		return result;
	}

	double dot(const vec3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	vec3 operator+(const vec3& other) const {
		return vec3(x + other.x, y + other.y, z + other.z);
	}

	vec3 operator-() const {
		return vec3(-x, -y, -z);
	}

	vec3 operator-(const vec3& other) const {
		return vec3(other.x - x, other.y - y, other.z - z);
	}

	vec3 operator*(double scalar) const {
		return vec3(scalar * x, scalar * y, scalar * z);
	}

	vec3 operator/(double scalar) const {
		return (*this) * (1 / scalar);
	}

	double norm() const {
		return sqrt(x*x + y*y + z*z);
	}
};

