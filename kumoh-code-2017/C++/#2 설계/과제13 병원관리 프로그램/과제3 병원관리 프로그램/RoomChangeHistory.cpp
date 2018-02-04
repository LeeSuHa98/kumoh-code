#include "RoomChangeHistory.h"
#include "ioHandler.h"

int RoomChangeHistory::findIndex(RoomChange rc)
{
	for (int i = 0; i<count; i++) 
	{
		if (room_change_history[i].patient_id == rc.patient_id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void RoomChangeHistory::insertRoomChange(RoomChange rc)
{
	ioHandler ioh;
	if (count >= MAX_ROOM_CHANGES) 
	{
		ioh.putString("", "���� ���� ����!���α׷� ����!");
		exit(1);
	}
	room_change_history[count] = rc;
	count++;
}

void RoomChangeHistory::deleteRoomChange(RoomChange rc)
{
	ioHandler ioh;
	int index = findIndex(rc);
	if (index == NOT_FOUND) 
	{
		ioh.putString("", "���� ����� �������� �ƴ���!!");
		return;
	}
	room_change_history[index] = room_change_history[count - 1];
	count--;
}

RoomChangeHistory RoomChangeHistory::searchRoomHistoryForPatient(Patient p)
{
	RoomChangeHistory result;
	for (int i = 0; i<count; i++)
	{
		if (room_change_history[i].patient_id == p.patient_id)
		{
			result.insertRoomChange(room_change_history[i]);
		}
	}
	return result;
}

void RoomChangeHistory::showRoomChangeHistory()
{
	ioHandler ioh;
	ioh.putString("", "\n\n\t\t\t���� �̵� ����");
	ioh.putString("", "\n������\t������\t������\n");

	for (int i = 0; i<count; i++)
	{
		ioh.putRoomChange(room_change_history[i]);
	}
}