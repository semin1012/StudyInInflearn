#pragma once
#include "ConsoleHelper.h"

enum
{
	BOARD_MAX_SIZE = 100
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL
};

// 헤더에는 웬만하면 "Player.h" 추가하면 안 됨
// 따라서 class 로 일단 넘어가게 만들어야 함
// cpp 파일에 헤더 파일 추가해야 한다
class Player;

class Board
{
public:
	Board();
	~Board();

	void			Init(int32 size, Player* player);
	void			Render();

	void			GenerateMap();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);

	Pos				GetEnterPos() { return Pos(1, 1); }
	Pos				GetExitPos() { return Pos(_size - 2, _size - 2); }

	int32			GetSize() { return _size; }

private:
	TileType		_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	int32			_size = 0;
	Player*			_player = nullptr;
};

