#pragma once
#include "Person.h"

class PersonList
{
private:
	Person* person_list;
	int count;
public:
	PersonList() 
	{
		person_list = new Person[MAX_PERSON];
		count = 0; 
	}
	~PersonList() {}

	Person getPersonList(int index) { return person_list[index]; }
	int getCount() { return count; }
	void plusCount() { count++; }
	void minusCount() { count--; }

	// �л� �˻�
	int findPerson(string name);
	void inputPerson(Person p); // ���
	void deletePerson(int index); // ����
};