#pragma once

class Point
{
private:
	int x, y;

public:
	Point(int x, int y);
	Point();
	~Point();

	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	bool isSame(Point pos);
	void pointMove(int dir);
};