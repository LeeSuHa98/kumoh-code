#pragma once

class Player : public Galaga
{
public:
	Player(Point pos) : Galaga(pos) {}

	void setPoint(Point point) { pos = point; }
	void move(int dir) { pos.pointMove(dir); }
};