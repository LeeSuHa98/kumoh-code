#include "FileHandler.h"

void FileHandler::loadPatientList(string fname, PatientList& p_list)
{	// open file
	ifstream fin;
	fin.open(fname, ios_base::in);
	if (!fin) 
	{
		cerr << "\n" << "can't open file!!";
		return;
	}

	// read data from file
	Patient p;
	while (!fin.eof()) // read data
	{
		fin >> p.patient_id >> p.name >> p.sex >> p.birth_date >> p.phone_no >> p.entering_date >> p.entering_time
			>> p.disease >> p.room_no >> p.doctor_assigned >> p.nurse_assigned >> p.leaving_date >> p.leaving_time;
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
		cerr << "\n" << "can't open file!!";
		exit(1);
	}

	// save data into file
	int count = p_list.getCount();
	for (int i = 0; i<count; i++) 
	{
		Patient p = p_list.getPatientList(i);
		fout << p.patient_id << " " << p.name << " " << p.sex << " " << p.birth_date << " " << p.phone_no << " " << p.entering_date << " "
			<< p.disease << " " << p.room_no << " " << p.doctor_assigned << " " << p.nurse_assigned << " " << p.leaving_date << endl;
	}

	// close file
	fout.close();
}

void FileHandler::loadRoomList(string fname, RoomList& r_list)
{	// open file
	ifstream fin;
	fin.open(fname, ios_base::in);
	if (!fin)
	{
		cerr << "\n" << "can't open file!!";
		return;
	}

	// read data from file
	Room r;
	while (!fin.eof()) // read data
	{
		fin >> r.room_no >> r.room_type >> r.sex >> r.max_patient >> r.current_patient;
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
		cerr << "\n" << "can't open file!!";
		exit(1);
	}

	// save data into file
	int count = r_list.getCount();
	for (int i = 0; i<count; i++)
	{
		Room r = r_list.getRoomList(i);
		fout << r.room_no << " " << r.room_type << " " << r.sex << " " << r.max_patient << " " << r.current_patient << endl;
	}

	// close file
	fout.close();
}

void FileHandler::loadRoomHistoryList(string fname, RoomHistoryList& rh_list)
{	// open file
	ifstream fin;
	fin.open(fname, ios_base::in);
	if (!fin)
	{
		cerr << "\n" << "can't open file!!";
		return;
	}

	// read data from file
	RoomHistory rh;
	while (!fin.eof()) // read data
	{
		fin >> rh.patient_id >> rh.change_date >> rh.room_no;
		rh_list.insertHistory(rh);
	}

	// close file
	fin.close();
}

void FileHandler::saveRoomHistoryList(string fname, RoomHistoryList& rh_list)
{
	// open file
	ofstream fout;
	fout.open(fname);
	if (!fout)
	{
		cerr << "\n" << "can't open file!!";
		exit(1);
	}

	// save data into file
	int count = rh_list.getCount();
	for (int i = 0; i<count; i++)
	{
		RoomHistory rh = rh_list.getRoomHistoryList(i);
		fout << rh.patient_id << " " << rh.change_date << " " << rh.room_no << endl;
	}

	// close file
	fout.close();
}