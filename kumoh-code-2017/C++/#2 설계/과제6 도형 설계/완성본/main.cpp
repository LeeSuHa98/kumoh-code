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
	cout << " 파일에서 도형정보를 읽어들였습니다. " << endl;
	// 사각형
	r.loadRectangle("rectangle.dat", s_list);
	rectInShapeList = r.registerRectangle(s_list);
	//r.registerRectangle(s_list);
	// 원
	c.loadCircle("circle.dat", s_list);
	circleInShapeList = c.registerCircle(s_list);
	//c.registerCircle(s_list);
	cout << "------------------------------------" << endl;

	while (1)
	{
		cout << " 기능선택 [1. 크기조정 2. 출력 3. 종료] --- ";

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			// 1. 크기조정
			cout << " 대상 도형의 번호를 선택하시오. ---";
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
			// 2. 출력
			s_list.displayShape();
			break;
		case 3:
			// save to file.
			r.saveRectangle("rectangle.dat", s_list);
			c.saveCircle("circle.dat", s_list);
			// 3. 종료
			return 0;
		}
	}
}