#include <stdio.h>

#include "Enemy.h"

int main() {

	Enemy enemy;

	for (int i = 0; i < 3; i++) {
		// 現在の状態表示
		enemy.Update();
	}

	return 0;
}