#include "ioHandler.h"

int ioHandler::getMenu()
{
	int menu;

	while (1)
	{
		cout << endl;
		cout << endl << "1. 입원";
		cout << endl << "2. 퇴원";
		cout << endl << "3. 병실 이동";
		cout << endl << "4. 의료인(의사, 간호사) 배정";
		cout << endl << "5. 검사기록 등재";
		cout << endl << "9. 자료 조회";
		cout << endl << "10. 종료";

		cout << endl << "select -> ";
		cin >> menu;
		if (menu >= CHECK_IN && menu <= REGISTER_CHECK_SHEET
			|| menu >= QUERY && menu <= EXIT)
			return menu;
		cout << endl << "Invalid Selection!! Retry!!";
	}
}

int ioHandler::getQueryMenu()
{
	int q_menu;

	while (1) 
	{
		cout << endl;
		cout << endl << "1. 환자 상세 내역";
		cout << endl << "2. 전체 환자 명단";
		cout << endl << "3. 가용 병실 목록";
		cout << endl << "4. 병실별 환자 명단";
		cout << endl << "5. 의료인별 담당 환자 명단";

		cout << endl << "select -> ";
		cin >> q_menu;
		if (q_menu >= 1 && q_menu <= 5)
			return q_menu;
		cout << endl << "Invalid Selection!! Retry!!";
	}
}

int ioHandler::getStaffAssignMenu()
{
	int s_menu;

	while (1)
	{
		cout << endl;
		cout << endl << "1. 의료인(직원) 배정";
		cout << endl << "2. 주치의 배정";
		cout << endl << "3. 담당 간호사 배정";

		cout << endl << "select -> ";
		cin >> s_menu;
		if (s_menu >= 1 && s_menu <= 3)
			return s_menu;
		cout << endl << "Invalid Selection!! Retry!!";
	}
}

Patient ioHandler::getPatient(PatientList& p_list)
{
	Patient p;
	string today = getCurrentDate();
	cout << "신규 환자에 대한 자료 입력" << endl;
	p.patient_id = p_list.findMaxPatientId(today.substr(0, 4));
	cout << endl << "환자번호: " << p.patient_id;
	putNewLine();
	cout << endl << "성명: ";
	cin >> p.name;
	cout << endl << "성별(M: 남성 / F: 여성) : ";
	cin >> p.sex;
	cout << endl << "생년월일(yyyymmdd) : ";
	cin >> p.birth_date;
	cout << endl << "휴대전화번호: ";
	cin >> p.phone_no;
	p.entering_date = getCurrentDate();
	putNewLine();
	cout << endl << "입원일(yyyymmdd) : " << p.entering_date;
	//cout << endl << "입원일(yyyymmdd) : ";
	//cin >> p.entering_date;
	p.entering_time = getCurrentTime();
	putNewLine();
	cout << endl << "입원시간(hhmm) : " << p.entering_time;
	//cout << endl << "입원시간(hhmm) : ";
	//cin >> p.entering_time;
	putNewLine();
	cout << endl << "병명: ";
	cin >> p.disease;
	cout << endl << "병실: ";
	cin >> p.room_no;
	cout << endl << "주치의: ";
	cin >> p.doctor_assigned;
	cout << endl << "담당 간호사 : ";
	cin >> p.nurse_assigned;
	p.leaving_date = "xxxx0101";
	p.leaving_time = "xxxx";
	return p;
}

void ioHandler::putPatient(Patient p)
{
	cout << endl << endl << "[환자에 대한 기본자료]";
	cout << endl << "환자번호: " << p.patient_id;
	cout << endl << "성명: " << p.name;
	cout << endl << "성별: " << p.sex;
	cout << endl << "생년월일: " << p.birth_date.substr(0, 4) << "년 "
		<< p.birth_date.substr(4, 2) << "월 " << p.birth_date.substr(6, 2) << "일 ";
	cout << endl << "휴대전화번호: " << p.phone_no;
	cout << endl << "입원일: " << p.entering_date.substr(0, 4) << "년 "
		<< p.entering_date.substr(4, 2) << "월 " << p.entering_date.substr(6, 2) << "일 ";
	cout << endl << "입원시간: " << p.entering_time.substr(0, 2) << "시 " << p.entering_time.substr(2, 4) << "분 ";
	cout << endl << "병명: " << p.disease;
	cout << endl << "병실 번호 : " << p.room_no;
	cout << endl << "주치의: " << p.doctor_assigned;
	cout << endl << "담당 간호사 : " << p.nurse_assigned;
	cout << endl << "퇴원일: " << p.leaving_date.substr(0, 4) << "년 "
		<< p.leaving_date.substr(4, 2) << "월 " << p.leaving_date.substr(6, 2) << "일 ";
	cout << endl << "퇴원시간: " << p.leaving_time.substr(0, 2) << "시 " << p.entering_time.substr(2, 4) << "분 ";
}

