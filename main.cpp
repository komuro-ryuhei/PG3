#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <thread>

// SetTimeout 関数
void SetTimeout(std::function<void()> func, int delay) {
	std::thread([func, delay]() {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		func();
	}).detach();
}

int main() {
	// 乱数のシードを初期化
	srand(static_cast<unsigned int>(time(0)));

	// サイコロを振るラムダ式
	auto rollDice = []() -> int { return rand() % 6 + 1; };

	// 偶数か奇数か判定するラムダ式
	std::function<bool(int)> isOdd = [](int number) { return number % 2 != 0; };

	// サイコロを振って結果を取得
	int diceRoll = rollDice();

	// ユーザーの入力を取得
	std::string userGuess;
	printf("奇数か偶数か当ててください (奇数: odd / 偶数: even): ");
	std::cin >> userGuess;

	// 3秒待機してから結果を表示
	SetTimeout(
	    [diceRoll, userGuess, isOdd]() {
		    bool correctGuess = (userGuess == "奇数" && isOdd(diceRoll)) || (userGuess == "偶数" && !isOdd(diceRoll));

		    if (correctGuess) {
			    printf("正解！サイコロの目は %d でした。", diceRoll);
		    } else {
			    printf("不正解！サイコロの目は %d でした。", diceRoll);
		    }
	    },
	    3000); // 3000ミリ秒 (3秒) 待機

	// メインスレッドが終了しないように
	std::this_thread::sleep_for(std::chrono::seconds(5));

	return 0;
}