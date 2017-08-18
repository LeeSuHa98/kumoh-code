#pragma once
#include "PatientList.h"

typedef struct
{
	string room_no;			// ���ǹ�ȣ=����ȣ(1)+�Ϸù�ȣ(2)
	string room_type;		// �������� -> 1: 1�ν�, 2: 2�ν�, 3: 3�ν�, x: ���ν�
	char sex;				// ���� -> M: ������ ����, F: ������ ����
	int capacity;		// ���밡���ο�
	int p_count;	// �����ο�
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
	// ������ ���� �ο� ����
	void minusCurrentPatient(Room& r) { r.p_count--; }
	// ������ ���� �ο� �ʰ� ����
	bool isFull(Room& r) { return r.capacity == r.p_count ? true : false; }
	// ������ ���� ���� ����
	bool isSex(Patient& p, Room& r) { return  p.sex == r.sex ? true : false; }

	int findRoom(Room r);
	void insertRoom(Room r);
	void updateRoom(int index, Room r);
	// ���� �˻�
	Room searchRoom(string room_no);
};