#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

int main()
{
	const char* test = "aaa세민";
	cout << test << endl;
	// 한글로 출력을 해도 제대로 출력이 될까?
	// 사용환경에 따라 다르기도 할 것이다. 일단 출력은 됨.
	// char는 1바이트다. 1바이트에서 표현될 수 있는 숫자가 많지 않다.
	// char(1) = 0~255 < 여기에 어떻게 한글까지 표현할 수가 있지?
	
	char ch = 'A'; // A = 65번
	// 1) ASCII 코드 -> 영어만 고려함
	// 7bit (0~127) char의 반이 다 영어임
	// 어떻게 한글이 그 안에 들 수 있는가

	// ASCII 코드가 태초고, 이후에 발전해왔다.
	// 2) ANSI << 동일한 키코드값이 동일한 문자라는 보장이 없다
	// ASCII + 각국 언어별로 128개 넣음
	// 128개만으로 한글, 중국어 등을 다 표현할 수 없다. 뚫뙑 같은 거 다 포함하면 한국어도 128 넘음
	// 한국어는 CP949라는 포멧을 사용. 모든 문자들에 대해 번호가 매겨짐.
	setlocale(LC_ALL, "");
	cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << endl;
	// 출력: LC_ALL: Korean_Korea.949
	// 윈도우가 한국어라서 이 렇게 나온다.
	// 영어는 2 글자가 1바이트인데, 한국어는 1글자가 1바이트.
	
	// 문제 - 나라마다 글자가 다르다는 것이 끔찍한 부분이다.
	// 다른 나라 사이트 가면 통신이 절대 불가능한 상황이 됨
	// 로컬환경이면 상관 없지만 통신이 들어가면 난리가 난다.

	// 3) 유니코드 (동일한 번호 = 동일한 문자 = 동일한 유니코드 보장)
	// 대표적인 것: 인코딩(UTF-8, UTF-16). 나머지는 사용할 일 없음
	// - utf8: 영어(1바이트), 한국어/중국어(3바이트)
	// - utf16: 영어(2바이트), 한국(2), 중국어(2), 진짜진짜잘안쓰는거(3)
	// 한국, 중국에서 서비스한다면 utf16이 나을 것
	auto test2 = u8"aaa세민입니다";
	// setlocale로 UTF-8로 출력 변경해줘야 제대로 나온다. 
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << test2 << endl;

	// char는 1바이트라면서 사실 국가가 다를 때마다 2바이트로 사용됨
	// const char*이 아니라 const void*라고 이해하는 것이 맞을 것이다.
	// 포인터를 타고 갔을 때 char이 있는 게 아니라 void가 있는 것이다.
	
	// UTF16
	auto test3 = L"UTF16 - aaa세민입니다";
	// UTF16은 거의 모든 애들이 2바이트를 차지하게 된다. 
	cout << test3 << endl;
	// 아무튼 이런 출력 문제들 때문에 구닥다리 const char*보다는 string을 사용하게 될 것이다.
	
	// 4) MBCS(Multi Byte Character Set) vs WBCS(Wide Byte Character Set)
	// - 멀티바이트 집합(MBCS): 가변 길이 인코딩, ANSI, UTF-8
	// 							국가마다 1바이트일 수도, 2바이트일 수도
	// - 유니코드 집합(WBCS): 고정 길이 인코딩, UTF-16
	//						  국가마다 2바이트로 통일

	// char // string
	wchar_t ch = L'루';	// L 표시는 Wide Byte라는 표시다 
	wstring name = L"세민입니다";
	wcout << name << endl;
	// WBCS 형식의 char과 string이라고 보면 된다.
	// 실질적으로 2바이트의 char과 string이다. 
	// 언리얼이나 유니티에서도 다 2바이트임.
	// utf16으로 관리하는 것이 보통이다. 

	// 유니코드와 유니코드 집합은 다른 의미다. 
}