#pragma once

#include "ray.hpp"

class Camera {
public:
	Camera(Vec3& look_from, Vec3& look_at, Vec3 view_up, Scalar vertical_field_of_view, Scalar aspect) {
		Vec3 u, v, w;
		Scalar theta = vertical_field_of_view * M_PI/180;
		Scalar half_height = std::tan(theta/2);
		Scalar half_width = aspect * half_height;
		this->origin = look_from;
		w = UnitVector(look_from - look_at);
		u = UnitVector(view_up.Cross(w));
		v = w.Cross(u);

		this->lower_left_corner = Vec3({ -half_width, -half_height, -1.0 });
		this->lower_left_corner = origin - half_width*u - half_height*v - w;
		this->horizontal = 2.0*half_width*u;
		this->vertical = 2*half_height*v;

	}

	Ray GetRay(Scalar s, Scalar t) {
		return Ray(this->origin, this->lower_left_corner + s*this->horizontal + t*this->vertical - origin);
	}

	Vec3 origin;
	Vec3 lower_left_corner;
	Vec3 horizontal;
	Vec3 vertical;

};

