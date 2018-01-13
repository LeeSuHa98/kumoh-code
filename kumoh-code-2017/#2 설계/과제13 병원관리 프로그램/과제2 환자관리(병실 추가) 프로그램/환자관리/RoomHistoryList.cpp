#include "RoomHistoryList.h"
#include "ioHandler.h"

void RoomHistoryList::insertHistory(RoomHistory rh)
{
	ioHandler ioh;
	if (count >= MAX_ROOMS)
	{
		ioh.putString("", "저장 공간 부족!프로그램 종료!");
		exit(1);
	}
	room_history_list[count] = rh;
	count++;
}

RoomHistory RoomHistoryList::searchRoomHistory(string& patient_id)
{
	for (int i = 0; i<MAX_ROOMS; i++)
	{
		if (room_history_list[i].patient_id == patient_id)
		{
			return room_history_list[i];
		}
	}
	RoomHistory rh;
	rh.patient_id = "";			// indicate NOT_FOUND
	return rh;
}