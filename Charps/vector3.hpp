#pragma once
#include <math.h>

namespace Charps {
	/**
	 * A vector (in a mathematical and physical sense) with 3 dimensions.
	 */
	template <typename T>
	struct Vector3 {
		/**
		 * Main constructor.
		 * @param x The initial value of the first dimension.
		 * @param y The initial value of the second dimension.
		 * @param y The initial value of the third dimension.
		 */
		Vector3(const T& x, const T& y, const T& z);
		/**
		 * Constructor where dimensions are all equal to the one input.
		 * @param n The initial value of the dimensions.
		 */
		Vector3(const T& n);
		/**
		 * Default constructor;
		 */
		Vector3();

		/**
		 * One of the three dimensions.
		 */
		T x = 0, y = 0, z = 0;

		/**
		 * Gets the total lenght of the vector using pythagoras.
		 */
		double length();
		
		template<typename N>
		Vector3<N> cast();

		// OPERATORS

		Vector3 operator+(const Vector3<T>&);
		template<typename N>
		void operator+=(const Vector3<N>&);
		Vector3 operator-(const Vector3<T>&);
		template<typename N>
		void operator-=(const Vector3<N>&);
		template<typename N>
		void operator=(const Vector3<N>&);
	};

	template<typename T>
	Vector3<T>::Vector3(const T& x, const T& y, const T& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<typename T>
	Vector3<T>::Vector3(const T& n) {
		this->x = n;
		this->y = n;
		this->z = n;
	}

	template<typename T>
	Vector3<T>::Vector3() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	template<typename T>
	double Vector3<T>::length() {
		return sqrt(x * x + y * y + z * z);
	};

	template<typename T> template<typename N>
	Vector3<N> Vector3<T>::cast() {
		return Vector3<N>((N) this->x, (N) this->y, (N) this->z);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator+(const Vector3<T>& _) {
		return Vector3<T>(this->x + _.x, this->y + _.y, this->z + _.z);
	}
	template<typename T> template<typename N>
	void Vector3<T>::operator+=(const Vector3<N>& _) {
		this->x += (T) _.x;
		this->y += (T) _.y;
		this->z += (T) _.z;
	}
	template<typename T>
	Vector3<T> Vector3<T>::operator-(const Vector3<T>& _) {
		return Vector3<T>(this->x - _.x, this->y - _.y, this->z - _.z);
	}
	template<typename T> template<typename N>
	void Vector3<T>::operator-=(const Vector3<N>& _) {
		this->x -= (T) _.x;
		this->y -= (T) _.y;
		this->z -= (T) _.z;
	}
	template<typename T> template<typename N>
	void Vector3<T>::operator=(const Vector3<N>& _) {
		this->x = (T) _.x;
		this->y = (T) _.y;
		this->z = (T) _.z;
	}
}