#include "Vec3.hpp"

Vec3f32::Vec3f32(std::array<float32_t, 3> arr) : Vec<float32_t, 3>{ arr } {}

inline Vec<float32_t, 3> Vec3f32::Cross(const Vec<float32_t, 3>& v) {
	std::array<float32_t, 3> cross = {
		this->elements[1] * v.elements[2] - this->elements[2] * v.elements[1],
		-(this->elements[0] * v.elements[2] - this->elements[2] * v.elements[0]),
		this->elements[0] * v.elements[1] - this->elements[1] * v.elements[0]
	};

	return Vec<float32_t, 3>(cross);
}

Vec3f64::Vec3f64(std::array<float64_t, 3> arr) : Vec<float64_t, 3>{ arr } {}

inline Vec<float64_t, 3> Vec3f64::Cross(const Vec<float64_t, 3>& v) {
	std::array<float64_t, 3> cross = {
		this->elements[1] * v.elements[2] - this->elements[2] * v.elements[1],
		-(this->elements[0] * v.elements[2] - this->elements[2] * v.elements[0]),
		this->elements[0] * v.elements[1] - this->elements[1] * v.elements[0]
	};

	return Vec<float64_t, 3>(cross);
}
