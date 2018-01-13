#pragma once
#include "ioHandler.h"
class TaskManager 
{
private:
	// operations for display data
	void displayDetailsOfPatient(PatientList& p_list, RoomHistoryList& rh_list);	// ȯ�� �� ����
	void displayAvailableOfRoomList(RoomList& r_list);								// ��ü ȯ�� ���
	void displayPatientListByRoom(PatientList& p_list, RoomList& r_list);
public:
	// operation methods
	void checkIn(PatientList& p_list, RoomList& r_list);
	void checkOut(PatientList& p_list, RoomList& r_list);
	void changeRoom(PatientList& p_list, RoomList& r_list);
	void processQuery(PatientList& p_list, RoomList& r_list, RoomHistoryList& rh_list);
};