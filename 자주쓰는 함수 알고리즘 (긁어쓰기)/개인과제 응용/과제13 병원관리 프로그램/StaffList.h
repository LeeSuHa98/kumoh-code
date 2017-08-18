#pragma once
#include "PatientList.h"

class StaffList
{
private:
	Staff staff_list[MAX_STAFFS];
	int count;

	int findIndex(Staff s);	// find index for¡®s¡¯
public:
	StaffList() {}
	~StaffList() {}

	Staff getStaff(int index) { return staff_list[index]; }
	int getCount() { return count; }

	void insertStaff(Staff s);
	void deleteStaff(Staff s);
	string findMaxStaffId(string year);
	Staff searchStaff(string staff_id);
	StaffList searchStaffInRoom(string staff_sep);
	void showStaffList();
};