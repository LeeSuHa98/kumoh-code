#include "Vector.h"

int main()
{
	Vector v1(1,2), v2(3,4);
	Vector v3 = v1 + v2;
	v3.display();

	return 0;
}