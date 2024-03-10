#include <iostream>
using namespace std;

int main()
{
	cout << "Hello World" << endl;

	char ch = 'A';
	cout << ch << endl;

	char str[] = { 'H', 'e', 'l', 'l', 'o' };
	// 이 문법에서 'H'와 같은 문자 각각은 스택 영역에 저장된다. 
	cout << str << endl; // Hello儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆季-긃?
	// '\0'(null 처리, 0으로 넣어도 됨)를 넣어 줘야 긑인 걸 알아듣는다.
	// 안 넣어 주면 위의 결과처럼 이상하게 뜸

	char str2[] = "Hello "; // 요즘 쓰는 스타일
	cout << str2 << endl;

	const char* ptr = "Hello";
	// 포인터로 사용하려면 const를 적어야 한다.
	// 포인터를 타고 간 다음의 데이터를 건들이지 말라는 뜻, 가르키는 변수 자체는 다른 걸로 바꿔도 됨
	// char* const a << 이렇게 쓸 수도 있다. 
	// 이건 애당초 a를 바꿀 수 없다는 것. 포인터 변수를 바꿔칠 수가 없다.
	// 포인터의 변경을 막고 싶으면 const char* const 이렇게 쓸 수 있으나 잘 안 씀.
	// 이 문법에서 지역 변수(char)에 담긴 ‘문자열’은 데이터 영역에 포함된다.
	// char이 가르키는 데이터의 주소값은 스택 영역에 저장되지만, 주소값이 가르키는 데이터는 데이터 영역에 저장되는 것이다. 포인터를 사용했기 때문에.
}