#pragma once
#include "PatientList.h"

class IOHandler
{
public:
	IOHandler() {}
	~IOHandler() {}

	int getMenu(); // ���θ޴�
	int getChoiceMenu(); // Yes or No
	char getPatientInfo(); // ȯ�� �� ���� ����

	Patient getPatient(char patient_info);
	void putPatient(Patient p);

	string getString(string msg);
	int getInteger(string msg);

	void putNewLine() { cout << endl; }
	void putString(string msg) { cout << endl << msg.c_str(); }
};