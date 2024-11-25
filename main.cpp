#include <cstring>
#include <list>
#include <stdio.h>

struct Station {
	char name[50];   // 駅名を文字配列で管理
	int year_opened; // 開業年
};

void displayStations(const std::list<Station>& stations, int year) {
	printf("%d年の駅リスト:\n", year);
	for (const auto& station : stations) {
		if (station.year_opened <= year) {
			printf(" - %s\n", station.name);
		}
	}
}

int main() {
	// 双方向リストを作成
	std::list<Station> yamanoteLine = {
	    {"Tokyo",        1885},
        {"Kanda",        1885},
        {"Akihabara",    1925},
        {"Okachimachi",  1925},
        {"Ueno",         1883},
        {"Uguisudani",   1912},
        {"Nippori",      1905},
	    {"Tabata",       1896},
        {"Komagome",     1910},
        {"Sugamo",       1903},
        {"Otsuka",       1903},
        {"Ikebukuro",    1903},
        {"Mejiro",       1885},
        {"Takadanobaba", 1910},
	    {"Shin-Okubo",   1914},
        {"Shinjuku",     1885},
        {"Yoyogi",       1906},
        {"Harajuku",     1906},
        {"Shibuya",      1885},
        {"Ebisu",        1901},
        {"Meguro",       1885},
	    {"Gotanda",      1911},
        {"Osaki",        1901},
        {"Shinagawa",    1872},
        {"Tamachi",      1909},
        {"Hamamatsucho", 1909},
        {"Shimbashi",    1872},
        {"Yurakucho",    1910}
    };

	// 新しい駅をリストに追加
	Station nishiNippori = {"Nishi-Nippori", 1971};
	Station takanawaGateway = {"Takanawa Gateway", 2020};

	// 西日暮里駅を適切な位置に挿入
	auto it = yamanoteLine.begin();
	for (; it != yamanoteLine.end(); ++it) {
		if (strcmp(it->name, "Tabata") == 0) {
			++it; // 田端の次に挿入
			yamanoteLine.insert(it, nishiNippori);
			break;
		}
	}

	// 高輪ゲートウェイ駅を挿入
	for (it = yamanoteLine.begin(); it != yamanoteLine.end(); ++it) {
		if (strcmp(it->name, "Tamachi") == 0) {
			++it; // 田町の次に挿入
			yamanoteLine.insert(it, takanawaGateway);
			break;
		}
	}

	// 各年の駅リストを表示
	displayStations(yamanoteLine, 1970);
	displayStations(yamanoteLine, 2019);
	displayStations(yamanoteLine, 2022);

	return 0;
}