#pragma once
#include "PersonList.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	// �л� ���
	void registerPerson(PersonList& p_list);
	// �л� ����
	void unregisterPerson(PersonList& p_list);
	// �л� ���
	void displayPerson(PersonList p_list);
};