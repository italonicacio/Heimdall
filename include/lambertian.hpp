#pragma once

#include "material.hpp"
#include "utils.hpp"

// using namespace Utils;

class Lambertian : public Material {
public:
	Lambertian(const Vec3& albedo) : albedo{ albedo } {}

	virtual bool Scatter(const Ray& incident_ray, const HitRecord& record, Vec3& attenuation, Ray& scattered) const override {
		Vec3 target = record.p + record.normal + Utils::Math::RandomInUnitSphere();
		scattered = Ray(record.p, target-record.p);
		attenuation = this->albedo;
		return true;
	}


	Vec3 albedo;
};
