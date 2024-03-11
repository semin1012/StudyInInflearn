#include <iostream>
using namespace std;

// 로또 번호 생성기
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// { 1, 42, 3, 15, 5, 6 } -> { 1, 3, 5, 6, 15, 42 }
void Sort(int* numbers, int count)
{
	for (int i = 0; i < count; i++)
	{
		// 마지막 숫자는 하면 안 되니까 -1
		// i번째 가장 큰 숫자는 이미 뒤로 가 있으니까 -i
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
				Swap(numbers[j], numbers[j + 1]);
		}
	}
}

void ChooseLotto(int* numbers)
{
	int count = 0;

	while (count != 6)
	{
		// 1~45 랜덤 추출
		int randValue = 1 + rand() % 45; 
		
		// 이미 찾은 값인지?
		bool found = false;
		for (int i = 0; i < count; i++) {
			if (numbers[i] == randValue) {
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}

		numbers[count] = randValue;
	}

	Sort(numbers, 6);
}

int main()
{
	srand((unsigned)time(0));
	int lotto[6];
	ChooseLotto(lotto);

	Sort(lotto, 6);

	for (int i = 0; i < 6; i++)
		cout << lotto[i] << " ";
}