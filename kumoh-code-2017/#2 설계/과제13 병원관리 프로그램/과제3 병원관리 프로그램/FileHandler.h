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
	void loadRoomChangeHistory(string fname, RoomChangeHistory& rc_history);
	void saveRoomChangeHistory(string fname, RoomChangeHistory& rc_history);
	void loadStaffList(string fname, StaffList& s_list);
	void saveStaffList(string fname, StaffList& s_list);
	void loadStaffAssignHistory(string fname, StaffAssignHistory& sa_history);
	void saveStaffAssignHistory(string fname, StaffAssignHistory& sa_history);
	void loadCheckSheetList(string fname, CheckSheetList& cs_list);
	void saveCheckSheetList(string fname, CheckSheetList& cs_list);


};