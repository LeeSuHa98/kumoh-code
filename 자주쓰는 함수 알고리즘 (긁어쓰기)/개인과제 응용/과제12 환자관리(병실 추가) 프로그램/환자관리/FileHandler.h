#pragma once
#include "ioHandler.h"
class FileHandler 
{
public:
	// operations for file handling
	void loadPatientList(string fname, PatientList& p_list);
	void savePatientList(string fname, PatientList& p_list);
	void loadRoomList(string fname, RoomList& r_list);
	void saveRoomList(string fname, RoomList& r_list);
	void loadRoomHistoryList(string fname, RoomHistoryList& rh_list);
	void saveRoomHistoryList(string fname, RoomHistoryList& rh_list);
};