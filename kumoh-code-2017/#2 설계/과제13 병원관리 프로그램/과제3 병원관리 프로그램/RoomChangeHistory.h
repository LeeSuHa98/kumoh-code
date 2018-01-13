#pragma once
#include "PatientList.h"

class RoomChangeHistory 
{
private:
	RoomChange room_change_history[MAX_ROOM_CHANGES];
	int count;

	int findIndex(RoomChange rc);	// find index for¡®rc¡¯
public:
	RoomChangeHistory() {}
	~RoomChangeHistory() {}

	RoomChange getRoomChange(int index) { return room_change_history[index]; }
	int getCount() { return count; }

	void insertRoomChange(RoomChange rc);
	void deleteRoomChange(RoomChange rc);
	RoomChangeHistory searchRoomHistoryForPatient(Patient p);
	void showRoomChangeHistory();
};