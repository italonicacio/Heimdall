#pragma once

#include "vec3.hpp"

template<typename T>
class Ray {
public:
	Ray() {}
	Ray(const Vec3<T>& a, const Vec3<T>& b) : A{ a }, B{ b } {}
	Vec3<T> Origin() const { return A; }
	Vec3<T> Direction() const { return B; }
	Vec3<T> PointAtParameter(T t) const { return A + t * B; }

	Vec3<T> A;
	Vec3<T> B;

};
