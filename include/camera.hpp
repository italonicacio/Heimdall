#pragma once

#include "ray.hpp"
#include "utils.hpp"

Vec3 RandomInUnitDisk() {
	Vec3 p;
	do {
		Scalar x = Utils::Math::AutoRand();
		Scalar y = Utils::Math::AutoRand();

		p = 2.0 * Vec3({ x, y, 0.0 }) - Vec3({ 1.0, 1.0, 0.0 });

	} while(p.Dot(p) >= 1.0);

	return p;
}

class Camera {
public:
	Camera(Vec3& look_from, Vec3& look_at, Vec3 view_up, Scalar vertical_field_of_view, Scalar aspect, Scalar focus_dist) {
		Vec3 u, v, w;
		Scalar theta = vertical_field_of_view * M_PI/180.0;
		Scalar half_height = std::tan(theta/2);
		Scalar half_width = aspect * half_height;
		this->origin = look_from;
		w = UnitVector(look_from - look_at);
		u = UnitVector(view_up.Cross(w));
		v = w.Cross(u);

		this->lower_left_corner = origin - half_width*focus_dist*u - half_height*focus_dist*v - focus_dist*w;
		this->horizontal = 2.0*half_width*focus_dist*u;
		this->vertical = 2*half_height*focus_dist*v;

	}

	Ray GetRay(Scalar s, Scalar t) {
		return Ray(this->origin, this->lower_left_corner + s*this->horizontal + t*this->vertical - origin);
	}

	Vec3 origin;
	Vec3 lower_left_corner;
	Vec3 horizontal;
	Vec3 vertical;

};

