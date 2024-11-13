#include "Enemy.h"
#include <stdio.h>

void Enemy::Update() {

	// 現在のフェーズに対応する関数を呼び出す
	(this->*FuncTable[static_cast<size_t>(phase_)])();
}

void (Enemy::*Enemy::FuncTable[])() = {&Enemy::Approacth, &Enemy::Attack, &Enemy::Leave};

void Enemy::Approacth() {

	// 接近と表示
	printf("接近\n");
	phase_ = Phase::Attck;
}

void Enemy::Attack() {

	// 攻撃と表示
	printf("攻撃\n");
	phase_ = Phase::Leave;
}

void Enemy::Leave() {

	// 離脱と表示
	printf("離脱\n");
}