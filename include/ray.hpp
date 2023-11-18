#pragma once

#include "vec3.hpp"

template<typename T>
class Ray {
	static_assert(std::is_same<T, float32_t>::value || std::is_same<T, float64_t>::value,
		"Template argument must be float32_t or float64_t");
public:
	Ray() {}
	Ray(const Vec3<T>& a, const Vec3<T>& b) : A{ a }, B{ b } {}
	Vec3<T> Origin() const { return A; }
	Vec3<T> Direction() const { return B; }
	Vec3<T> PointAtParameter(T t) const { return A + t * B; }

	Vec3<T> A;
	Vec3<T> B;

};
