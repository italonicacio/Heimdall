#pragma once

#include "hitable.hpp"

template<typename T>
class Sphere : public Hitable<T> {
public:
	Sphere() {}
	Sphere(Vec3<T> center, T radius) : center{ center }, radius{ radius } {}
	virtual bool Hit(const Ray<T>& r, T t_min, T t_max, HitRecord<T>& record) const override;
	Vec3<T> center;
	T radius;
};

template<typename T>
bool Sphere<T>::Hit(const Ray<T>& r, T t_min, T t_max, HitRecord<T>& record) const {
	Vec3 oc = r.Origin() - this->center;
	T a = r.Direction().Dot(r.Direction());
	T b = oc.Dot(r.Direction());
	T c = oc.Dot(oc) - this->radius * this->radius;
	T discrimant = b * b - a * c;
	if(discrimant <= 0) {
		return false;
	}

	T temp = (-b - sqrt(discrimant)) / a;
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
}
