#pragma once

#include <string>
#include <random>

#include "vec3.hpp"
#include "config.hpp"

namespace Utils
{
	std::string ToLower(std::string str);
	bool HasWhiteSpaces(const std::string& str);

	namespace Math {
		Vec3 RandomInUnitSphere();

		Scalar AutoRand();
		float64_t Rand64();
		float32_t Rand32();
		Vec3 Reflect(const Vec3& v, const Vec3& n);
		bool Refract(const Vec3& v, const Vec3& n, Scalar ni_over_nt, Vec3& refracted);
		// Switch the ni_over_nt name for other name with more context

	}
}
