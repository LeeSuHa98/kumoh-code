#pragma once
#include "PatientList.h"
#include "IOHandler.h"
#include "FileHandler.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	void admissionPatient(PatientList& p_list); // 입원
	void leavePatient(PatientList& p_list); // 퇴원
	void displayPatient(PatientList p_list); // 자료조회
};