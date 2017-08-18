#include "PersonList.h"

int PersonList::findPerson(string name)
{
	// �л� ���� �˻�
	for (int i = 0; i < count; i++)
	{
		if (name == person_list[i].getName()) // id�� ����� ��(�Է� ��) == ��µ� ��
		{
			return i; // �˻��ؼ� ã�� ���� ��ȯ
		}
	}
	return NOT_FOUND; // ��ȯ�� : �ش� �л��� ������ �ε���, ������ NOT_FOUND�� ��ȯ
}

void PersonList::inputPerson(Person p)
{
	if (count >= MAX_PERSON)
	{
		cout << "�л� ���� " << MAX_PERSON << "���� �ʰ��� �� �����ϴ�!!" << endl;
		return;
	}

	person_list[count] = p; // �������� ������ �迭�� ������ �� �ְ� ��ü ����

	count++; // ���� ������ ������ �� �ְ� ����
}

void PersonList::deletePerson(int index)
{
	person_list[index] = person_list[count - 1]; // ���� ������ ���� ������ ���� �����ش�

	count--; // ���� ������ ������ �� �ְ� ������ ������ ����ֱ� ������ �Էµ� ��������� �����ֱ� ���� ����
}