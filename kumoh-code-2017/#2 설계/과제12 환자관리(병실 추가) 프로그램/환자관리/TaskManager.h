#pragma once
#include "ioHandler.h"
class TaskManager 
{
private:
	// operations for display data
	void displayDetailsOfPatient(PatientList& p_list, RoomHistoryList& rh_list);	// 환자 상세 내역
	void displayAvailableOfRoomList(RoomList& r_list);								// 전체 환자 명단
	void displayPatientListByRoom(PatientList& p_list, RoomList& r_list);
public:
	// operation methods
	void checkIn(PatientList& p_list, RoomList& r_list);
	void checkOut(PatientList& p_list, RoomList& r_list);
	void changeRoom(PatientList& p_list, RoomList& r_list);
	void processQuery(PatientList& p_list, RoomList& r_list, RoomHistoryList& rh_list);
};