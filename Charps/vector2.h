#pragma once
#include <math.h>
#include <iostream>

using namespace std;

namespace Charps {
	template <typename T>
	class Vector2 {
	public:
		Vector2(T x, T y);
		Vector2();

		T x = 0, y = 0;

		double length();
	};

	template<typename T>
	Vector2<T>::Vector2(T x, T y) {
		this->x = x;
		this->y = y;
	}


	template<typename T>
	Vector2<T>::Vector2() {
		this->x = 0;
		this->y = 0;
	}

	template<typename T>
	double Vector2<T>::length() {
		return sqrt(x * x + y * y);
	};
}