#include "Player.h"
#include "Helper.h"
#include "Map.h"

int GPlayerX = 2;
int GPlayerY = 2;

// 플레이어만 사용하는 변수
bool canMove = true;

void HandleMove()
{
	// 키보드를 떼고 있으면 다음 번엔 움직일 수 있다
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	// 움직일 수 있는가? 누르고 있던 중이면 여기서 return됨
	if (canMove == false)
		return;

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer(GPlayerX, GPlayerY + 1);
		break;
	}
}

void MovePlayer(int x, int y)
{
	// 범위 체크 코드
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;

	// 벽 체크
	int index = y * MAP_SIZE + x;
	if (GMap1D[index] == 1) // 벽이라면 이동 안 됨
		return;

	// 기존 위치 정리 
	int prevIndex = GPlayerY * MAP_SIZE + GPlayerX;
	GMap1D[prevIndex] = 0;

	// 새 위치 이동
	GPlayerX = x;
	GPlayerY = y;

	int newIndex = GPlayerY * MAP_SIZE + GPlayerX;
	GMap1D[newIndex] = 2;
};