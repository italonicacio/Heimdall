#pragma once

#include "config.hpp"
#include "material.hpp"
#include "utils.hpp"

class Metal : public Material {
public:
	Metal(const Vec3& albedo, Scalar fuzz) : albedo{ albedo } {
		if(fuzz < 1)
			this->fuzz = fuzz;
		else
			this->fuzz = 1;
	}
	virtual bool Scatter(const Ray& incident_ray, const HitRecord& record, Vec3& attenuation, Ray& scattered) const override {
		Vec3 reflected = Utils::Math::Reflect(UnitVector(incident_ray.Direction()), record.normal);
		scattered = Ray(record.p, reflected + this->fuzz*Utils::Math::RandomInUnitSphere());
		attenuation = albedo;
		return (scattered.Direction().Dot(record.normal) > 0);
	}

	Vec3 albedo;
	Scalar fuzz;
};
