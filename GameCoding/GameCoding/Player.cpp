#include "Player.h"
#include "Helper.h"
#include "Map.h"

int GPlayerX = 2;
int GPlayerY = 2;

// �÷��̾ ����ϴ� ����
bool canMove = true;

void HandleMove()
{
	// Ű���带 ���� ������ ���� ���� ������ �� �ִ�
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	// ������ �� �ִ°�? ������ �ִ� ���̸� ���⼭ return��
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
	// ���� üũ �ڵ�
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;

	// �� üũ
	int index = y * MAP_SIZE + x;
	if (GMap1D[index] == 1) // ���̶�� �̵� �� ��
		return;

	// ���� ��ġ ���� 
	int prevIndex = GPlayerY * MAP_SIZE + GPlayerX;
	GMap1D[prevIndex] = 0;

	// �� ��ġ �̵�
	GPlayerX = x;
	GPlayerY = y;

	int newIndex = GPlayerY * MAP_SIZE + GPlayerX;
	GMap1D[newIndex] = 2;
};