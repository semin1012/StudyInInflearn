#include <iostream>
using namespace std;

void AddHp(int* hp, int value)
{
	*hp += value;
}



int main()
{
	int hp = 100;

	// [타입] * [이름];
	// - * = 포인터
	// - 주소값을 담는 바구니라고 생각하면 된다
	// - 주소값을 타고 가면 -> 무엇이 있느냐? (타입, ex: int 타입)
	int* ptr = &hp;

	*ptr = 200; // 원본 데이터를 수정할 수 있음
	// *ptr - ptr의 주소를 타고 가라
	cout << *ptr << endl;  //200


	float* ptr2 = (float*)&hp;

	cout << *ptr2 << endl;  //2.8026e-43
	// int 원본 데이터를 float 포인터를 사용하면
	// 이상한 값이 결과로 나온다 주의할 것


	__int64* ptr3 = (__int64*)&hp;

	cout << *ptr3 << endl;  //-3689348818177883960
	// 작은 메모리에 더 큰 메모리를 넣으려고 하니까
	// 원래는 사용하면 안 되는 메모리에 접근해서 건들이는 상황
	// 심각한 문제를 낳을 수 있다

	AddHp(&hp, 10);		// 복사가 되긴 한다. '주소값'을 복사해주는 것
						// 주소값 안의 원본 데이터를 수정할 수 있음
	cout << hp << endl;	// 210

	// 주소를 접근하면 많은 것을 할 수 있지만 위험하다.


	int* ptr4 = (int*)100;
	// 주소 100번지를 ptr4에 담음
	
	ptr4 += 1;
	// 주소 100번지의 다음칸으로 넘어가라는 명령

	cout << (int)ptr4 << endl;  // 104, int형을 한칸 뒤로 밀어서 104 나옴

	int** pptr = &ptr; // 주소 -> 주소 -> 정수라는 뜻의 이중포인터

}