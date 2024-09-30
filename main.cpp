#include <stdio.h>

// 一般的な賃金計算関数(引数は働いた時間)
int Normal(int time) {

	// 働いた時間×1072円
	return time * 1072;
}

// 再帰的な賃金計算関数
int Recursion(int time) {

	// 最初の1時間は100円
	if (time == 1) {
		return 100;
	}
	// 2時間目以降は再帰関数で計算
	return (Recursion(time - 1) * 2 - 50);
}

// 合計賃金計算関数
int TotalWage(int time) {
	// 合計の金額
	int total = 0;
	for (int i = 1; i <= time; i++) {
		// 各時間の賃金を加算
		total += Recursion(i);
	}
	return total;
}

// 再帰的な賃金が一般的な賃金を超える時間を計算する関数
int FindHours() {
	for (int hours = 1; hours <= 24; hours++) { // 上限は24時間
		if (TotalWage(hours) > Normal(hours)) {
			return hours; // 再帰的な賃金が一般的な賃金を超える時間を返す
		}
	}
	return -1; // 条件を満たす時間が見つからなかった場合
}

int main() {
	
	// 労働時間
	int hours = 1;

	printf("労働時間 : %d時間\n\n", hours); // 労働時間を出力

	printf("一般的な時給1072円の%d時間の賃金 : %d円\n", hours, Normal(hours)); // 一般的な賃金を出力
	printf("再帰的な時給の%d時間の賃金       : %d円\n", hours, TotalWage(hours)); // 再帰的な賃金を出力

	printf("----------------------------------------------------------------\n");

	// 再帰的な賃金が一般的な賃金を超える時間を計算
	int hoursToExceed = FindHours();
	if (hoursToExceed != -1) {
		printf("再帰的な賃金が一般的な賃金を超えるのは %d 時間です。\n", hoursToExceed); // 再帰的な賃金が高くなる時間を出力
	} else {
		printf("再帰的な賃金が一般的な賃金を超える時間は見つかりませんでした。\n");
	}

	return 0;
}