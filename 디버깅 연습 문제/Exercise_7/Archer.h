#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer();
	Archer(int hp);
	virtual ~Archer();

public:
	class Pet* _pet;
};

