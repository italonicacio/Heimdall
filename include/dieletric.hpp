#pragma once

#include "material.hpp"
#include "utils.hpp"

class Dieletric : public Material {
public:
	Dieletric(Scalar ri) : ref_idx(ri) {}
	virtual bool Scatter(const Ray& incident_ray, const HitRecord& record, Vec3& attenuation, Ray& scattered) const {
		Vec3 outward_normal;
		Vec3 reflected = Utils::Math::Reflect(incident_ray.Direction(), record.normal);

		Scalar ni_over_nt;
		attenuation = Vec3({ 1.0, 1.0, 1.0 });
		Vec3 refracted;
		if(incident_ray.Direction().Dot(record.normal) > 0.0) {
			outward_normal = -record.normal;
			ni_over_nt = ref_idx;
		} else {
			outward_normal = record.normal;
			ni_over_nt = 1.0 / ref_idx;
		}

		if(Utils::Math::Refract(incident_ray.Direction(), outward_normal, ni_over_nt, refracted)) {
			scattered = Ray(record.p, refracted);
		} else {
			scattered = Ray(record.p, reflected);
			return false;
		}

		return true;



	}

	Scalar ref_idx;
};
