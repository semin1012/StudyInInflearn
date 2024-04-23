#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp);
	~Knight();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

public:
	int _hp;
	const int _maxHp = 4000;
	int _attack;
};

