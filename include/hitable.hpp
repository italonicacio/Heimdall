#pragma once

#include "ray.hpp"

template<typename T>
struct HitRecord {
	T t;
	Vec3<T> p;
	Vec3<T> normal;
};

template<typename T>
class Hitable {
public:
	virtual bool Hit(const Ray<T>& r, T t_min, T t_max, HitRecord<T>& record) const = 0;
};