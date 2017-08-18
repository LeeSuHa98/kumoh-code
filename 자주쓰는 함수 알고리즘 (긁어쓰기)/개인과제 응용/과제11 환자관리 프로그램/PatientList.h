#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_PATIENT = 100;
const int NOT_FOUND = -1;
enum Menus {CHECK_IN = 1, CHECK_OUT, QUERY, EXIT};
enum ChoiceMenus {YES = 1, NO};

typedef struct Patient
{
	int id; // ȯ�ڹ�ȣ
	string name; // ����
	string sex; // ����
	int birth; // ����
	string phone_number; // �޴�����ȣ
	string ad_date; // �Կ���
	string disease; // ����
	string room; // ����
	string doctor; // ��ġ��
	string nurse; // ��簣ȣ��
	string leave_date; // �����

	Patient() {}
	Patient(int id, string name, string sex, int birth, string phone_number, string ad_date, string disease, string room, string doctor, string nurse, string leave_date) // load ������
	{
		this->id = id;
		this->name = name;
		this->sex = sex;
		this->birth = birth;
		this->phone_number = phone_number;
		this->ad_date = ad_date;
		this->disease = disease;
		this->room = room;
		this->doctor = doctor;
		this->nurse = nurse;
		this->leave_date = leave_date;
	}
	~Patient() {}
}Patient;

class PatientList
{
private:
	Patient patient_list[MAX_PATIENT]; // ȯ�ڸ��
	int count;
public:
	PatientList() { count = 0; }
	~PatientList() {}

	Patient getPatientList(int index) { return patient_list[index]; }
	int getCount() { return count; }
	
	int findPatient(int id); // ȯ�� �˻�
	int findLeaveDate(string leave_date); // ȯ�� ����� �˻�
	void insertPatient(Patient& p); // ȯ�� ��� ����
	void deletePatient(int index); // ȯ�� ��� ����
	void updatePatient(int index, Patient p); // ȯ�� ��� ����
	void setPatient(int index,string room, string doctor,string nurse); // ���� ���� ����
};