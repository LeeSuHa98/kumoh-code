#pragma once
#include "PersonList.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	// 학생 등록
	void registerPerson(PersonList& p_list);
	// 학생 삭제
	void unregisterPerson(PersonList& p_list);
	// 학생 출력
	void displayPerson(PersonList p_list);
};