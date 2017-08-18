#include "Monster.h"

int Monster::galagaMove(int width, int height)
{
	int x = pos.getX() + dx[moving[LEVEL1][idx]];
	int y = pos.getY() + dy[moving[LEVEL1][idx]];

	idx++;
	if (moving[monster_kind][idx] == DO_NOTING)
		idx = 0;

	if (y >= height)
		return OUT_MONSTER;

	if (x < 0)
		x = 0;
	if (x >= height)
		x = height - 1;

	pos.setX(x);
	pos.setY(y);

	return CONTINUE;
}