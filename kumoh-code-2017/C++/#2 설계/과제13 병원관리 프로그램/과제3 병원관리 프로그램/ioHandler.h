#pragma once
#include "PatientList.h"
#include "RoomList.h"
#include "RoomChangeHistory.h"
#include "StaffList.h"
#include "StaffAssignHistory.h"
#include "CheckSheetList.h"

class ioHandler 
{
public:
	// operations for menu handling
	int getMenu();
	int getQueryMenu();
	int getStaffAssignMenu();

	// operations for getting & putting object
	Patient getPatient(PatientList& p_list);
	void putPatient(Patient p);
	RoomChange getRoomChange(PatientList& p_list, RoomList& r_list);
	void putRoomChange(RoomChange rc);

	string getPatientId(PatientList& p_list, string msg);
	int getRoomNo(RoomList& r_list);
	void putRoom(Room r);

	string getStaffId(StaffList& s_list, string msg);
	Staff getStaff(StaffList& s_list);
	void putStaff(Staff s);
	StaffAssign getDoctorAssign(PatientList& p_list, StaffList& s_list);
	StaffAssign getNurseAssign(PatientList& p_list, StaffList& s_list);
	void putStaffAssign(StaffAssign sa);

	CheckSheet getCheckSheet(PatientList& p_list, StaffList& s_list, CheckSheetList& cs_list);
	void putCheckSheet(CheckSheet cs);

	// operations for date & time
	string getCurrentDate();	// returns ¡°yyyymmdd¡±of today()
	string getCurrentTime();	// returns ¡°hhmm¡±of today()
	string getDate();		// returns ¡°yyyymmdd¡±
	string getTime();		// returns ¡°hhmm¡±

	// operations for getting or putting simple value
	int getInteger(string msg, int lower, int upper);
	void putInteger(string msg, int n);
	string getString(string msg);
	void putString(string msg, string s);
	void putNewLine() { cout << endl; }
};