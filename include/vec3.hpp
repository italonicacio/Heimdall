#pragma once
#include "float-types.hpp"
#include "vec-template.hpp"

template <typename T>
class Vec3 : public Vec<T, 3> {
	static_assert(std::is_same<T, float32_t>::value || std::is_same<T, float64_t>::value,
		"Template argument must be float32_t or float64_t");
public:
	Vec3(std::array<T, 3> arr) : Vec<T, 3>{ arr } {}
	Vec3(const Vec<T, 3>& v) : Vec<T, 3>{ v } {}

	inline T x() const { return this->elements[0]; }
	inline T y() const { return this->elements[1]; }
	inline T z() const { return this->elements[2]; }

	inline T r() const { return this->elements[0]; }
	inline T g() const { return this->elements[1]; }
	inline T b() const { return this->elements[2]; }


	Vec<T, 3> Cross(const Vec<T, 3>& v) override {
		std::array<T, 3> cross = {
			this->elements[1] * v.elements[2] - this->elements[2] * v.elements[1],
			-(this->elements[0] * v.elements[2] - this->elements[2] * v.elements[0]),
			this->elements[0] * v.elements[1] - this->elements[1] * v.elements[0]
		};

		return Vec<T, 3>(cross);
	}
};

