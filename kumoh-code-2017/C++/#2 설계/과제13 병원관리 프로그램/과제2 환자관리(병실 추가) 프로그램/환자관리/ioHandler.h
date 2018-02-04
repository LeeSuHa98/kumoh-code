#pragma once
#include "PatientList.h"
#include "RoomList.h"
#include "RoomHistoryList.h"

class ioHandler
{
public:
	// operations for menu handling
	int getMenu();
	int getQueryMenu();

	// operations for getting & putting object
	Patient getPatient(PatientList& p_list);
	void putPatient(Patient p);
	string getPatientId(PatientList& p_list, string msg);
	Room getRoom(RoomList& r_list);
	void putRoom(Room r);
	string getRoomNo(RoomList& r_list);
	RoomHistory getRoomHistory(Patient& p);
	void putRoomHistory(RoomHistory rh);

	// operations for date & time
	string getCurrentDate();	// returns ¡°yyyymmdd¡±of today()
	string getCurrentTime();	// returns ¡°hhmm¡±of today()
	string getDate();			// returns ¡°yyyymmdd¡±
	string getTime();			// returns ¡°hhmm¡±

	// operations for getting or putting simple value
	int getInteger(string msg, int lower, int upper);
	void putInteger(string msg, int n);
	string getString(string msg);
	void putString(string msg, string s);
	void putNewLine() { cout << endl; }
};