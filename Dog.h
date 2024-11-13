#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
	void Voice() override {
		// 鳴き声
		printf("ワン");
	}
};