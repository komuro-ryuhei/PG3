#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>

int main() {
	// 100000文字のstd::stringを初期化
	std::string a(100000, 'a');

	// コピーの計算
	auto start_copy = std::chrono::high_resolution_clock::now();
	std::string b = a; // コピー
	auto end_copy = std::chrono::high_resolution_clock::now();
	auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

	// 移動の計算
	auto start_move = std::chrono::high_resolution_clock::now();
	std::string c = std::move(a); // 移動
	auto end_move = std::chrono::high_resolution_clock::now();
	auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

	// 結果を表示 (printfを使用)
	printf("100,000文字を移動とコピーで比較しました。\n");
	printf("コピー: %lldμs\n", copy_duration);
	printf("移動: %lldμs\n", move_duration);

	return 0;
}