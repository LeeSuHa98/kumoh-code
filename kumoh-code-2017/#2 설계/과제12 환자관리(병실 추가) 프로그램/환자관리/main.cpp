#include "PatientList.h"
#include "FileHandler.h"
#include "ioHandler.h"
#include "TaskManager.h"
#include "RoomList.h"
#include "RoomHistoryList.h"

int main(void)
{
	PatientList p_list;
	FileHandler fh;
	ioHandler ioh;
	TaskManager tm;
	RoomList r_list;
	RoomHistoryList rh_list;

	fh.loadPatientList("patient.dat", p_list);
	fh.loadRoomList("room.dat", r_list);
	fh.loadRoomHistoryList("room_history.dat", rh_list);

	while (1) 
	{
		int menu = ioh.getMenu();
		if (menu == EXIT) break;

		switch (menu) 
		{
		case CHECK_IN:
			tm.checkIn(p_list, r_list);
			break;
		case CHECK_OUT:
			tm.checkOut(p_list, r_list);
			break;
		case CHANGE_ROOM:
			tm.changeRoom(p_list, r_list);
			break;
		case QUERY:
			tm.processQuery(p_list, r_list, rh_list);
			break;
		}
	}
	fh.savePatientList("patient.dat", p_list);
	fh.saveRoomList("room.dat", r_list);
	fh.saveRoomHistoryList("room_history.dat", rh_list);
}