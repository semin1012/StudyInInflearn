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
		// 이동
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
	
	// 목적지
	Pos dest = _board->GetExitPos();

	//for (int i = 0; i < 20; i++)
	//{
	//	pos += Pos(1, 0);
	//	_path.push_back(pos);
	//}

	_dir;	// 내가 바라보는 방향
	pos;	// 현재 좌표

	// 내가 바라보는 방향 기준 앞에 있는 좌표?
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

	// 오른쪽 방향 90도 회전
	// DIR_LEFT 순서보다 빠르게 DIR_UP이 있기 때문에 -1
	_dir = (_dir - 1) % DIR_COUNT;
	// 왼쪽 방향 90도 회전
	_dir = (_dir + 1) % DIR_COUNT;

	// 목적지 찾을 때까지
	//while (pos != dest)
	//{
	//	// 1. 현재 바라보는 방향을 기준으로, 오른쪽으로 갈 수 있는지 확인
	//	//int32 newDir = (_dir - 1) % DIR_COUNT;	// = ?
	//	//if (CanGo(pos + front[newDir]))
	//	//{
	//	//	// 오른쪽 방향으로 90도 회전

	//	//	// 앞으로 한 보 전진

	//	//	// 좌표 기록
	//	//	_path.push_back(pos);
	//	//}

	//	//// 2. 현재 바라보는 방향을 기준으로, 전진할 수 있는지 확인
	//	//else if (CanGo(? ? ))
	//	//{
	//	//	// 앞으로 한 보 전진

	//	//	// 좌표
	//	//	_path.push_back(pos);
	//	//}

	//	//// 둘 다 안 된다면
	//	//else
	//	//{
	//	//	// 왼쪽 방향으로 90도 회전
	//	//}

	//}
}

void Player::CalculatePath_BFS()
{
	// 시작 위치
	Pos pos = _pos;
	// 목적지
	Pos dest = _board->GetExitPos();
	// 네 방향 정의
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
	// parent[y][x] = pos -> (y, x)는 Pos에 의해 발견된 것을 나타낸다. 걍 부모 좌표 ㅇㅇ!
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;

	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 목적지 도착 (예외 처리)
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++) 
		{
			// 네 방향에 대해서 갈 수 있는지 하나씩 확인
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인 
			if (CanGo(nextPos) == false)
				continue;
			// 이미 다른 경로에 의해 발견한 지역인지 확인
			if (discovered[nextPos.y][nextPos.x])
				continue;

			// 예외 처리 후에도 여기까지 내려왔다면! 예약시스템 On!
			// q에 푸쉬로 넣어둬서 이후에 뺑뺑이 돌 수 있도록 함
			// q 는 선입선출이다 
			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;	// 이전 좌표에 의해 발견되었음 기록
		}
	}

	_path.clear();
	// 내가 어떻게 목적지까지 왔는지를 패스에 조정해 주기 위해 pos를 목적지로 둔다
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// 시작점인지 판별한다
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x]; // pos를 자신의 부모의 것으로 바꾸니까 한칸씩 뒤로가는 효과
	}

	vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
		temp[i] = _path[_path.size() - 1 - i];

	_path = temp;

	// 위에 temp로 만드는 코드랑 밑의 코드랑 같은 결과임
	// std::reverse(_path.begin(), _path.end());
}
