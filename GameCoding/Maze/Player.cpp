#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	//CalculatePath_RightHand();
	CalculatePath_BFS();
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

void Player::CalculatePath_RightHand()
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

void Player::CalculatePath_BFS()
{
	// ���� ��ġ
	Pos pos = _pos;
	// ������
	Pos dest = _board->GetExitPos();
	// �� ���� ����
	Pos front[4] =
	{
		Pos(-1, 0),	//UP
		Pos(0, -1),	//LEFT
		Pos(1, 0),	//DOWN
		Pos(0, 1),	//RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	// extra)
	// parent[y][x] = pos -> (y, x)�� Pos�� ���� �߰ߵ� ���� ��Ÿ����. �� �θ� ��ǥ ����!
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;

	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// ������ ���� (���� ó��)
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++) 
		{
			// �� ���⿡ ���ؼ� �� �� �ִ��� �ϳ��� Ȯ��
			Pos nextPos = pos + front[dir];
			// �� �� �ִ� ������ �´��� Ȯ�� 
			if (CanGo(nextPos) == false)
				continue;
			// �̹� �ٸ� ��ο� ���� �߰��� �������� Ȯ��
			if (discovered[nextPos.y][nextPos.x])
				continue;

			// ���� ó�� �Ŀ��� ������� �����Դٸ�! ����ý��� On!
			// q�� Ǫ���� �־�ּ� ���Ŀ� ������ �� �� �ֵ��� ��
			// q �� ���Լ����̴� 
			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;	// ���� ��ǥ�� ���� �߰ߵǾ��� ���
		}
	}

	_path.clear();
	// ���� ��� ���������� �Դ����� �н��� ������ �ֱ� ���� pos�� �������� �д�
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// ���������� �Ǻ��Ѵ�
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x]; // pos�� �ڽ��� �θ��� ������ �ٲٴϱ� ��ĭ�� �ڷΰ��� ȿ��
	}

	vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
		temp[i] = _path[_path.size() - 1 - i];

	_path = temp;

	// ���� temp�� ����� �ڵ�� ���� �ڵ�� ���� �����
	// std::reverse(_path.begin(), _path.end());
}
