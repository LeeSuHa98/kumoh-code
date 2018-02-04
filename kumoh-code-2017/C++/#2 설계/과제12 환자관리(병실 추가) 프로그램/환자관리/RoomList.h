#pragma once
#include "PatientList.h"

typedef struct
{
	string room_no;			// 병실번호=층번호(1)+일련번호(2)
	string room_type;		// 병실종류 -> 1: 1인실, 2: 2인실, 3: 3인실, x: 다인실
	char sex;				// 성별 -> M: 남성용 병실, F: 여성용 병실
	int capacity;		// 수용가능인원
	int p_count;	// 현재인원
} Room;

class RoomList
{
private:
	Room room_list[MAX_ROOMS];
	int count;
public:
	RoomList() { count = 0; }
	~RoomList() {}

	Room& getRoomList(int index) { return room_list[index]; }
	int getCount() { return count; }
	// 병실의 현재 인원 증감
	void minusCurrentPatient(Room& r) { r.p_count--; }
	// 병실의 현재 인원 초과 유무
	bool isFull(Room& r) { return r.capacity == r.p_count ? true : false; }
	// 병실의 성별 대조 유무
	bool isSex(Patient& p, Room& r) { return  p.sex == r.sex ? true : false; }

	int findRoom(Room r);
	void insertRoom(Room r);
	void updateRoom(int index, Room r);
	// 병실 검색
	Room searchRoom(string room_no);
};