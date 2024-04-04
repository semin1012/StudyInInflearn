#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	CalculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;
	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		// �̵�
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);
	
	// ������
	Pos dest = _board->GetExitPos();

	//for (int i = 0; i < 20; i++)
	//{
	//	pos += Pos(1, 0);
	//	_path.push_back(pos);
	//}

	_dir;	// ���� �ٶ󺸴� ����
	pos;	// ���� ��ǥ

	// ���� �ٶ󺸴� ���� ���� �տ� �ִ� ��ǥ?
	Pos front[4] =
	{
		Pos(-1, 0),	//UP
		Pos(0, -1),	//LEFT
		Pos(1, 0),	//DOWN
		Pos(0, 1),	//RIGHT
	};

	Pos next = pos + front[_dir];

	/*switch (_dir)
	{
	case DIR_UP:
		Pos next = pos + Pos(-1, 0);
		break;
	case DIR_LEFT:
		Pos next = pos + Pos(0, -1);
		break;
	case DIR_DOWN:
		Pos next = pos + Pos(1, 0);
		break;
	case DIR_RIGHT:
		Pos next = pos + Pos(0, 1);
		break;
	}*/

	// ������ ���� 90�� ȸ��
	// DIR_LEFT �������� ������ DIR_UP�� �ֱ� ������ -1
	_dir = (_dir - 1) % DIR_COUNT;
	// ���� ���� 90�� ȸ��
	_dir = (_dir + 1) % DIR_COUNT;

	// ������ ã�� ������
	//while (pos != dest)
	//{
	//	// 1. ���� �ٶ󺸴� ������ ��������, ���������� �� �� �ִ��� Ȯ��
	//	//int32 newDir = (_dir - 1) % DIR_COUNT;	// = ?
	//	//if (CanGo(pos + front[newDir]))
	//	//{
	//	//	// ������ �������� 90�� ȸ��

	//	//	// ������ �� �� ����

	//	//	// ��ǥ ���
	//	//	_path.push_back(pos);
	//	//}

	//	//// 2. ���� �ٶ󺸴� ������ ��������, ������ �� �ִ��� Ȯ��
	//	//else if (CanGo(? ? ))
	//	//{
	//	//	// ������ �� �� ����

	//	//	// ��ǥ
	//	//	_path.push_back(pos);
	//	//}

	//	//// �� �� �� �ȴٸ�
	//	//else
	//	//{
	//	//	// ���� �������� 90�� ȸ��
	//	//}

	//}
}
