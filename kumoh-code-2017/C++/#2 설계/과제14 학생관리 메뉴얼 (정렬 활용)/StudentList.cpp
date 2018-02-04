#include "StudentList.h"

int StudentList::findStudent(int id)
{
	for (int i = 0; i < count; i++)
	{
		if (id == studentList[i].getId())	// ��ü �迭 ���� �л�id key�� �˻�
		{
			return i;
		}
	}
	cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻÿ�." << endl;
}

void StudentList::insertStudent(Student s)
{
	studentList[count] = s;	// ������ ��ü�� �迭�� ����
	count++;	// �迭�� ���� �������� �̵�
}

void StudentList::registerStudentRecord()
{
	int id;
	string name;
	int kor;
	int math;
	int eng;

	while (1)
	{
		if (isFlag() == false)
		{
			break;
		}
		else
		{
			cout << "�л��� ���������� �Է��Ͻÿ�" << endl;
			cout << "�й� : ";
			cin >> id;
			cout << "�̸� : ";
			cin >> name;
			cout << "�л��� ������ �Է��Ͻÿ�" << endl;
			cout << "���� : ";
			cin >> kor;
			cout << "���� : ";
			cin >> math;
			cout << "���� : ";
			cin >> eng;

			Student s(id, name, kor, math, eng);	// �л� Entity ������

			insertStudent(s);	// �л� Entity�� ������ List ��ü �迭�� �Ҵ�;
		}

		cout << "�й�, �̸�, ���� �Է� �� �� �Է�?(y/n)" << endl;

		char select;
		cin >> select;

		switch (select)
		{
		case 'y':
		case 'Y':
			flag = true;
			break;
		case 'n':
		case 'N':
			flag = false;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}

	flag = true;	// �޴����� ������ ���� �ʱ�ȭ
}

void StudentList::averageStudentRecord()
{
	for (int i = 0; i < count; i++)
	{
		cout << "�й� : " << studentList[i].getId() << endl;
		cout << "�̸� : " << studentList[i].getName() << endl;
		cout << "��� ���� : " << studentList[i].getAvgRecord() << endl;
		cout << endl;
	}
}

void StudentList::sortByStudentRecordWithId()
{
	for (int i = 0; i < count - 1; i++)   // ��������
	{
		int id1 = studentList[i].getId();	// ��ü �迭�� ���� ù��° id�� ������ �Ҵ�
		for (int j = i + 1; j < count; j++)
		{
			int id2 = studentList[j].getId();	//	��ü �迭�� ���� �ι�° id�� ������ �Ҵ�
			if (id1 >= id2)	// �Ҵ�� �������� ��
			{	// Swap
				Student temp;
				temp = studentList[i];
				studentList[i] = studentList[j];
				studentList[j] = temp;
			}
		}
	}
}

void StudentList::sortByStudentRecordWithGrade()
{
	for (int i = 0; i < count - 1; i++)   // ��������
	{
		int avg1 = studentList[i].getAvgRecord();	// ��ü �迭�� ���� ù��° id�� ������ �Ҵ�
		for (int j = i + 1; j < count; j++)
		{
			int avg2 = studentList[j].getAvgRecord();	//	��ü �迭�� ���� �ι�° id�� ������ �Ҵ�
			if (avg1 <= avg2)	// �Ҵ�� �������� ��
			{	// Swap
				Student temp;
				temp = studentList[i];
				studentList[i] = studentList[j];
				studentList[j] = temp;
			}
		}
	}
}

void StudentList::searchByStudentId()
{
	int id;

	cout << "�л��� �й��� �˻��մϴ�." << endl;
	
	cout << "�˻��� �л��� �й��� �Է��Ͻÿ� : ";
	cin >> id;

	selectDisplayStudent(findStudent(id));	// Ž���� �л��� ���
}

void StudentList::selectDisplayStudent(int index)
{	// ���ڷ� �Ѱ��� �л��� ������ ������ ���
	cout << "�й� : " << studentList[index].getId() << endl;
	cout << "�̸� : " << studentList[index].getName() << endl;
	cout << "���� ���� : " << studentList[index].getKor() << endl;
	cout << "���� ���� : " << studentList[index].getMath() << endl;
	cout << "���� ���� : " << studentList[index].getEng() << endl;
	cout << "��� ���� : " << studentList[index].getAvgRecord() << endl;
}

void StudentList::allDisplayStudent()
{
	for (int i = 0; i < count; i++)	// count�� ��� �л��� ������ ���
	{
		cout << "�й� : " << studentList[i].getId() << endl;
		cout << "�̸� : " << studentList[i].getName() << endl;
		cout << "���� ���� : " << studentList[i].getKor() << endl;
		cout << "���� ���� : " << studentList[i].getMath() << endl;
		cout << "���� ���� : " << studentList[i].getEng() << endl;
		cout << "��� ���� : " << studentList[i].getAvgRecord() << endl;
	}
}