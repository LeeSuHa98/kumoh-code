#pragma once
#include "PatientList.h"

class StaffAssignHistory
{
private:
	StaffAssign staff_assign_history[MAX_STAFF_ASSIGN];
	int count;

	int findIndex(StaffAssign sa);	// find index for¡®sa¡¯
public:
	StaffAssignHistory() {}
	~StaffAssignHistory() {}

	StaffAssign getStaffAssign(int index) { return staff_assign_history[index]; }
	int getCount() { return count; }

	void insertStaffAssign(StaffAssign sa);
	void deleteStaffAssign(StaffAssign sa);
	StaffAssignHistory searchStaffHistoryForPatient(Patient p);
	void showStaffAssignHistory();
};