#include <array>
#include <algorithm>

template<typename T, std::size_t N>
class Vec {
public:
	std::array<T, N> elements;

	Vec() :elements{} {}
	Vec(const std::array<T, N>& elements) : elements(elements) {};

	Vec operator+(const Vec& v) const {
		std::array<T, N> result;
		for(std::size_t i = 0; i < N; ++i) {
			result[i] = elements[i] + v.elements[i];
		}
		return Vec(result);
	}

	Vec operator-(const Vec& v) const {
		std::array<T, N> result;
		for(std::size_t i = 0; i < N; ++i) {
			result[i] = elements[i] - v.elements[i];
		}
		return Vec(result);
	}

	T operator*(const Vec& v) const {

	}

	Vec operator*(T scalar) const {
		std::array<T, N> result;
		std::transform(elements.begin(), elements.end(), elements.begin(), [scalar](T& c) {return scalar * c;});
		return Vec(result);
	}
};
