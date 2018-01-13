#pragma once
#include "Person.h"

const int MAX_PERSON = 2;
const int NOT_FOUND = -1;
enum Menus { REGISTER = 1, UNREGISTER, DISPLAY, EXIT };

class PersonList
{
private:
	Person person_list[MAX_PERSON];
	int count;
public:
	PersonList() { count = 0; }
	~PersonList() {}

	int findPerson(string name); // �˻�
	void inputPerson(); // ���
	void deletePerson(); // ����
	void displayPerson(); // ���
};