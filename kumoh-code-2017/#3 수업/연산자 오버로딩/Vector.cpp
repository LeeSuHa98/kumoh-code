#include "Vector.h"

Vector operator+ (const Vector& v1, const Vector& v2)
{
	Vector v(0.0, 0.0);
	v.x = v1.x + v2.x;
	v.y = v1.y + v1.y;

	return v;
}