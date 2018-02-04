#include "StaffAssignHistory.h"
#include "ioHandler.h"

int StaffAssignHistory::findIndex(StaffAssign sa)
{
	for (int i = 0; i<count; i++)
	{
		if (staff_assign_history[i].patient_id == sa.patient_id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void StaffAssignHistory::insertStaffAssign(StaffAssign sa)
{
	ioHandler ioh;
	if (count >= MAX_STAFF_ASSIGN)
	{
		ioh.putString("", "���� ���� ����!���α׷� ����!");
		exit(1);
	}
	staff_assign_history[count] = sa;
	count++;
}

void StaffAssignHistory::deleteStaffAssign(StaffAssign sa)
{
	ioHandler ioh;
	int index = findIndex(sa);
	if (index == NOT_FOUND)
	{
		ioh.putString("", "���� ����� �������� �ƴ���!!");
		return;
	}
	staff_assign_history[index] = staff_assign_history[count - 1];
	count--;
}

StaffAssignHistory StaffAssignHistory::searchStaffHistoryForPatient(Patient p)
{
	StaffAssignHistory result;
	for (int i = 0; i<count; i++)
	{
		if (staff_assign_history[i].patient_id == p.patient_id)
		{
			result.insertStaffAssign(staff_assign_history[i]);
		}
	}
	return result;
}

void StaffAssignHistory::showStaffAssignHistory()
{
	ioHandler ioh;
	ioh.putString("", "\n\n\t\t\t�Ƿ��� ���� ����");
	ioh.putString("", "\n������\t������\t������\n");

	for (int i = 0; i<count; i++)
	{
		ioh.putStaffAssign(staff_assign_history[i]);
	}
}