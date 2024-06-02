#include <iostream>
#include <unordered_map>
#include <windows.h>
#include <algorithm>

// ENCHANT

// +0 집행검
// 무기 강화 주문서 -> +1 +2 +3 중 하나가 랜덤으로 뜬다

// +9 집행검 뜨는 경우의 수는?
// ex) +1 +2 +3 +4 ... +9
// ex) +3 +6 +9
// ex) +1 +3 +4 ... +9 등

int N = 9;
int cache[100];

// [+num]부터 시작해서, [+N]까지 가는 경우의 수
int Enchant(int num)
{
	// 기저 사례
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// 캐시
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// 적용 
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}
// 항상 기저사례, 캐시, 적용 세 부분으로 나뉜다.

int main()
{
	memset(cache, -1, sizeof(cache));

	int ret = Enchant(0);
	// 0강이니까 0부터 시작
	std::cout << ret << std::endl;
}