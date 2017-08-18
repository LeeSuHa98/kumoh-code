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
	string patient_id;		// 환자번호=년도(4)+일련번호(4)
	string name;			// 성명
	char sex;				// 성별 -> M: 남성, F: 여성
	string birth_date;		// 생년월일=년도(4)+월(2)+일(2)
	string phone_no;		// 휴대전화번호
	string entering_date;	// 입원일=년도(4)+월(2)+일(2)
	string entering_time;   // 입원시간=시간(2)+분(2)
	string disease;			// 병명
	int room_no;			// 병실
	string doctor_assigned;	// 주치의
	string nurse_assigned;	// 담당 간호사
	string leaving_date;	// 퇴원일. 초기 값=xxxx0101
	string leaving_time;	// 퇴원시간. 초기 값=xx00
} Patient;

typedef struct
{
	int room_no;	// 병실번호=층번호(1)+일련번호(2)
	char room_type;	// 병실종류 -> 1: 1인실, 2: 2인실, 3: 3인실, x: 다인실
	char sex;		// 성별 -> M: 남성용 병실, F: 여성용 병실
	int capacity;	// 수용가능 인원
	int p_count;	// 현재 인원
} Room;

typedef struct 
{
	string patient_id;	// 환자번호
	string change_date;	// 변경일
	int before_room;	// 변경 전의 병실번호
	int after_room;	// 변경 후의 병실번호
} RoomChange;

typedef struct
{
	string staff_id;	// 직원번호
	string staff_sep;	// 직원구분
	string name;		// 성명
	string birth_date;	// 생년월일
	string phone_no;	// 휴대전화번호
	string join_date;	// 입사일
	string resign_date;	// 퇴사일
} Staff;

typedef struct
{
	string patient_id;	// 환자번호
	string change_date;	// 변경일
	string before_staff;// 변경전 직원
	string after_staff;	// 변경후 직원
} StaffAssign;

typedef struct
{
	string check_sheet_no;	// 기록지 번호
	string patient_id;		// 환자번호
	string check_date;		// 검사일
	string nurse_id;		// 검사자
	string blood_pressure;	// 혈압
	string temperature;		// 체온
	string blood_sugar;		// 혈당
} CheckSheet;

// Class Definitions
class PatientList 
{
private:
	Patient patient_list[MAX_PATIENTS];
	int count;

	int findIndex(Patient p);	// find index for‘p’
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