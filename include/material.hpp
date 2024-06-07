#pragma once

#include "ray.hpp"
#include "hit-record.hpp"


class Material {
public:
	virtual bool Scatter(const Ray& incident_ray, const HitRecord& record, Vec3& attenuation, Ray& scattered) const = 0;
};
