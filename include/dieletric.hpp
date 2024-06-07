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
		Scalar reflect_prob;
		Scalar cosine;
		if(incident_ray.Direction().Dot(record.normal) > 0.0) {
			outward_normal = -record.normal;
			ni_over_nt = ref_idx;
			cosine = ref_idx * incident_ray.Direction().Dot(record.normal) / incident_ray.Direction().Length();
		} else {
			outward_normal = record.normal;
			ni_over_nt = 1.0 / ref_idx;
			cosine = -incident_ray.Direction().Dot(record.normal) / incident_ray.Direction().Length();
		}

		if(Utils::Math::Refract(incident_ray.Direction(), outward_normal, ni_over_nt, refracted)) {
			reflect_prob = Utils::Math::Schlick(cosine, ref_idx);
		} else {
			scattered = Ray(record.p, reflected);
			reflect_prob = 1.0;
		}

		if(Utils::Math::AutoRand() < reflect_prob) {
			scattered = Ray(record.p, reflected);
		} else {
			scattered = Ray(record.p, refracted);
		}

		return true;
	}

	Scalar ref_idx;
};
