#pragma once
#include "RoomList.h"

typedef struct
{
	string patient_id;	// ȯ�ڹ�ȣ
	string change_date;	// ������
	string room_no; // ����
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