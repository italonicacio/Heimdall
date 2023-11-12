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
		T dot = 0;
		for(std::size_t i = 0; i < N; ++i) {
			dot += elements[i] * v.elements[i];
		}
		return dot;
	}

	template<typename U>
	Vec operator*(U scalar) const {
		std::array<T, N> result;
		std::transform(elements.begin(), elements.end(), result.begin(), [scalar](const T& c) {return scalar * c;});
		return Vec(result);
	}

	// Testar daqui pra baixo
	Vec operator-() const {
		std::array<T, N> result;
		std::transform(elements.begin(), elements.end(), result.begin(), [](const T& c) {return -c;});
		return Vec(result);
	}

	Vec& operator+=(const Vec& v) {
		for(std::size_t i = 0; i < N; ++i) {
			this->elements[i] += v.elements[i];
		}
		return *this;
	}

	Vec& operator-=(const Vec& v) {
		for(std::size_t i = 0; i < N; ++i) {
			this->elements[i] -= v.elements[i];
		}
		return *this;
	}

	template<typename U>
	Vec& operator*=(U scalar) {
		std::transform(elements.begin(), elements.end(), elements.begin(), [scalar](const T& c) {return scalar * c;});
		return *this;
	}
};
