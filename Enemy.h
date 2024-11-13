#pragma once

class Enemy {

public:

	// 行動フェーズ
	enum class Phase {
		Approach, // 接近
		Attck,    // 攻撃
		Leave,    // 離脱
	};

	// 更新
	void Update();

	// 関数
	void Approacth();

	void Attack();

	void Leave();


private:

	static void (Enemy::*FuncTable[])();

	// メンバ関数ポインタ
	void (Enemy::*AppFunc)();
	void (Enemy::*AttackFunc)();
	void (Enemy::*LeaveFunc)();

	Phase phase_ = Phase::Approach;
};