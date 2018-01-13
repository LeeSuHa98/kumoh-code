#include "PersonList.h"

int PersonList::findPerson(string name)
{
	for (int i = 0; i < count; i++)
	{
		if (name == person_list[i].getName())
		{
			return i;
		}
	}
	return NOT_FOUND; // ��ȯ�� : �ش� �л��� ������ �ε���, ������ NOT_FOUND�� ��ȯ
}

void PersonList::inputPerson()
{
	cout << " �л��� ������ ����մϴ� " << endl;

	string name;
	int korean;
	int english;
	int math;

	cout << " �̸� : ";
	cin >> name;
	cout << " ���� ���� : ";
	cin >> korean;
	cout << " ���� ���� : ";
	cin >> english;
	cout << " ���� ���� : ";
	cin >> math;

	Person p(name, korean, english, math);

	// ����ó��
	if (count >= MAX_PERSON)
	{
		cout << "�л� ���� " << MAX_PERSON << "���� �ʰ��� �� �����ϴ�!!" << endl;
		return;
	}
	else if (findPerson(name) == NOT_FOUND)
	{
		person_list[count] = p;
		count++;
	}
	else
	{
		cout << " ������ �̸��Դϴ�. �ٽ� �Է����ֽʽÿ�. " << endl;
	}
}

void PersonList::deletePerson()
{
	cout << " �л��� ������ �����մϴ� " << endl;

	string name;

	cout << " ������ �л��� �̸��� �Է��Ͻÿ� : ";
	cin >> name;

	for (int i = findPerson(name); i < count; i++)
	{
		person_list[i + 1];
	}

	count--;
}

void PersonList::displayPerson()
{
	cout << " �л��� ������ ����մϴ� " << endl;

	for (int i = 0; i < count; i++)
	{
		cout << " �̸� : " << person_list[i].getName() << endl;
		cout << " ���� ���� : " << person_list[i].getKorean() << endl;
		cout << " ���� ���� : " << person_list[i].getEnglish() << endl;
		cout << " ���� ���� : " << person_list[i].getMath() << endl;
		cout << " �л� ��� ���� : " << person_list[i].getAverage() << endl;
		cout << " �л� ��� : " << person_list[i].getGrade() << endl;
		cout << endl;
	}
}