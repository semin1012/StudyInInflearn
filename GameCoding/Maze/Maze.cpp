#include "pch.h"
#include "Vector.h"
#include "Player.h"
#include "Board.h"
#include "Stack.h"
#include "List.h"

Board board;
Player player;

int main()
{
	List<int> li;

	auto node2 = li.GetNode(0);

	li.AddAtHead(1);
	li.AddAtHead(2);

	auto node3 = li.GetNode(1);

	li.AddAtHead(3);
	li.Print();

	auto node = li.GetNode(3);

	//----------------------------------------------------------------------------

	::srand(static_cast<uint32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;

	while (true)
	{
#pragma region 프레임 관리 
// 위처럼 적으면 접었다 폈다 할 수 있음! 코드 정리에 유용
		// ::GetTickCount64() - 어느 시점을 기준으로 경과된 시간을 리턴한다.
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion

		// 입력

		// 로직
		player.Update(deltaTick);

		// 렌더링
		board.Render();
	}
}