RoomChange ioHandler::getRoomChange(PatientList& p_list, RoomList& r_list)
{
	RoomChange rc;
	rc.patient_id = getPatientId(p_list, "병실을 변경할 환자의 번호 : ");
	Patient p = p_list.searchPatient(rc.patient_id);

	rc.change_date = getCurrentDate();
	cout << endl << "변경일(yyyymmdd) : " << rc.change_date;
	//cin >> rc.change_date;

	rc.before_room = p.room_no;
	cout << "변경전 병실 번호 : " << rc.before_room;
	rc.after_room = getRoomNo(r_list);
	return rc;
}

void ioHandler::putRoomChange(RoomChange rc)
{
	cout << endl << "환자번호: " << rc.patient_id;
	cout << endl << "변경일: " << rc.change_date.substr(0, 4) << "년 "
		<< rc.change_date.substr(4, 2) << "월 " << rc.change_date.substr(6, 2) << "일 ";
	cout << endl << "변경 전 병실번호 : " << rc.before_room;
	cout << endl << "변경 후 병실번호 : " << rc.after_room;
}

// 입원 중이거나 입원한 적이 있는 환자의 환자 번호를 입력 받는다. 
string ioHandler::getPatientId(PatientList& p_list, string msg)
{
	string p_id;

	while (1)
	{
		p_id = getString(msg);
		Patient p = p_list.searchPatient(p_id);
		if (p.patient_id != "")	break;		// if valid patient id
		putString("", "Invalid patient id!!, Retry!!");
	}
	return p_id;
}

int ioHandler::getRoomNo(RoomList& r_list)
{
	int r_no;

	while (1)
	{
		r_no = getInteger("병실 번호 : ", 100, 999);
		Room r = r_list.searchRoom(r_no);
		if (r.room_no != NULL) break;			// if valid room no
		putString("", "Invalid room no!!, Retry!!");
	}
	return r_no;
}

void ioHandler::putRoom(Room r)
{
	cout << endl << "병실번호 : " << r.room_no;
	cout << endl << "병실종류 : " << r.room_type;
	cout << endl << "성별 : " << r.sex;
	cout << endl << "수용가능인원 : " << r.capacity;
	cout << endl << "현재인원 : " << r.p_count;
}
// 재직 중이거나 재직한 적이 있는 직원의 직원 번호를 입력 받는다. 
string ioHandler::getStaffId(StaffList& s_list, string msg)
{
	string s_id;

	while (1)
	{
		s_id = getString(msg);
		Staff s = s_list.searchStaff(s_id);
		if (s.staff_id != "")	break;		// if valid patient id
		putString("", "Invalid staff id!!, Retry!!");
	}
	return s_id;
}

Staff ioHandler::getStaff(StaffList& s_list)
{
	Staff s;
	string today = getCurrentDate();
	cout << "신규 직원에 대한 자료 입력" << endl;
	s.staff_id = s_list.findMaxStaffId(today.substr(0, 4));
	cout << endl << "직원번호: " << s.staff_id;
	putNewLine();
	cout << endl << "직원구분: ";
	cin >> s.staff_sep;
	cout << endl << "성명 : ";
	cin >> s.name;
	cout << endl << "생년월일(yyyymmdd) : ";
	cin >> s.birth_date;
	cout << endl << "휴대전화번호: ";
	cin >> s.phone_no;
	s.join_date = getCurrentDate();
	putNewLine();
	cout << endl << "입사일(yyyymmdd) : " << s.join_date;
	s.resign_date = "xxxx0101";
	return s;
}

void ioHandler::putStaff(Staff s)
{
	cout << endl << endl << "[의료진에 대한 기본자료]";
	cout << endl << "직원번호 : " << s.staff_id;
	cout << endl << "직원구분 : " << s.staff_sep;
	cout << endl << "성명 : " << s.name;
	cout << endl << "생년월일 : " << s.birth_date;
	cout << endl << "휴대폰번호 : " << s.phone_no;
	cout << endl << "입사일 : " << s.join_date;
	cout << endl << "퇴사일 : " << s.resign_date;
}

StaffAssign ioHandler::getDoctorAssign(PatientList& p_list, StaffList& s_list)
{
	StaffAssign sa;
	sa.patient_id = getPatientId(p_list, "직원을 변경할 환자의 번호 : ");
	Patient p = p_list.searchPatient(sa.patient_id);

	sa.change_date = getCurrentDate();
	cout << endl << "변경일(yyyymmdd) : " << sa.change_date;

	sa.before_staff = p.doctor_assigned;
	cout << "변경전 주치의 : " << sa.before_staff;
	sa.after_staff = getStaffId(s_list, "변경할 주치의");
	return sa;
}

