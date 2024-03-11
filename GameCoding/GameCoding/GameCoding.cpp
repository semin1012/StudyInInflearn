#include <iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX];
int N;

void PrintBoard()
{
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGo(int x, int y)
{
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void SetBoard()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	// 방향을 enum 대신 간단하게 쓰고 싶을 때
	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	while (true)
	{
		board[x][y] = num;

		if (num == N * N)
			break; // 끝 숫자에 도달하면 break

		
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		/*int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}*/

		if (CanGo(nextY, nextX)) 
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else  
		{
			// 방향을 enum 대신 쓰고 싶을 때
			dir = (dir + 1) % 4;

			/*switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}*/
		}
	}

	PrintBoard();
}

int main()
{
	cin >> N;

	SetBoard();
}