#pragma once

#include "config.hpp"
#include "float-types.hpp"
#include "vec-template.hpp"


class Vec3 : public Vec<Scalar, 3> {

public:
	Vec3() {}
	Vec3(std::array<Scalar, 3> arr) : Vec<Scalar, 3>{ arr } {}
	Vec3(const Vec<Scalar, 3>& v) : Vec<Scalar, 3>{ v } {}

	inline Scalar x() const { return this->elements[0]; }
	inline Scalar y() const { return this->elements[1]; }
	inline Scalar z() const { return this->elements[2]; }

	inline Scalar r() const { return this->elements[0]; }
	inline Scalar g() const { return this->elements[1]; }
	inline Scalar b() const { return this->elements[2]; }


	Vec<Scalar, 3> Cross(const Vec<Scalar, 3>& v) override {
		std::array<Scalar, 3> cross = {
			this->elements[1] * v.elements[2] - this->elements[2] * v.elements[1],
			-(this->elements[0] * v.elements[2] - this->elements[2] * v.elements[0]),
			this->elements[0] * v.elements[1] - this->elements[1] * v.elements[0]
		};

		return Vec<Scalar, 3>(cross);
	}
};

