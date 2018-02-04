#include "RoomList.h"
#include "ioHandler.h"

int RoomList::findIndex(Room r)
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

void RoomList::deleteRoom(Room r)
{
	ioHandler ioh;
	int index = findIndex(r);
	if (index == NOT_FOUND) 
	{
		ioh.putString("", "삭제 대상이 존재하지 아니함!!");
		return;
	}
	room_list[index] = room_list[count - 1];
	count--;
}

Room RoomList::searchRoom(int room_no)
{
	for (int i = 0; i<count; i++)
	{
		if (room_list[i].room_no == room_no)
		{
			return room_list[i];
		}
	}
	Room r;
	r.room_no = NULL;			// indicate NOT_FOUND
	return r;
}

RoomList RoomList::searchAvailableRooms()
{
	RoomList result;
	for (int i = 0; i<count; i++) 
	{
		if (room_list[i].capacity > room_list[i].p_count)
		{
			result.insertRoom(room_list[i]);
		}
	}
	return result;
}

void RoomList::showRoomList()
{
	ioHandler ioh;
	ioh.putString("", "\n\n\t\t\t병실 목록");
	ioh.putString("", "\n병실번호\t병실종류\t성별\t수용가능인원\t현재인원\n");

	for (int i = 0; i<count; i++) 
	{
		ioh.putRoom(room_list[i]);
	}
}