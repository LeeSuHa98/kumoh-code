#pragma once
#include "PatientList.h"
#include "IOHandler.h"
#include "FileHandler.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	void admissionPatient(PatientList& p_list); // �Կ�
	void leavePatient(PatientList& p_list); // ���
	void displayPatient(PatientList p_list); // �ڷ���ȸ
};