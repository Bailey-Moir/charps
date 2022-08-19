#pragma once
#include <math.h>
#include <iostream>

namespace Charps {
	/**
	 * A vector (in a mathematical and physical sense) with 2 dimensions.
	 */
	template <typename T>
	class Vector2 {
	public:
		/**
		 * Main constructor.
		 * @param x The initial value of the first dimension.
		 * @param y The initial value of the second dimension.
		 */
		Vector2(T x, T y);
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
		double length();
	};

	template<typename T>
	Vector2<T>::Vector2(T x, T y) {
		this->x = x;
		this->y = y;
	}
	
	template<typename T>
	Vector2<T>::Vector2() {}

	template<typename T>
	double Vector2<T>::length() {
		return sqrt(x * x + y * y);
	};
}