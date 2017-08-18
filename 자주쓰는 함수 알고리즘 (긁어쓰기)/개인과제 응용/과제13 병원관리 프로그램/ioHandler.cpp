#include "ioHandler.h"

int ioHandler::getMenu()
{
	int menu;

	while (1)
	{
		cout << endl;
		cout << endl << "1. �Կ�";
		cout << endl << "2. ���";
		cout << endl << "3. ���� �̵�";
		cout << endl << "4. �Ƿ���(�ǻ�, ��ȣ��) ����";
		cout << endl << "5. �˻��� ����";
		cout << endl << "9. �ڷ� ��ȸ";
		cout << endl << "10. ����";

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
		cout << endl << "1. ȯ�� �� ����";
		cout << endl << "2. ��ü ȯ�� ���";
		cout << endl << "3. ���� ���� ���";
		cout << endl << "4. ���Ǻ� ȯ�� ���";
		cout << endl << "5. �Ƿ��κ� ��� ȯ�� ���";

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
		cout << endl << "1. �Ƿ���(����) ����";
		cout << endl << "2. ��ġ�� ����";
		cout << endl << "3. ��� ��ȣ�� ����";

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
	cout << endl << "���� ��ȣ : " << p.room_no;
	cout << endl << "��ġ��: " << p.doctor_assigned;
	cout << endl << "��� ��ȣ�� : " << p.nurse_assigned;
	cout << endl << "�����: " << p.leaving_date.substr(0, 4) << "�� "
		<< p.leaving_date.substr(4, 2) << "�� " << p.leaving_date.substr(6, 2) << "�� ";
	cout << endl << "����ð�: " << p.leaving_time.substr(0, 2) << "�� " << p.entering_time.substr(2, 4) << "�� ";
}

RoomChange ioHandler::getRoomChange(PatientList& p_list, RoomList& r_list)
{
	RoomChange rc;
	rc.patient_id = getPatientId(p_list, "������ ������ ȯ���� ��ȣ : ");
	Patient p = p_list.searchPatient(rc.patient_id);

	rc.change_date = getCurrentDate();
	cout << endl << "������(yyyymmdd) : " << rc.change_date;
	//cin >> rc.change_date;

	rc.before_room = p.room_no;
	cout << "������ ���� ��ȣ : " << rc.before_room;
	rc.after_room = getRoomNo(r_list);
	return rc;
}

void ioHandler::putRoomChange(RoomChange rc)
{
	cout << endl << "ȯ�ڹ�ȣ: " << rc.patient_id;
	cout << endl << "������: " << rc.change_date.substr(0, 4) << "�� "
		<< rc.change_date.substr(4, 2) << "�� " << rc.change_date.substr(6, 2) << "�� ";
	cout << endl << "���� �� ���ǹ�ȣ : " << rc.before_room;
	cout << endl << "���� �� ���ǹ�ȣ : " << rc.after_room;
}

// �Կ� ���̰ų� �Կ��� ���� �ִ� ȯ���� ȯ�� ��ȣ�� �Է� �޴´�. 
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
		r_no = getInteger("���� ��ȣ : ", 100, 999);
		Room r = r_list.searchRoom(r_no);
		if (r.room_no != NULL) break;			// if valid room no
		putString("", "Invalid room no!!, Retry!!");
	}
	return r_no;
}

void ioHandler::putRoom(Room r)
{
	cout << endl << "���ǹ�ȣ : " << r.room_no;
	cout << endl << "�������� : " << r.room_type;
	cout << endl << "���� : " << r.sex;
	cout << endl << "���밡���ο� : " << r.capacity;
	cout << endl << "�����ο� : " << r.p_count;
}
// ���� ���̰ų� ������ ���� �ִ� ������ ���� ��ȣ�� �Է� �޴´�. 
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
	cout << "�ű� ������ ���� �ڷ� �Է�" << endl;
	s.staff_id = s_list.findMaxStaffId(today.substr(0, 4));
	cout << endl << "������ȣ: " << s.staff_id;
	putNewLine();
	cout << endl << "��������: ";
	cin >> s.staff_sep;
	cout << endl << "���� : ";
	cin >> s.name;
	cout << endl << "�������(yyyymmdd) : ";
	cin >> s.birth_date;
	cout << endl << "�޴���ȭ��ȣ: ";
	cin >> s.phone_no;
	s.join_date = getCurrentDate();
	putNewLine();
	cout << endl << "�Ի���(yyyymmdd) : " << s.join_date;
	s.resign_date = "xxxx0101";
	return s;
}

