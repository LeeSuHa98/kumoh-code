#include "ioHandler.h"

int ioHandler::getMenu()
{
	int menu;

	while (1) 
	{
		cout << endl << "1. �Կ�";
		cout << endl << "2. ���";
		cout << endl << "3. �����̵�";
		cout << endl << "9. �ڷ� ��ȸ";
		cout << endl << "10. ����";

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
		cout << endl << "1. ȯ�� �� ����";
		cout << endl << "2. ��ü ȯ�� ���";
		cout << endl << "3. ���� ���� ���";
		cout << endl << "4. ���Ǻ� ȯ�� ���";
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
	cout << "�ű� ȯ�ڿ� ���� �ڷ� �Է�" << endl;
	p.patient_id = p_list.findMaxPatientId(today.substr(0, 4));
	cout << endl << "ȯ�ڹ�ȣ: " << p.patient_id;
	putNewLine();
	cout << endl << "����: ";
	cin >> p.name;
	cout << endl << "����(M: ���� / F: ����) : ";
	cin >> p.sex;
	cout << endl << "�������(yyyymmdd) : ";
	cin >> p.birth_date;
	cout << endl << "�޴���ȭ��ȣ: ";
	cin >> p.phone_no;
	p.entering_date = getCurrentDate();
	putNewLine();
	cout << endl << "�Կ���(yyyymmdd) : " << p.entering_date;
	//cout << endl << "�Կ���(yyyymmdd) : ";
	//cin >> p.entering_date;
	p.entering_time = getCurrentTime();
	putNewLine();
	cout << endl << "�Կ��ð�(hhmm) : " << p.entering_time;
	//cout << endl << "�Կ��ð�(hhmm) : ";
	//cin >> p.entering_time;
	putNewLine();
	cout << endl << "����: ";
	cin >> p.disease;
	cout << endl << "����: ";
	cin >> p.room_no;
	cout << endl << "��ġ��: ";
	cin >> p.doctor_assigned;
	cout << endl << "��� ��ȣ�� : ";
	cin >> p.nurse_assigned;
	p.leaving_date = "xxxx0101";
	p.leaving_time = "xxxx";
	return p;
}

void ioHandler::putPatient(Patient p)
{
	cout << endl << endl << "[ȯ�ڿ� ���� �⺻�ڷ�]";
	cout << endl << "ȯ�ڹ�ȣ: " << p.patient_id;
	cout << endl << "����: " << p.name;
	cout << endl << "����: " << p.sex;
	cout << endl << "�������: " << p.birth_date.substr(0, 4) << "�� "
		<< p.birth_date.substr(4, 2) << "�� " << p.birth_date.substr(6, 2) << "�� ";
	cout << endl << "�޴���ȭ��ȣ: " << p.phone_no;
	cout << endl << "�Կ���: " << p.entering_date.substr(0, 4) << "�� "
		<< p.entering_date.substr(4, 2) << "�� " << p.entering_date.substr(6, 2) << "�� ";
	cout << endl << "�Կ��ð�: " << p.entering_time.substr(0, 2) << "�� " << p.entering_time.substr(2, 4) << "�� ";
	cout << endl << "����: " << p.disease;
	cout << endl << "���� ��ȣ : " << p.room_no.substr(0, 1) << "�� " << p.room_no.substr(1, 3);
	cout << endl << "��ġ��: " << p.doctor_assigned;
	cout << endl << "��� ��ȣ�� : " << p.nurse_assigned;
	cout << endl << "�����: " << p.leaving_date.substr(0, 4) << "�� "
		<< p.leaving_date.substr(4, 2) << "�� " << p.leaving_date.substr(6, 2) << "�� ";
	cout << endl << "����ð�: " << p.leaving_time.substr(0, 2) << "�� " << p.entering_time.substr(2, 4) << "�� ";
}

// �Կ� ���̰ų� �Կ��� ���� �ִ� ȯ���� ȯ�� ��ȣ�� �Է� �޴´�. 
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
	cout << "�ű� ���ǿ� ���� �ڷ� �Է�" << endl;
	r.room_no = p.room_no;
	cout << endl << "���ǹ�ȣ: " << r.room_no;
	cout << endl << "��������(1: 1�ν�, 2: 2�ν�, 3: 3�ν�, x: ���ν�): ";
	cin >> r.room_type;
	r.sex = p.sex;
	cout << endl << "����(M: ������ ���� / F: ������ ����) : " << r.sex;
	cout << endl << "���밡���ο� : " << r.capacity;
	cout << endl << "�����ο� : " << r.p_count;
	
	return r;
}

void ioHandler::putRoom(Room r)
{
	cout << endl << endl << "[���ǿ� ���� �⺻�ڷ�]";
	cout << endl << "���� ��ȣ : " << r.room_no.substr(0, 1) << "�� " << r.room_no.substr(1, 3);
	cout << endl << "��������: " << r.room_type;
	cout << endl << "����: " << r.sex;
	cout << endl << "���밡���ο� : " << r.capacity;
	cout << endl << "�����ο� : " << r.p_count;
}

string ioHandler::getRoomNo(RoomList& r_list)
{
	string r_no;

	while (1)
	{
		putNewLine();
		cout << "���ǹ�ȣ: ";
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
	cout << "���� ȯ�ڿ� ���� �ڷ� �Է�" << endl;
	rh.patient_id = p.patient_id;
	cout << endl << "ȯ�ڹ�ȣ: " << rh.patient_id;
	rh.change_date = getCurrentDate();
	cout << endl << "������: " << rh.change_date;
	rh.room_no = p.room_no;
	cout << endl << "������ ����: " << rh.room_no;
	return rh;
}

void ioHandler::putRoomHistory(RoomHistory rh)
{
	cout << endl << endl << "[���� ȯ�ڿ� ���� �⺻�ڷ�]";
	cout << endl << "ȯ�ڹ�ȣ: " << rh.patient_id;
	cout << endl << "������: " << rh.change_date.substr(0, 4) << "�� "
		<< rh.change_date.substr(4, 2) << "�� " << rh.change_date.substr(6, 2) << "�� ";

	cout << endl << "������ ����: " << rh.room_no;
}

string ioHandler::getCurrentDate()	// returns ��yyyymmdd��of local time
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

string ioHandler::getCurrentTime()	// returns ��hhmm��of local time
{
	time_t tp;
	tp = time(NULL);
	string date;

	struct tm *current = localtime(&tp);
	int hour = current->tm_hour + 1900;
	int minute = current->tm_min % 60;
	return to_string(hour + minute);
}

string ioHandler::getDate()		// returns ��yyyymmdd��
{
	string year, month, day;
	cout << "�⵵(4�ڸ�) : ";
	cin >> year;
	cout << "��(2�ڸ�) : ";
	cin >> month;
	cout << "��(2�ڸ�) : ";
	cin >> day;
	return year + month + day;
}

string ioHandler::getTime()		// returns ��hhmm��
{
	string hour, minute;
	cout << "��(hh) : ";
	cin >> hour;
	cout << "��(mm) : ";
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