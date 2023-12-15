#include <algorithm>

#include "utils.hpp"


namespace Utils
{
	std::string ToLower(std::string str) {
		std::transform(std::begin(str), std::end(str), std::begin(str),
			[](unsigned char c) { return std::tolower(c); });
		return str;
	}

	bool HasWhiteSpaces(const std::string& str) {
		return str.find(' ') != std::string::npos;
	}

	namespace Math {
		Vec3 RandomInUnitSphere() {
			Vec3 p;
			do {
				p = 2.0*Vec3({ Math::AutoRand(), Math::AutoRand(), Math::AutoRand() }) - Vec3({ 1.0, 1.0, 1.0 });
			} while(p.SquaredLength() >= 1.0);

			return p;
		}

		Scalar AutoRand() {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<Scalar> dist(0.0, 1.0);


			// return static_cast<Scalar>(drand48());
			return dist(gen);

		}

		float64_t Rand64() {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float32_t> dist(0.0, 1.0);

			return dist(gen);

			// return drand48();
		}

		float32_t Rand32() {
			return static_cast<float32_t>(Rand64());

			// return static_cast<float32_t>(drand48());
		}

		Vec3 Reflect(const Vec3& v, const Vec3& n) {
			return v - 2*v.Dot(n)*n;
		}

		bool Refract(const Vec3& v, const Vec3& n, Scalar ni_over_nt, Vec3& refracted) {
			Vec3 uv = UnitVector(v);
			Scalar dot = uv.Dot(n);
			Scalar discriminant = 1.0 - ni_over_nt*ni_over_nt*(1.0-dot*dot);
			if(discriminant > 0.0) {
				refracted = ni_over_nt*(uv - n*dot) - n*sqrt(discriminant);
				return true;
			}

			return false;
		}

	}

}
