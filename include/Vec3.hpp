#pragma once
#include "float-types.hpp"
#include "vec-template.hpp"


class Vec3f32 : public Vec<float32_t, 3> {
public:
	Vec3f32(std::array<float32_t, 3> arr);
	Vec3f32(const Vec<float32_t, 3>& v) : Vec<float32_t, 3>{ v } {}
	Vec<float32_t, 3> Cross(const Vec<float32_t, 3>& v) override;
};

class Vec3f64 : public Vec<float64_t, 3> {
public:
	Vec3f64(std::array<float64_t, 3> arr);
	Vec3f64(const Vec<float64_t, 3>& v) : Vec<float64_t, 3>{ v } {}
	Vec<float64_t, 3> Cross(const Vec<float64_t, 3>& v) override;
};

