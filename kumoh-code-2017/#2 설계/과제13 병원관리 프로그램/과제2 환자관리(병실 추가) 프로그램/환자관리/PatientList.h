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
	string patient_id;		// 환자번호=년도(4)+일련번호(4)
	string name;			// 성명
	char sex;				// 성별 -> M: 남성, F: 여성
	string birth_date;		// 생년월일=년도(4)+월(2)+일(2)
	string phone_no;		// 휴대전화번호
	string entering_date;	// 입원일=년도(4)+월(2)+일(2)
	string entering_time;   // 입원시간=시간(2)+분(2)
	string disease;			// 병명
	string room_no;			// 병실
	string doctor_assigned;	// 주치의
	string nurse_assigned;	// 담당 간호사
	string leaving_date;	// 퇴원일. 초기 값=xxxx0101
	string leaving_time;	// 퇴원시간. 초기 값=xx00
} Patient;

// Class Definitions
class PatientList 
{
private:
	Patient patient_list[MAX_PATIENTS];
	int count;
	int findIndex(Patient p);	// find index for‘p’
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