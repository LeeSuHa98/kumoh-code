#pragma once
#include "PatientList.h"

class RoomList
{
	Room room_list[MAX_ROOMS];
	int count;

	int findIndex(Room r);	// find index for¡®r¡¯
public:
	RoomList() { }
	~RoomList() { }

	Room getRoom(int index) { return room_list[index]; }
	int getCount() { return count; }

	void insertRoom(Room r);
	void deleteRoom(Room r);
	Room searchRoom(int room_no);
	RoomList searchAvailableRooms();
	void showRoomList();
};