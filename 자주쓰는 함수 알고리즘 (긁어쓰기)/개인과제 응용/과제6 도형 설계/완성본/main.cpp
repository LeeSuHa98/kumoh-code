#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapeList.h"

int main()
{
	Rectangle r;
	Circle c;
	ShapeList s_list;

	Rectangle* rectInShapeList;
	Circle* circleInShapeList;
	cout << " ���Ͽ��� ���������� �о�鿴���ϴ�. " << endl;
	// �簢��
	r.loadRectangle("rectangle.dat", s_list);
	rectInShapeList = r.registerRectangle(s_list);
	//r.registerRectangle(s_list);
	// ��
	c.loadCircle("circle.dat", s_list);
	circleInShapeList = c.registerCircle(s_list);
	//c.registerCircle(s_list);
	cout << "------------------------------------" << endl;

	while (1)
	{
		cout << " ��ɼ��� [1. ũ������ 2. ��� 3. ����] --- ";

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			// 1. ũ������
			cout << " ��� ������ ��ȣ�� �����Ͻÿ�. ---";
			int select2;
			cin >> select2;
			switch (select2)
			{
			case 1:
				// Rectangle
				rectInShapeList->resize();
				r.resize();
				break;
			case 2:
				// Circle
				circleInShapeList->resize();
				c.resize();
				break;
			}
			break;
		case 2:
			// 2. ���
			s_list.displayShape();
			break;
		case 3:
			// save to file.
			r.saveRectangle("rectangle.dat", s_list);
			c.saveCircle("circle.dat", s_list);
			// 3. ����
			return 0;
		}
	}
}