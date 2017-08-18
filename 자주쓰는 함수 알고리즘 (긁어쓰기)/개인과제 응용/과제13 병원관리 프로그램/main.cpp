#include "PatientList.h"
#include "RoomList.h"
#include "RoomChangeHistory.h"
#include "StaffList.h"
#include "StaffAssignHistory.h"
#include "FileHandler.h"
#include "ioHandler.h"
#include "TaskManager.h"

int main(void)
{
	PatientList p_list;
	RoomList r_list;
	RoomChangeHistory rc_history;
	StaffList s_list;
	StaffAssignHistory sa_history;
	CheckSheet cs;
	CheckSheetList cs_list;
	FileHandler fh;
	ioHandler ioh;
	TaskManager tm;

	fh.loadPatientList("patient.dat", p_list);
	fh.loadRoomList("room.dat", r_list);
	fh.loadRoomChangeHistory("room_history.dat", rc_history);
	fh.loadStaffList("staff.dat", s_list);
	fh.loadStaffAssignHistory("staff_history.dat", sa_history);
	fh.loadCheckSheetList("check_sheet.dat", cs_list);

	while (1)
	{
		int menu = ioh.getMenu();
		if (menu == EXIT) break;

		switch (menu) 
		{
		case CHECK_IN:
			tm.checkIn(p_list);
			break;
		case CHECK_OUT:
			tm.checkOut(p_list);
			break;
		case CHANGE_ROOM:
			tm.changeRoom(rc_history, p_list, r_list);
			break;
		case ASSIGN_STAFF:
			tm.assignStaff(p_list, s_list, sa_history);
			break;
		case REGISTER_CHECK_SHEET:
			tm.registerCheckSheet(p_list, cs_list, s_list);
			break;
		case QUERY:
			tm.processQuery(p_list, r_list, rc_history, s_list, sa_history, cs_list);
			break;
		}
	}
	fh.savePatientList("patient.dat", p_list);
	fh.saveRoomList("room.dat", r_list);
	fh.saveRoomChangeHistory("room_history.dat", rc_history);
	fh.saveStaffList("staff.dat", s_list);
	fh.saveStaffAssignHistory("staff_history.dat", sa_history);
	fh.saveCheckSheetList("check_sheet.dat", cs_list);
}
