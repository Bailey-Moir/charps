#pragma once
#include <math.h>

namespace Charps {
	/**
	 * A vector (in a mathematical and physical sense) with 3 dimensions.
	 */
	template <typename T>
	class Vector3 {
	public:
		/**
		 * Main constructor.
		 * @param x The initial value of the first dimension.
		 * @param y The initial value of the second dimension.
		 * @param y The initial value of the third dimension.
		 */
		Vector3(T x, T y, T z);
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
	};

	template<typename T>
	Vector3<T>::Vector3(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
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
}