﻿#include <iostream>
using namespace std;

int main()
{
	// C 스타일 캐스팅

	// 값 타입 변환
	// 특징) 의미를 유지하기 위해서 원본 객체와 다른 비트열 재구성
	{
		int a = 123456789;
		float b = (float)a;
		// 위처럼 괄호를 치는 것을 C 스타일 캐스팅이라고 한다. 옛날 스타일.
		// C++ 에서는 위처럼 쓰는 것은 안 좋다. 다른 의미로 받아들여질 수도 있고, 위험한 작업이기 때문에.
		
		// b= 123456792.라는 숫자가 나옴. 2의 보수와 다른 방식으로 숫자를 넣기 때문이다. 
		// 큰 숫자를 정확히 표현하기 힘들다. 
		int c = 0;
	}

	// 참조 타입 변환
	{
		int a = 123456789;
		float b = (float&)a;	//1.65359970e-34 나옴. 메모리 값 자체를 float로 분석하는 것.
		int c = 0;
	}

	// 안전한 변환 (의미가 100% 일치): 작은 곳에서 큰 곳으로 옮길 때 
	{
		int a = 123456789;
		__int64 b = (__int64)a;
		int c = 0;
	}

	// 불안전한 변환 (의미가 불일치): 큰 곳에서 작은 곳으로 옮길 때
	{
		int a = 123456789;
		short b = (short)a;		// -13035
		int c = 0;
	}

	// 암시적 변환, 괄호 생략해도 컴파일이 변환시켜준다.
	{
		int a = 123456789;
		float b = a;
	}
}
 