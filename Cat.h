#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	void Voice() override {
		// 鳴き声
		printf("にゃー");
	}
};