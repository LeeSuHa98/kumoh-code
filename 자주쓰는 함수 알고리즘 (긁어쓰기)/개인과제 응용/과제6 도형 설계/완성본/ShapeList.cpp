#include "ShapeList.h"

void ShapeList::insertShape(Shape* s)
{
	shape_list[count] = s;
}

void ShapeList::updateShape(int index, Shape* s)
{
	shape_list[index] = s;
}

void ShapeList::displayShape()
{
	cout << " ������ ������ ����մϴ�. " << endl;

	for (int i = 0; i < count; i++)
	{
		Shape* s = shape_list[i];
		s->print();
	}
}
