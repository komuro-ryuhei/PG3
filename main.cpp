#include <stdio.h>

// 2つの引数の小さい値を返す関数
template<typename Type>

Type Min(Type a, Type b) {
	if (a < b) {
		return static_cast<Type> (a);
	} else if (b < a) {
		return static_cast<Type> (b);
	} else {
		printf("同値\n");
		return static_cast<Type> (a);
	}
}

// const char* 型専用のMin関数の特殊化
template<> const char* Min<const char*>(const char* a, const char* b) {
	const char* str = "数字以外は代入できません";
	return str;
}

int main() {

	printf("%d\n" ,Min<int>(200, 100)); // int型同士
	printf("%f\n" ,Min<float>(22.0f, 11.0f)); // float型同士
	printf("%f\n" ,Min<double>(2.2, 1.1)); // double型同士
	printf("%s\n" ,Min<const char*>("ひゃく", "にひゃく")); // char型同士

	return 0;
}