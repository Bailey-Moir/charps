#pragma once
#include <math.h>
#include <iostream>

using namespace std;

namespace Charps {
	/**
	 * A vector (in a mathematical and physical sense) with 2 dimensions.
	 */
	template <typename T>
	struct Vector2 {
		/**
		 * Main constructor.
		 * @param x The initial value of the first dimension.
		 * @param y The initial value of the second dimension.
		 */
		Vector2(const T& x, const T& y);
		/**
		 * Constructor where dimensions are all equal to the one input.
		 * @param n The initial value of the dimensions.
		 */
		Vector2(const T& n);
		/**
		 * Default constructor;
		 */
		Vector2();

		/**
		 * One of the two dimensions.
		 */
		T x = 0, y = 0;

		/**
		 * Gets the total lenght of the vector using pythagoras.
		 */
		double length() const;

		/**
		 * Casts the vector2 to another type of vector2.
		 */
		template<typename N>
		Vector2<N> cast() const;

		/**
		 * Converts each dimension to its absolute value.
		 */
		Vector2<T> absVals() const;

		// OPERATORS

		template<typename N>
		Vector2<T> operator+(const Vector2<N>&) const;
		template<typename N>
		Vector2<T> operator+(N n) const;
		template<typename N>
		void operator+=(const Vector2<N>&);

		template<typename N>
		Vector2<T> operator-(const Vector2<N>&) const;
		template<typename N>
		Vector2<T> operator-(N n) const;
		template<typename N>
		void operator-=(const Vector2<N>&);

		template<typename N>
		Vector2<T> operator*(const Vector2<N>&) const;
		template<typename N>
		Vector2<T> operator*(N n) const;
		template<typename N>
		void operator*=(const Vector2<N>&);

		template<typename N>
		Vector2<T> operator/(const Vector2<N>&) const;
		template<typename N>
		Vector2<T> operator/(N n) const;
		template<typename N>
		void operator/=(const Vector2<N>&);

		template<typename N>
		void operator=(const Vector2<N>&);
	};

	template<typename T>
	Vector2<T>::Vector2(const T& x, const T& y) {
		this->x = x;
		this->y = y;
	}

	template<typename T>
	Vector2<T>::Vector2(const T& n) {
		this->x = n;
		this->y = n;
	}

	template<typename T>
	Vector2<T>::Vector2() {
		this->x = 0;
		this->y = 0;
	}

	template<typename T>
	double Vector2<T>::length() const {
		return sqrt(x * x + y * y);
	}
	template<typename T>
	Vector2<T> Vector2<T>::absVals() const {
		return Vector2<T>(abs(x), abs(y));
	}

	template<typename T> template<typename N>
	Vector2<N> Vector2<T>::cast() const {
		return Vector2<N>((N)this->x, (N)this->y);
	}

	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator+(const Vector2<N>& _) const {
		return Vector2<T>(this->x + _.x, this->y + _.y);
	}
	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator+(N n) const {
		return Vector2<T>(this->x + n, this->y + n);
	}
	template<typename T> template<typename N>
	void Vector2<T>::operator+=(const Vector2<N>& _) {
		this->x += (T)_.x;
		this->y += (T)_.y;
	}

	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator-(const Vector2<N>& _) const {
		return Vector2<T>(this->x - _.x, this->y - _.y);
	}
	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator-(N n) const {
		return Vector2<T>(this->x - n, this->y - n);
	}
	template<typename T> template<typename N>
	void Vector2<T>::operator-=(const Vector2<N>& _) {
		this->x -= (T)_.x;
		this->y -= (T)_.y;
	}

	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator*(const Vector2<N>& _) const {
		return Vector2<T>(this->x * _.x, this->y * _.y);
	}
	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator*(N n) const {
		return Vector2<T>(this->x * n, this->y * n);
	}
	template<typename T> template<typename N>
	void Vector2<T>::operator*=(const Vector2<N>& _) {
		this->x *= (T)_.x;
		this->y *= (T)_.y;
	}

	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator/(const Vector2<N>& _) const {
		return Vector2<T>(this->x / _.x, this->y / _.y);
	}
	template<typename T> template<typename N>
	Vector2<T> Vector2<T>::operator/(N n) const {
		return Vector2<T>(this->x / n, this->y / n);
	}
	template<typename T> template<typename N>
	void Vector2<T>::operator/=(const Vector2<N>& _) {
		this->x /= (T)_.x;
		this->y /= (T)_.y;
	}

	template<typename T> template<typename N>
	void Vector2<T>::operator=(const Vector2<N>& _) {
		this->x = (T)_.x;
		this->y = (T)_.y;
	}
}