#include <iostream>
using namespace std;

enum class ScreenColor
{
	RED,
	GREEN,
};

enum ScreenColor_orgin
{
	SC_RED,
	SC_GREEN,
};

enum class LightColor
{ 
	RED,
	GREEN,
};

// enum class를 사용하면 이름 범위 문제 해결해 줌
// 타입 변환 어거지로 해 주는 걸 해결해 줌
// SC_RED 는 int a 에 형변환 없이도 넣어짐. 이게 불안한 코드다.
// enum class 는 static_cast 를 사용해서 직접 형변환을 해야 넣어짐. 안전. 

int main()
{
	int a = static_cast<int>(ScreenColor::RED);
}