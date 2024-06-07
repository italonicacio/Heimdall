#pragma once

#include "config.hpp"
#include "vec3.hpp"

class Ray {

public:
	Ray() {}
	Ray(const Vec3& a, const Vec3& b) : A{ a }, B{ b } {}
	Vec3 Origin() const { return A; }
	Vec3 Direction() const { return B; }
	Vec3 PointAtParameter(Scalar t) const { return A + t*B; }

	Vec3 A;
	Vec3 B;
};
