#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	void Size() override {
		// 面積計算
		size = (upper + bottom) * height / 2.0f;
	}

	void Draw() override {
		Size();
		printf("面積 : %3.2f\n", size);
	}

private:
	float size;
	float height = 3.0f;
	float upper = 2.0f;
	float bottom = 4.0f;
};