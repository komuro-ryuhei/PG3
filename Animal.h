#pragma once
#include <stdio.h>

// 基底クラス
struct Animal {

public:
	virtual void Voice() {
		// 鳴き声
		printf("鳴き声");
	}
};