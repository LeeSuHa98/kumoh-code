#include "Rectangle.h"

//int Rectangle::findRectangle(ShapeList& s_list)
//{
//	for (int i = 0; i < s_list.getCount(); i++)
//	{
//		if (width == s_list.getShapeList(i)->getWidth())
//		{
//			return i;
//		}
//		for (int j = 0; j < s_list.getCount(); j++)
//		{
//			if (height == s_list.getShapeList(j)->getHeight())
//			{
//				return j;
//			}
//		}
//	}
//}

Rectangle* Rectangle::registerRectangle(ShapeList& s_list)
{
	cout << " Rectangle " << endl << endl;

	cout << " x 좌표 : ";
	cin >> centerX;
	cout << " y 좌표 : ";
	cin >> centerY;
	cout << " 너비 : ";
	cin >> width;
	cout << " 높이 : ";
	cin >> height;
	cout << endl;

	Rectangle* r = new Rectangle(centerX, centerY, width, height);

	s_list.insertShape(r);
	s_list.plusCount();

	return r;
}

void Rectangle::loadRectangle(string fileName, ShapeList& s_list) // 파일 읽기용
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int centerX;
	int centerY;
	int width;
	int height;

	while (!fin.eof()) // 파일의 끝에 도달하지 않았다면 계속 반복
	{
		fin >> centerX >> centerY >> width >> height; // 파일의 값을 읽음
		Rectangle* r = new Rectangle(centerX, centerY, width, height); // Student 임시 객체 생성
		s_list.insertShape(r);
		s_list.plusCount();
	}

	fin.close();
}

void Rectangle::saveRectangle(string fileName, ShapeList& s_list) // 파일 쓰기용
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

void Rectangle::print()
{
	cout << "[1] 사각형 -> 중심 : (" << centerX << ", " << centerY << ")" << " 너비 : " << width << " 높이 : " << height;
	calArea();
	cout << endl;
}

void Rectangle::calArea()
{
	cout << " 면적 : " << width * height << endl;
}

void Rectangle::resize()
{
	cout << " 도형의 정보를 수정합니다 " << endl;

	
	cout << " 너비와 높이를 순서대로 입력하세요 " << endl;
	//
	//int shape_type = insertShapeType();

	//Shape* s = getRectangle(shape_type, s_list);
	//s_list.updateShape(findRectangle(s_list), s);
	int tempWidth, tempHeight;
	cin >> tempWidth;
	cin >> tempHeight;

	width = tempWidth;
	height = tempHeight;
}

//int Rectangle::insertShapeType()
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
//Shape* Rectangle::getRectangle(int shape_type, ShapeList& s_list)
//{
//	if (shape_type == 1)
//	{
//		// Rectangle
//		Rectangle* s = registerRectangle(s_list);
//
//		return s;
//	}
//}