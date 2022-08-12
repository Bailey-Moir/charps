#pragma once
#include <math.h>

using namespace std;

namespace Charps {
	template <typename T>
	class Vector3 {
	public:
		Vector3(T x, T y, T z);
		Vector3();

		T x = 0, y = 0, z = 0;

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