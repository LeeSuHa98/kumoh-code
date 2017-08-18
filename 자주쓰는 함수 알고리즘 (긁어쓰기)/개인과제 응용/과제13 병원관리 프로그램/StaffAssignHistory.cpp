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
		ioh.putString("", "저장 공간 부족!프로그램 종료!");
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
		ioh.putString("", "삭제 대상이 존재하지 아니함!!");
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
	ioh.putString("", "\n\n\t\t\t의료인 배정 내역");
	ioh.putString("", "\n변경일\t변경전\t변경후\n");

	for (int i = 0; i<count; i++)
	{
		ioh.putStaffAssign(staff_assign_history[i]);
	}
}