#include "FileHandler.h"

void FileHandler::loadPatientList(string fname, PatientList& p_list)
{	// open file
	ifstream fin;
	fin.open(fname);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		return;
	}

	// read data from file
	Patient p;
	while (!fin.eof())	// read data
	{
		fin >> p.patient_id >> p.name >> p.sex >> p.birth_date >> p.phone_no >> p.entering_date
			>> p.disease >> p.room_no >> p.doctor_assigned >> p.nurse_assigned >> p.leaving_date;
		p_list.insertPatient(p);
	}

	// close file
	fin.close();
}

void FileHandler::savePatientList(string fname, PatientList& p_list)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout) 
	{
		cerr << "\n" << "can't open " << fname << "!!";
		exit(1);
	}

	// save data into file
	int count = p_list.getCount();
	for (int i = 0; i<count; i++) 
	{
		Patient p = p_list.getPatient(i);
		fout << p.patient_id << p.name << p.sex << p.birth_date << p.phone_no << p.entering_date
			<< p.disease << p.room_no << p.doctor_assigned << p.nurse_assigned << p.leaving_date;
	}

	// close file
	fout.close();
}

void FileHandler::loadRoomList(string fname, RoomList& r_list)
{
	// open file
	ifstream fin;
	fin.open(fname);
	if (!fin) 
	{
		cerr << "\n" << "can't open " << fname << "!!";
		return;
	}

	// read data from file
	Room r;
	while (!fin.eof())	// read data
	{
		fin >> r.room_no >> r.room_type >> r.sex >> r.capacity >> r.p_count;
		r_list.insertRoom(r);
	}

	// close file
	fin.close();
}

void FileHandler::saveRoomList(string fname, RoomList& r_list)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout) 
	{
		cerr << "\n" << "can't open " << fname << "!!";
		exit(1);
	}

	// save data into file
	int count = r_list.getCount();
	for (int i = 0; i<count; i++) 
	{
		Room r = r_list.getRoom(i);
		fout << r.room_no << r.room_type << r.sex << r.capacity << r.p_count;
	}

	// close file
	fout.close();
}

void FileHandler::loadRoomChangeHistory(string fname, RoomChangeHistory& rc_history)
{
	// open file
	ifstream fin;
	fin.open(fname);
	if (!fin) 
	{
		cerr << "\n" << "can't open " << fname << "!!";
		return;
	}

	// read data from file
	RoomChange rc;
	while (!fin.eof())	// read data
	{
		fin >> rc.patient_id >> rc.change_date >> rc.before_room >> rc.after_room;
		rc_history.insertRoomChange(rc);
	}

	// close file
	fin.close();
}

void FileHandler::saveRoomChangeHistory(string fname, RoomChangeHistory& rc_history)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		exit(1);
	}

	// save data into file
	int count = rc_history.getCount();
	for (int i = 0; i<count; i++) 
	{
		RoomChange rc = rc_history.getRoomChange(i);
		fout << rc.patient_id << rc.change_date << rc.before_room << rc.after_room;
	}

	// close file
	fout.close();
}

void FileHandler::loadStaffList(string fname, StaffList& s_list)
{
	// open file
	ifstream fin;
	fin.open(fname);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		return;
	}

	// read data from file
	Staff s;
	while (!fin.eof())	// read data
	{
		fin >> s.staff_id >> s.staff_sep >> s.name >> s.birth_date >> s.phone_no >> s.join_date >> s.resign_date;
		s_list.insertStaff(s);
	}

	// close file
	fin.close();
}

void FileHandler::saveStaffList(string fname, StaffList& s_list)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		exit(1);
	}

	// save data into file
	int count = s_list.getCount();
	for (int i = 0; i<count; i++)
	{
		Staff s = s_list.getStaff(i);
		fout << s.staff_id << s.staff_sep << s.name << s.birth_date << s.phone_no << s.join_date << s.resign_date;
	}

	// close file
	fout.close();
}

void FileHandler::loadStaffAssignHistory(string fname, StaffAssignHistory& sa_history)
{
	// open file
	ifstream fin;
	fin.open(fname);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		return;
	}

	// read data from file
	StaffAssign sa;
	while (!fin.eof())	// read data
	{
		fin >> sa.patient_id >> sa.change_date >> sa.before_staff >> sa.after_staff;
		sa_history.insertStaffAssign(sa);
	}

	// close file
	fin.close();
}

void FileHandler::saveStaffAssignHistory(string fname, StaffAssignHistory& sa_history)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		exit(1);
	}

	// save data into file
	int count = sa_history.getCount();
	for (int i = 0; i<count; i++)
	{
		StaffAssign sa = sa_history.getStaffAssign(i);
		fout << sa.patient_id << sa.change_date << sa.before_staff << sa.after_staff;
	}

	// close file
	fout.close();
}

void FileHandler::loadCheckSheetList(string fname, CheckSheetList& cs_list)
{
	// open file
	ifstream fin;
	fin.open(fname);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		return;
	}

	// read data from file
	CheckSheet cs;
	while (!fin.eof())	// read data
	{
		fin >> cs.check_sheet_no >> cs.patient_id >> cs.check_date >> cs.nurse_id >> cs.blood_pressure >> cs.temperature >> cs.blood_sugar;
		cs_list.insertCheckSheet(cs);
	}

	// close file
	fin.close();
}

void FileHandler::saveCheckSheetList(string fname, CheckSheetList& cs_list)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout)
	{
		cerr << "\n" << "can't open " << fname << "!!";
		exit(1);
	}

	// save data into file
	int count = cs_list.getCount();
	for (int i = 0; i<count; i++)
	{
		CheckSheet cs = cs_list.getCheckSheet(i);
		fout << cs.check_sheet_no << cs.patient_id << cs.check_date << cs.nurse_id << cs.blood_pressure << cs.temperature << cs.blood_sugar;
	}

	// close file
	fout.close();
}