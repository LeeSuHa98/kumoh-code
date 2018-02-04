#pragma once
#include "RoomList.h"

typedef struct
{
	string patient_id;	// 환자번호
	string change_date;	// 변경일
	string room_no; // 병실
} RoomHistory;

class RoomHistoryList
{
private:
	RoomHistory room_history_list[MAX_ROOMS];
	int count;
public:
	RoomHistoryList() { count = 0; }
	~RoomHistoryList() {}

	RoomHistory getRoomHistoryList(int index) { return room_history_list[index]; }
	int getCount() { return count; }

	void insertHistory(RoomHistory rh);
	RoomHistory searchRoomHistory(string& patient_id);
	
};