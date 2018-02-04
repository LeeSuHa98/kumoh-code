#include "Circle.h"

//int Circle::findCircle(ShapeList& s_list)
//{
//	for (int i = 0; i < s_list.getCount(); i++)
//	{
//		if (radius == s_list.getShapeList(i)->getRadius())
//		{
//			return i;
//		}
//	}
//}

Circle* Circle::registerCircle(ShapeList& s_list)
{
	cout << " Circle " << endl << endl;

	cout << " x 좌표 : ";
	cin >> centerX;
	cout << " y 좌표 : ";
	cin >> centerY;
	cout << " 반지름 : ";
	cin >> radius;
	cout << endl;

	Circle* c = new Circle(centerX, centerY, radius);

	s_list.insertShape(c);
	s_list.plusCount();

	return c;
}

void Circle::loadCircle(string fileName, ShapeList& s_list) // 파일 읽기용
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int centerX;
	int centerY;
	int radius;

	while (!fin.eof()) // 파일의 끝에 도달하지 않았다면 계속 반복
	{
		fin >> centerX >> centerY >> radius; // 파일의 값을 읽음
		Circle* c = new Circle(centerX, centerY, radius); // Student 임시 객체 생성
		s_list.insertShape(c);
		s_list.plusCount();
	}

	fin.close();
}

void Circle::saveCircle(string fileName, ShapeList& s_list) // 파일 쓰기용
{
	ofstream fout;
	fout.open(fileName, ios_base::out);

	for (int i = 0; i < s_list.getCount(); i++)
	{
		Shape* s = s_list.getShapeList(i);
		s->print();
	}

	fout.close();
}

void Circle::print()
{
	cout << "[2] 원 -> 중심 : (" << centerX << ", " << centerY << ")" << " 반지름 : " << radius;
	calArea();
	cout << endl;
}

void Circle::calArea()
{
	cout << " 면적 : " << radius * radius * 3.14 << endl;
}

void Circle::resize()
{
	cout << " 도형의 정보를 수정합니다 " << endl;


	cout << " 변경할 반지름을 입력하세요 " << endl;

	//int shape_type = insertShapeType();

	//Shape* s = getCircle(shape_type, s_list);
	//s_list.updateShape(findCircle(s_list), s);

	int tempRadius;
	cin >> tempRadius;

	radius = tempRadius;
}

//int Circle::insertShapeType()
//{
//	int shape_type;
//
//	while (1)
//	{
//		cout << endl;
//		cout << "[1]사각형" << endl;
//		cout << "[2]원" << endl;
//
//		cin >> shape_type;
//
//		if (shape_type == 1 || shape_type == 2)
//		{
//			return shape_type;
//		}
//		else
//		{
//			cout << " 잘못 입력하셨습니다. " << endl;
//		}
//	}
//}
//
//Shape* Circle::getCircle(int shape_type, ShapeList& s_list)
//{
//	if (shape_type == 2)
//	{
//		// Rectangle
//		Shape* s = registerCircle(s_list);
//
//		return s;
//	}
//}