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

	cout << " x ��ǥ : ";
	cin >> centerX;
	cout << " y ��ǥ : ";
	cin >> centerY;
	cout << " �ʺ� : ";
	cin >> width;
	cout << " ���� : ";
	cin >> height;
	cout << endl;

	Rectangle* r = new Rectangle(centerX, centerY, width, height);

	s_list.insertShape(r);
	s_list.plusCount();

	return r;
}

void Rectangle::loadRectangle(string fileName, ShapeList& s_list) // ���� �б��
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int centerX;
	int centerY;
	int width;
	int height;

	while (!fin.eof()) // ������ ���� �������� �ʾҴٸ� ��� �ݺ�
	{
		fin >> centerX >> centerY >> width >> height; // ������ ���� ����
		Rectangle* r = new Rectangle(centerX, centerY, width, height); // Student �ӽ� ��ü ����
		s_list.insertShape(r);
		s_list.plusCount();
	}

	fin.close();
}

void Rectangle::saveRectangle(string fileName, ShapeList& s_list) // ���� �����
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
	cout << "[1] �簢�� -> �߽� : (" << centerX << ", " << centerY << ")" << " �ʺ� : " << width << " ���� : " << height;
	calArea();
	cout << endl;
}

void Rectangle::calArea()
{
	cout << " ���� : " << width * height << endl;
}

void Rectangle::resize()
{
	cout << " ������ ������ �����մϴ� " << endl;

	
	cout << " �ʺ�� ���̸� ������� �Է��ϼ��� " << endl;
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
//		cout << "[1]�簢��" << endl;
//		cout << "[2]��" << endl;
//
//		cin >> shape_type;
//
//		if (shape_type == 1 || shape_type == 2)
//		{
//			return shape_type;
//		}
//		else
//		{
//			cout << " �߸� �Է��ϼ̽��ϴ�. " << endl;
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