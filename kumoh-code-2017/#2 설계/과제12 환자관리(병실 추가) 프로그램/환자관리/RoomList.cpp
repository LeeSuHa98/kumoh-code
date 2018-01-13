#include "RoomList.h"
#include "ioHandler.h"

int RoomList::findRoom(Room r)
{
	for (int i = 0; i<count; i++)
	{
		if (room_list[i].room_no == r.room_no)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void RoomList::insertRoom(Room r)
{
	ioHandler ioh;

	if (count >= MAX_ROOMS)
	{
		ioh.putString("", "저장 공간 부족!프로그램 종료!");
		exit(1);
	}

	room_list[count] = r;
	count++;
}

void RoomList::updateRoom(int index, Room r)
{
	room_list[index] = r;
}

Room RoomList::searchRoom(string room_no)
{
	for (int i = 0; i<MAX_ROOMS; i++)
	{
		if (room_list[i].room_no == room_no)
		{
			return room_list[i];
		}
	}
	Room r;
	r.room_no = "";			// indicate NOT_FOUND
	return r;
}