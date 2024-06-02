#include <iostream>
#include <unordered_map>
#include <windows.h>
#include <algorithm>

// 메모이제이션 (memoization)
// 중간에 있는 값을 저장했다가 그것을 재사용하겠다.
int cache[50][50];

//int combination(int n, int r)
//{
//	if (r == 0 || n == r)
//		return 1;
//
//	return combination(n - 1, r - 1) + combination(n - 1, r);
//}	// 약 100ms의 시간이 걸림



int combination(int n, int r)
{
	// 기저 사례
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한 적 있으면 바로 반환
	int& ret = cache[n][r];
	// 참조값으로 만들어서 복사가 되는 게 아니라 바로 넣어진다 
	if (ret != -1)
		return ret;

	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}	// 약 0ms의 시간이 걸림!! 훨신 빨라짐
// 이런 것이 dp다. 

int main()
{
	::memset(cache, -1, sizeof(cache));	// -1로 다 채운다

	__int64 start = GetTickCount64();
	
	int lotto = combination(45, 6);

	__int64 end = GetTickCount64();

	std::cout << end - start << "ms" << std::endl;
}