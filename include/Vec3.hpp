#pragma once
#include "float-types.hpp"
#include "vec-template.hpp"

class Vec3f32 : Vec<float32_t, 3> {
	virtual Vec3f32 Cross() override {
		std::string function("Cross");
		throw NotImplementedException(function);
	};
};

