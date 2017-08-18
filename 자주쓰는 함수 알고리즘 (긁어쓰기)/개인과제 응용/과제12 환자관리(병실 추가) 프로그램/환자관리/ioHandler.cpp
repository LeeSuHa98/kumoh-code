#include "ioHandler.h"

int ioHandler::getMenu()
{
	int menu;

	while (1) 
	{
		cout << endl << "1. 입원";
		cout << endl << "2. 퇴원";
		cout << endl << "3. 병실이동";
		cout << endl << "9. 자료 조회";
		cout << endl << "10. 종료";

		cout << endl << "select -> ";
		cin >> menu;
		if (menu >= CHECK_IN && menu <= CHANGE_ROOM
		|| menu >= QUERY && menu <= EXIT)
		{
			return menu;
		}
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
		cout << endl << "select -> ";
		cin >> q_menu;
		if (q_menu >= 1 && q_menu <= 4)
		{
			return q_menu;
		}
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
	cout << endl << "병실 번호 : " << p.room_no.substr(0, 1) << "층 " << p.room_no.substr(1, 3);
	cout << endl << "주치의: " << p.doctor_assigned;
	cout << endl << "담당 간호사 : " << p.nurse_assigned;
	cout << endl << "퇴원일: " << p.leaving_date.substr(0, 4) << "년 "
		<< p.leaving_date.substr(4, 2) << "월 " << p.leaving_date.substr(6, 2) << "일 ";
	cout << endl << "퇴원시간: " << p.leaving_time.substr(0, 2) << "시 " << p.entering_time.substr(2, 4) << "분 ";
}

// 입원 중이거나 입원한 적이 있는 환자의 환자 번호를 입력 받는다. 
string ioHandler::getPatientId(PatientList& p_list, string msg)
{
	string p_id;

	while (1) 
	{
		p_id = getString(msg);
		Patient p = p_list.searchPatient(p_id);
		if (p.patient_id != "")	// if valid patient id
		{
			break;
		}
		putString("", "Invalid patient id!!, Retry!!");
	}
	return p_id;
}

Room ioHandler::getRoom(RoomList& r_list)
{
	Patient p;
	Room r;
	cout << "신규 병실에 대한 자료 입력" << endl;
	r.room_no = p.room_no;
	cout << endl << "병실번호: " << r.room_no;
	cout << endl << "병실종류(1: 1인실, 2: 2인실, 3: 3인실, x: 다인실): ";
	cin >> r.room_type;
	r.sex = p.sex;
	cout << endl << "성별(M: 남성용 병실 / F: 여성용 병실) : " << r.sex;
	cout << endl << "수용가능인원 : " << r.capacity;
	cout << endl << "현재인원 : " << r.p_count;
	
	return r;
}

void ioHandler::putRoom(Room r)
{
	cout << endl << endl << "[병실에 대한 기본자료]";
	cout << endl << "병실 번호 : " << r.room_no.substr(0, 1) << "층 " << r.room_no.substr(1, 3);
	cout << endl << "병실종류: " << r.room_type;
	cout << endl << "성별: " << r.sex;
	cout << endl << "수용가능인원 : " << r.capacity;
	cout << endl << "현재인원 : " << r.p_count;
}

string ioHandler::getRoomNo(RoomList& r_list)
{
	string r_no;

	while (1)
	{
		putNewLine();
		cout << "병실번호: ";
		cin >> r_no;
		Room r = r_list.searchRoom(r_no);
		if ((r.room_no != "") && (r.capacity > r.p_count))
		{
			break;
		}
		putString("", "Invalid patient id!!, Retry!!");
	}

	return r_no;
}

RoomHistory ioHandler::getRoomHistory(Patient& p)
{
	RoomHistory rh;
	cout << "병실 환자에 대한 자료 입력" << endl;
	rh.patient_id = p.patient_id;
	cout << endl << "환자번호: " << rh.patient_id;
	rh.change_date = getCurrentDate();
	cout << endl << "변경일: " << rh.change_date;
	rh.room_no = p.room_no;
	cout << endl << "변경전 병실: " << rh.room_no;
	return rh;
}

void ioHandler::putRoomHistory(RoomHistory rh)
{
	cout << endl << endl << "[병실 환자에 대한 기본자료]";
	cout << endl << "환자번호: " << rh.patient_id;
	cout << endl << "변경일: " << rh.change_date.substr(0, 4) << "년 "
		<< rh.change_date.substr(4, 2) << "월 " << rh.change_date.substr(6, 2) << "일 ";

	cout << endl << "변경후 병실: " << rh.room_no;
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
		date = to_string(year) + ("0"+to_string(month)) + to_string(day);
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