StaffAssign ioHandler::getNurseAssign(PatientList& p_list, StaffList& s_list)
{
	StaffAssign sa;
	sa.patient_id = getPatientId(p_list, "직원을 변경할 환자의 번호 : ");
	Patient p = p_list.searchPatient(sa.patient_id);

	sa.change_date = getCurrentDate();
	cout << endl << "변경일(yyyymmdd) : " << sa.change_date;

	sa.before_staff = p.nurse_assigned;
	cout << "변경전 담당 간호사 : " << sa.before_staff;
	sa.after_staff = getStaffId(s_list, "");
	return sa;
}

void ioHandler::putStaffAssign(StaffAssign ac)
{
	cout << endl << "환자번호: " << ac.patient_id;
	cout << endl << "변경일: " << ac.change_date.substr(0, 4) << "년 "
		<< ac.change_date.substr(4, 2) << "월 " << ac.change_date.substr(6, 2) << "일 ";
	cout << endl << "변경 전 직원 : " << ac.before_staff;
	cout << endl << "변경 후 직원 : " << ac.after_staff;
}

CheckSheet ioHandler::getCheckSheet(PatientList& p_list, StaffList& s_list, CheckSheetList& cs_list)
{
	CheckSheet cs;

	string today = getCurrentDate();
	cout << endl << endl << "검사 기록에 대한 자료 입력";
	cs.check_sheet_no = cs_list.findMaxCheckSheetNo(today.substr(0, 4));
	cout << endl << "기록지 번호: " << cs.check_sheet_no;
	cs.patient_id = getPatientId(p_list, "환자번호: ");
	cs.check_date = getCurrentDate();
	cout << endl << "검사일: " << cs.check_date << endl;
	cs.nurse_id = getStaffId(s_list, "검사한 간호사의 직원번호: ");
	cout << endl << "혈압: ";
	cin >> cs.blood_pressure;
	cout << endl << "체온: ";
	cin >> cs.temperature;
	cout << endl << "혈당: ";
	cin >> cs.blood_sugar;
	return cs;
}

void ioHandler::putCheckSheet(CheckSheet cs)
{
	cout << endl << "기록지번호 : " << cs.check_sheet_no;
	cout << endl << "환자번호 : " << cs.patient_id;
	cout << endl << "검사일 : " << cs.check_date;
	cout << endl << "검사자 : " << cs.nurse_id;
	cout << endl << "혈압 : " << cs.blood_pressure;
	cout << endl << "체온 : " << cs.temperature;
	cout << endl << "혈당 : " << cs.blood_sugar;
}

string ioHandler::getCurrentDate()	// returns “yyyymmdd”of local time
{
	time_t tp;
	tp = time(NULL);
	string date;

	struct tm *current = localtime(&tp);
	int year = current->tm_year + 1900;
	int month = current->tm_mon + 1;
	int day = current->tm_mday;

	if (month < 10)
	{
		date = to_string(year) + ("0" + to_string(month)) + to_string(day);
	}
	else
	{
		date = to_string(year) + to_string(month) + to_string(day);
	}

	return date;
}

string ioHandler::getCurrentTime()	// returns “hhmm”of local time
{
	time_t tp;
	tp = time(NULL);
	string date;

	struct tm *current = localtime(&tp);
	int hour = current->tm_hour + 1900;
	int minute = current->tm_min % 60;
	return to_string(hour + minute);
}

string ioHandler::getDate()		// returns “yyyymmdd”
{
	string year, month, day;
	cout << "년도(4자리) : ";
	cin >> year;
	cout << "월(2자리) : ";
	cin >> month;
	cout << "일(2자리) : ";
	cin >> day;
	return year + month + day;
}

string ioHandler::getTime()		// returns “hhmm”
{
	string hour, minute;
	cout << "시(hh) : ";
	cin >> hour;
	cout << "분(mm) : ";
	cin >> minute;
	return hour + minute;
}

int ioHandler::getInteger(string msg, int lower, int upper)
{
	int n;
	while (1)
	{
		cout << msg << "(" << lower << " ~ " << upper << ") -> ";
		cin >> n;
		if (n >= lower && n <= upper) return n;
		cout << endl << "Out of Range!!" << "Retry!!";
	}
}

void ioHandler::putInteger(string msg, int n)
{
	cout << msg << n;
}

string ioHandler::getString(string msg)
{
	string s;
	cout << msg;
	cin >> s;
	return s;
}

void ioHandler::putString(string msg, string s)
{
	cout << msg << s;
}