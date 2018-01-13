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
	int id; // 환자번호
	string name; // 성명
	string sex; // 성별
	int birth; // 생일
	string phone_number; // 휴대폰번호
	string ad_date; // 입원일
	string disease; // 병명
	string room; // 병실
	string doctor; // 주치의
	string nurse; // 담당간호사
	string leave_date; // 퇴원일

	Patient() {}
	Patient(int id, string name, string sex, int birth, string phone_number, string ad_date, string disease, string room, string doctor, string nurse, string leave_date) // load 생성자
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
	Patient patient_list[MAX_PATIENT]; // 환자명부
	int count;
public:
	PatientList() { count = 0; }
	~PatientList() {}

	Patient getPatientList(int index) { return patient_list[index]; }
	int getCount() { return count; }
	
	int findPatient(int id); // 환자 검색
	int findLeaveDate(string leave_date); // 환자 퇴원일 검색
	void insertPatient(Patient& p); // 환자 명부 삽입
	void deletePatient(int index); // 환자 명부 삭제
	void updatePatient(int index, Patient p); // 환자 명부 갱신
	void setPatient(int index,string room, string doctor,string nurse); // 병원 정보 지정
};