#pragma once
#include "PatientList.h"

class IOHandler
{
public:
	IOHandler() {}
	~IOHandler() {}

	int getMenu(); // 메인메뉴
	int getChoiceMenu(); // Yes or No
	char getPatientInfo(); // 환자 상세 내역 정보

	Patient getPatient(char patient_info);
	void putPatient(Patient p);

	string getString(string msg);
	int getInteger(string msg);

	void putNewLine() { cout << endl; }
	void putString(string msg) { cout << endl << msg.c_str(); }
};