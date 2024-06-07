#pragma once

#include "hitable.hpp"

class Sphere : public Hitable {
public:
	Sphere() {}
	Sphere(Vec3 center, Scalar radius) : center{ center }, radius{ radius } {}

	virtual bool Hit(const Ray& r, Scalar t_min, Scalar t_max, HitRecord& record) const override {
		Vec3 oc = r.Origin() - this->center;
		Scalar a = r.Direction().Dot(r.Direction());
		Scalar b = oc.Dot(r.Direction());
		Scalar c = oc.Dot(oc) - this->radius * this->radius;
		Scalar discrimant = b * b - a * c;
		if(discrimant <= 0.0) {
			return false;
		}

		Scalar temp = (-b - sqrt(discrimant)) / a;
		if(temp < t_max && temp > t_min) {
			record.t = temp;
			record.p = r.PointAtParameter(record.t);
			record.normal = (record.p - this->center) / this->radius;
			return true;
		}
		temp = (-b + sqrt(discrimant)) / a;
		if(temp < t_max && temp > t_min) {
			record.t = temp;
			record.p = r.PointAtParameter(record.t);
			record.normal = (record.p - this->center) / this->radius;
			return true;
		}

		return false;
	};

	Vec3 center;
	Scalar radius;
};


// bool Sphere::Hit(const Ray& r, Scalar t_min, Scalar t_max, HitRecord& record) const {
// 	Vec3 oc = r.Origin() - this->center;
// 	Scalar a = r.Direction().Dot(r.Direction());
// 	Scalar b = oc.Dot(r.Direction());
// 	Scalar c = oc.Dot(oc) - this->radius * this->radius;
// 	Scalar discrimant = b * b - a * c;
// 	if(discrimant <= 0) {
// 		return false;
// 	}

// 	Scalar temp = (-b - sqrt(discrimant)) / a;
// 	if(temp < t_max && temp > t_min) {
// 		record.t = temp;
// 		record.p = r.PointAtParameter(record.t);
// 		record.normal = (record.p - this->center) / this->radius;
// 		return true;
// 	}
// 	temp = (-b + sqrt(discrimant)) / a;
// 	if(temp < t_max && temp > t_min) {
// 		record.t = temp;
// 		record.p = r.PointAtParameter(record.t);
// 		record.normal = (record.p - this->center) / this->radius;
// 		return true;
// 	}

// 	return false;
// }