void ioHandler::putStaff(Staff s)
{
	cout << endl << endl << "[�Ƿ����� ���� �⺻�ڷ�]";
	cout << endl << "������ȣ : " << s.staff_id;
	cout << endl << "�������� : " << s.staff_sep;
	cout << endl << "���� : " << s.name;
	cout << endl << "������� : " << s.birth_date;
	cout << endl << "�޴�����ȣ : " << s.phone_no;
	cout << endl << "�Ի��� : " << s.join_date;
	cout << endl << "����� : " << s.resign_date;
}

StaffAssign ioHandler::getDoctorAssign(PatientList& p_list, StaffList& s_list)
{
	StaffAssign sa;
	sa.patient_id = getPatientId(p_list, "������ ������ ȯ���� ��ȣ : ");
	Patient p = p_list.searchPatient(sa.patient_id);

	sa.change_date = getCurrentDate();
	cout << endl << "������(yyyymmdd) : " << sa.change_date;

	sa.before_staff = p.doctor_assigned;
	cout << "������ ��ġ�� : " << sa.before_staff;
	sa.after_staff = getStaffId(s_list, "������ ��ġ��");
	return sa;
}

StaffAssign ioHandler::getNurseAssign(PatientList& p_list, StaffList& s_list)
{
	StaffAssign sa;
	sa.patient_id = getPatientId(p_list, "������ ������ ȯ���� ��ȣ : ");
	Patient p = p_list.searchPatient(sa.patient_id);

	sa.change_date = getCurrentDate();
	cout << endl << "������(yyyymmdd) : " << sa.change_date;

	sa.before_staff = p.nurse_assigned;
	cout << "������ ��� ��ȣ�� : " << sa.before_staff;
	sa.after_staff = getStaffId(s_list, "");
	return sa;
}

void ioHandler::putStaffAssign(StaffAssign ac)
{
	cout << endl << "ȯ�ڹ�ȣ: " << ac.patient_id;
	cout << endl << "������: " << ac.change_date.substr(0, 4) << "�� "
		<< ac.change_date.substr(4, 2) << "�� " << ac.change_date.substr(6, 2) << "�� ";
	cout << endl << "���� �� ���� : " << ac.before_staff;
	cout << endl << "���� �� ���� : " << ac.after_staff;
}

CheckSheet ioHandler::getCheckSheet(PatientList& p_list, StaffList& s_list, CheckSheetList& cs_list)
{
	CheckSheet cs;

	string today = getCurrentDate();
	cout << endl << endl << "�˻� ��Ͽ� ���� �ڷ� �Է�";
	cs.check_sheet_no = cs_list.findMaxCheckSheetNo(today.substr(0, 4));
	cout << endl << "����� ��ȣ: " << cs.check_sheet_no;
	cs.patient_id = getPatientId(p_list, "ȯ�ڹ�ȣ: ");
	cs.check_date = getCurrentDate();
	cout << endl << "�˻���: " << cs.check_date << endl;
	cs.nurse_id = getStaffId(s_list, "�˻��� ��ȣ���� ������ȣ: ");
	cout << endl << "����: ";
	cin >> cs.blood_pressure;
	cout << endl << "ü��: ";
	cin >> cs.temperature;
	cout << endl << "����: ";
	cin >> cs.blood_sugar;
	return cs;
}

void ioHandler::putCheckSheet(CheckSheet cs)
{
	cout << endl << "�������ȣ : " << cs.check_sheet_no;
	cout << endl << "ȯ�ڹ�ȣ : " << cs.patient_id;
	cout << endl << "�˻��� : " << cs.check_date;
	cout << endl << "�˻��� : " << cs.nurse_id;
	cout << endl << "���� : " << cs.blood_pressure;
	cout << endl << "ü�� : " << cs.temperature;
	cout << endl << "���� : " << cs.blood_sugar;
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
		date = to_string(year) + ("0" + to_string(month)) + to_string(day);
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