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
	// C스타일 문자열
	const char* name = "Semin";
	const char* name2 = "Semin";
	// 끝에 null 들고 있어야 하고 포인터로 시작번지를 알려야 하는 구닥다리 문자열
	// id, pw 비교/추가/자르기 등 작업을 하기에 한계가 많다

	if (name == name2)
		cout << "같음" << endl;
	else
		cout << "다름" << endl;
	// 같다고 뜨긴 한데 컴파일마다 달라질 수 있다.

	char bname[] = "Semin";
	char bname2[] = "Semin";

	if (bname == bname2)
		cout << "같음" << endl;
	else
		cout << "다름" << endl;
	// 버퍼에 담아서 사용하니 문자열 비교가 아니라 주소값을 비교하는 것 확인 가능.

	// 그래서 string으로 문자열을 비교한다.
	std::string str = "Semin";
	std::string str2 = "Semin";
	// C스타일은 최대한 안 쓰는 게 좋고, 이것을 지향하는 게 좋다.

	// str.capacity(); 이런 것도 가능

	// 1) 비교
	// 비교 함수도 있음 -> str.compare(str2);
	if (str == str2)	// 이렇게 비교하는 게 일반적
	{
		cout << "str == str2: 같다 " << endl;
	}

	// 2) 복사
	string str3;
	str3 = str;
	// str3을 나중에 변화시켜도 원본에는 영향을 안 준다.

	// 3) 추가
	// 함수로도 추가 가능 str.append("1234");
	str += "1234";
	cout << "str에 1234 추가: " << str << endl;
	// 캐삭해도 나중에 운영자가 복원해주는 경우 있음
	// 삭제했는데 어떻게 복원을 해 줄까?
	// 비밀은? 삭제를 하지 않음.
	// 그냥 상태만 DELETE 등으로 바꿔두고 아이디만 다른 걸로 겹치지 않게끔 해둔다.
	// 다른 사람이 그 아이디 사용할 수 있도록 변경해 둠. 

	// 4) 찾기
	auto c = str.find("Se");	// 몇번째에서 찾았는지 번지가 나온다
	// 검색한 단어가 없으면 string::nops 반환함
	if (c == std::string::npos)
	{
		cout << "not found";
	}

	// 5) 교체
	string chatStr = "SHIT !!!";
	string findStr = "SHIT";
	string replaceStr = "****";
	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);
	// 욕설 문자 사용했을 때 바꾸는 방법임
	// 이런 거 보통 클라에서 하는 게 맞다

	// 문자열 잘라서 다른 문자열로 만들기
	string str4 = str.substr(0, 3);

	str.c_str();	// const char*로 만들 수 있다.
	// 옛날 문법 사용할 일이 생길 수 있으니 알아두면 된다. 
}