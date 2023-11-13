#pragma once

#include <array>
#include <algorithm>
#include <cmath>

#include "exception/not-implemented-exception.hpp"

template<typename T, std::size_t N>
class Vec {
public:
	std::array<T, N> elements;

	Vec() :elements{} {}
	Vec(const std::array<T, N>& elements) : elements(elements) {};

	inline const Vec& operator+() const { return *this; }

	inline Vec operator-() const {
		std::array<T, N> result;
		std::transform(elements.begin(), elements.end(), result.begin(),
			[](const T& c) {return -c;});
		return Vec(result);
	}

	inline T operator[](std::size_t i) const {
		return this->elements.at(i);
	}

	inline T& operator[](std::size_t i) {
		return this->elements.at(i);
	}

	inline Vec& operator+=(const Vec& v) {
		std::transform(this->elements.begin(), this->elements.end(), v.elements.begin(), this->elements.begin(),
			[](const T& a, const T& b) { return a + b; });
		return *this;
	}

	inline Vec& operator-=(const Vec& v) {
		std::transform(this->elements.begin(), this->elements.end(), v.elements.begin(), this->elements.begin(),
			[](const T& a, const T& b) { return a - b; });
		return *this;
	}

	inline Vec& operator*=(const Vec& v) {
		std::transform(this->elements.begin(), this->elements.end(), v.elements.begin(), this->elements.begin(),
			[](const T& a, const T& b) { return a * b; });
		return *this;
	}

	inline Vec& operator/=(const Vec& v) {
		std::transform(this->elements.begin(), this->elements.end(), v.elements.begin(), this->elements.begin(),
			[](const T& a, const T& b) { return a / b; });
		return *this;
	}

	template<typename U>
	inline Vec& operator*=(U scalar) {
		std::transform(this->elements.begin(), this->elements.end(), this->elements.begin(),
			[scalar](const T& c) { return scalar * c; });
		return *this;
	}

	template<typename U>
	inline Vec& operator/=(U scalar) {
		std::transform(this->elements.begin(), this->elements.end(), this->elements.begin(),
			[scalar](const T& c) {return scalar / c;});
		return *this;
	}

	inline Vec operator+(const Vec& v) const {
		std::array<T, N> result;
		for(std::size_t i = 0; i < N; ++i) {
			result[i] = elements[i] + v.elements[i];
		}
		return Vec(result);
	}

	inline Vec operator-(const Vec& v) const {
		std::array<T, N> result;
		for(std::size_t i = 0; i < N; ++i) {
			result[i] = elements[i] - v.elements[i];
		}
		return Vec(result);
	}

	// Hadamard
	inline T operator*(const Vec& v) const {
		std::array<T, N> result;
		for(std::size_t i = 0; i < N; ++i) {
			result[i] = elements[i] * v.elements[i];
		}
		return Vec(result);
	}

	// Hadamard
	inline T operator/(const Vec& v) const {
		std::array<T, N> result;
		for(std::size_t i = 0; i < N; ++i) {
			result[i] = elements[i] / v.elements[i];
		}
		return Vec(result);
	}

	template<typename U>
	inline Vec operator*(U scalar) const {
		std::array<T, N> result;
		std::transform(elements.begin(), elements.end(), result.begin(), [scalar](const T& c) {return scalar * c;});
		return Vec(result);
	}

	template<typename U>
	inline Vec operator/(U scalar) const {
		std::array<T, N> result;
		std::transform(elements.begin(), elements.end(), result.begin(), [scalar](const T& c) {return c / scalar;});
		return Vec(result);
	}

	inline T Dot(const Vec& v) const {
		T dot = 0;
		for(std::size_t i = 0; i < N; ++i) {
			dot += elements[i] * v.elements[i];
		}
		return dot;
	}

	virtual Vec Cross(Vec) {
		std::string function("Cross");
		throw NotImplementedException(function);
	};

	inline T Length() const {
		T length = 0;
		for(const T& element : this->elements) {
			length += element * element;
		}

		return std::sqrt(length);
	}

	inline T SquaredLength() const {

		T squared_length = 0;
		for(const T& element : this->elements) {
			squared_length += element * element;
		}

		return squared_length;
	}

	inline void MakeUnit() {
		float k = 1.0 / this->Length();
		std::transform(this->elements.begin(), this->elements.end(), this->elements.begin(),
			[k](const T& element) { return element * k; });

	}

};

template<typename T, std::size_t N>
inline Vec<T, N> UnitVector(const Vec<T, N>& v) {
	return v / v.Length();
}

