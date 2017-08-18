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

	cout << " x ��ǥ : ";
	cin >> centerX;
	cout << " y ��ǥ : ";
	cin >> centerY;
	cout << " ������ : ";
	cin >> radius;
	cout << endl;

	Circle* c = new Circle(centerX, centerY, radius);

	s_list.insertShape(c);
	s_list.plusCount();

	return c;
}

void Circle::loadCircle(string fileName, ShapeList& s_list) // ���� �б��
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int centerX;
	int centerY;
	int radius;

	while (!fin.eof()) // ������ ���� �������� �ʾҴٸ� ��� �ݺ�
	{
		fin >> centerX >> centerY >> radius; // ������ ���� ����
		Circle* c = new Circle(centerX, centerY, radius); // Student �ӽ� ��ü ����
		s_list.insertShape(c);
		s_list.plusCount();
	}

	fin.close();
}

void Circle::saveCircle(string fileName, ShapeList& s_list) // ���� �����
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
	cout << "[2] �� -> �߽� : (" << centerX << ", " << centerY << ")" << " ������ : " << radius;
	calArea();
	cout << endl;
}

void Circle::calArea()
{
	cout << " ���� : " << radius * radius * 3.14 << endl;
}

void Circle::resize()
{
	cout << " ������ ������ �����մϴ� " << endl;


	cout << " ������ �������� �Է��ϼ��� " << endl;

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