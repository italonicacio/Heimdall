#pragma once

#include "ray.hpp"
#include "hit-record.hpp"

class Hitable {
public:
	virtual bool Hit(const Ray& r, Scalar t_min, Scalar t_max, HitRecord& record) const = 0;
};
