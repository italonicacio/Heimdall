#pragma once

#include "ray.hpp"

template<typename T>
class Camera {
	static_assert(std::is_same<T, float32_t>::value || std::is_same<T, float64_t>::value,
		"Template argument must be float32_t or float64_t");
public:
	Camera(const Vec3<T>& look_from, const Vec3<T>& look_at, const Vec3<T> view_up, T vertical_field_of_view, T aspect) {
		Vec3<T> u, v, w;
		T theta = vfov * M_PI/180;
		T half_height = std::tan(theta/2);
		T half_width = aspect * half_height;
		this->origin = look_from;
		this->w = UnitVector(look_from - look_at);
		this->u = UnitVector(view_up.Cross(this->w));
		this->v = this->w.Cross(this->u);

		this->lower_left_corner = Vec3<T>(-half_width, -half_height, -1.0);
		this->lower_left_corner = origin - half_width*u - half_height*v - w;
		this->horizontal = 2.0*half_width*u;
		this->vertical = 2*half_height*v;

	}

	Ray<T> GetRay(T s, T t) {
		return Ray<T>(this->origin, this->lower_left_corner + s*this->horizontal + t*this->vertical - origin);
	}

	Vec3<T> origin;
	Vec3<T> lower_left_corner;
	Vec3<T> horizontal;
	Vec3<T> vertical;

};

