#pragma once
#include <stdio.h>

template<typename T>

class AddClass {

public:
	T Add(T a, T b) {
		T c = a + b;
		return c;
	};
};