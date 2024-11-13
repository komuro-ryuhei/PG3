#pragma once
#include "IShape.h"
#include <stdio.h>
#define _USE_MATH_DEFINS
#include <math.h>
#include <cmath>
#include <numbers>

class Circle : public IShape {
public:

	void Size() override {
		// 面積計算
		size = radius * radius * std::numbers::pi_v<float>;
	}

	void Draw() override {
		Size();
		// 面積描画
		printf("面積 : %3.2f\n", size);
	}

private:

	float size;
	float radius = 2.0f;
};