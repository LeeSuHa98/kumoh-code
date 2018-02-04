#pragma once
#include "Galaga.h"


class Monster : public Galaga
{
private:
	int monster_kind;
	int idx;

public:
	Monster(Point pos, int kind) : Galaga(pos) {
		idx = 0;
		monster_kind = kind;
	}

	~Monster() {}

	int galagaMove(int width, int height);
	
};

