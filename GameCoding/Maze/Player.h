#pragma once
#include "Vector.h"

class Board;

class Player
{
	enum
	{
		// 1/10 �ʸ��� MOVE �ؾ� �Ѵٴ� ���� ��Ÿ���� ��
		MOVE_TICK = 100
	};
public:

	void		Init(Board* board);
	void		Update(uint64 deltaTick);

	void		SetPos(Pos pos) { _pos = pos; }
	Pos			GetPos() { return _pos; }

	bool		CanGo(Pos pos);

private:
	void		CalculatePath_RightHand();
	void		CalculatePath_BFS
	();

public:
	Pos			_pos;
	int32		_dir = DIR_UP;
	Board*		_board = nullptr;

	// ���� �迭
	vector<Pos>	_path;
	int32		_pathIndex = 0;
	uint64		_sumTick = 0;
};

