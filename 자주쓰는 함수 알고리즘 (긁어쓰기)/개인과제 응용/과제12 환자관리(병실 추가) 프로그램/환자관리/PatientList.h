#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;

// Symbolic constants & Enumeration types
const int MAX_PATIENTS = 200;
const int MAX_ROOMS = 30;
const int NOT_FOUND = -1;

enum Menu { CHECK_IN = 1, CHECK_OUT, CHANGE_ROOM, QUERY = 9, EXIT };

// Structure Definitions
typedef struct 
{
	string patient_id;		// ȯ�ڹ�ȣ=�⵵(4)+�Ϸù�ȣ(4)
	string name;			// ����
	char sex;				// ���� -> M: ����, F: ����
	string birth_date;		// �������=�⵵(4)+��(2)+��(2)
	string phone_no;		// �޴���ȭ��ȣ
	string entering_date;	// �Կ���=�⵵(4)+��(2)+��(2)
	string entering_time;   // �Կ��ð�=�ð�(2)+��(2)
	string disease;			// ����
	string room_no;			// ����
	string doctor_assigned;	// ��ġ��
	string nurse_assigned;	// ��� ��ȣ��
	string leaving_date;	// �����. �ʱ� ��=xxxx0101
	string leaving_time;	// ����ð�. �ʱ� ��=xx00
} Patient;

// Class Definitions
class PatientList 
{
private:
	Patient patient_list[MAX_PATIENTS];
	int count;
	int findIndex(Patient p);	// find index for��p��
public:
	PatientList() { count = 0; }
	~PatientList() { }

	Patient getPatientList(int index) { return patient_list[index]; }
	int getCount() { return count; }

	void insertPatient(Patient p);
	void deletePatient(Patient p);
	string findMaxPatientId(string year);
	Patient searchPatient(string patient_id);
	void showPatientList();
};