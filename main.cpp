#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

// 奇数偶数を判定するコールバック関数
bool isOdd(int number) { return number % 2 != 0; }

// ゲームを進行する関数
void playGame(bool (*callback)(int)) {
	// サイコロの目をランダムに生成
	int diceRoll = rand() % 6 + 1;

	// ユーザーに奇数か偶数かを入力してもらう
	std::string userGuess;
	printf("奇数か偶数か当ててください (奇数: odd / 偶数: even): ");
	std::cin >> userGuess;

	// 3秒待機
	std::this_thread::sleep_for(std::chrono::seconds(3));

	// ユーザーの予測とサイコロの目を比較
	bool isUserCorrect = (userGuess == "奇数" && callback(diceRoll)) || (userGuess == "偶数" && !callback(diceRoll));

	// 結果を表示
	if (isUserCorrect) {
		printf("正解！サイコロの目は %d でした。", diceRoll);
	} else {
		printf("不正解！サイコロの目は %d でした。", diceRoll);
	}
}

int main() {
	// 乱数の種を設定
	srand(static_cast<unsigned int>(time(0)));

	// ゲームを実行
	playGame(isOdd);

	return 0;
}
