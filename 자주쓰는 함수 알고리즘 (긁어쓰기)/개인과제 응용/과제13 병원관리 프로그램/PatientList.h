#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
using namespace std;

// Symbolic constants & Enumeration types
const int MAX_PATIENTS = 200;
const int MAX_ROOMS = 50;
const int MAX_ROOM_CHANGES = 100;
const int MAX_STAFFS = 200;
const int MAX_STAFF_ASSIGN = 200;
const int MAX_CHECK_SHEET = 200;

const int NOT_FOUND = -1;
enum Menu { CHECK_IN = 1, CHECK_OUT, CHANGE_ROOM, ASSIGN_STAFF, REGISTER_CHECK_SHEET, QUERY = 9, EXIT };

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
	int room_no;			// ����
	string doctor_assigned;	// ��ġ��
	string nurse_assigned;	// ��� ��ȣ��
	string leaving_date;	// �����. �ʱ� ��=xxxx0101
	string leaving_time;	// ����ð�. �ʱ� ��=xx00
} Patient;

typedef struct
{
	int room_no;	// ���ǹ�ȣ=����ȣ(1)+�Ϸù�ȣ(2)
	char room_type;	// �������� -> 1: 1�ν�, 2: 2�ν�, 3: 3�ν�, x: ���ν�
	char sex;		// ���� -> M: ������ ����, F: ������ ����
	int capacity;	// ���밡�� �ο�
	int p_count;	// ���� �ο�
} Room;

typedef struct 
{
	string patient_id;	// ȯ�ڹ�ȣ
	string change_date;	// ������
	int before_room;	// ���� ���� ���ǹ�ȣ
	int after_room;	// ���� ���� ���ǹ�ȣ
} RoomChange;

typedef struct
{
	string staff_id;	// ������ȣ
	string staff_sep;	// ��������
	string name;		// ����
	string birth_date;	// �������
	string phone_no;	// �޴���ȭ��ȣ
	string join_date;	// �Ի���
	string resign_date;	// �����
} Staff;

typedef struct
{
	string patient_id;	// ȯ�ڹ�ȣ
	string change_date;	// ������
	string before_staff;// ������ ����
	string after_staff;	// ������ ����
} StaffAssign;

typedef struct
{
	string check_sheet_no;	// ����� ��ȣ
	string patient_id;		// ȯ�ڹ�ȣ
	string check_date;		// �˻���
	string nurse_id;		// �˻���
	string blood_pressure;	// ����
	string temperature;		// ü��
	string blood_sugar;		// ����
} CheckSheet;

// Class Definitions
class PatientList 
{
private:
	Patient patient_list[MAX_PATIENTS];
	int count;

	int findIndex(Patient p);	// find index for��p��
public:
	PatientList() { }
	~PatientList() { }

	Patient getPatient(int index) { return patient_list[index]; }
	int getCount() { return count; }

	void insertPatient(Patient p);
	void deletePatient(Patient p);
	string findMaxPatientId(string year);
	Patient searchPatient(string patient_id);
	PatientList searchPatientsInRoom(int room_no);
	PatientList searchPatientInStaff(string s_id);
	void showPatientList();
};