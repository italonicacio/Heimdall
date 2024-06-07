#pragma once

#include <memory>

#include "vec3.hpp"

class Material;


using MaterialPtr = std::shared_ptr<Material>;

struct HitRecord {
	Scalar t;
	Vec3 p;
	Vec3 normal;
	MaterialPtr material;
};
