#pragma once
#include "PatientList.h"

class CheckSheetList
{
private:
	CheckSheet check_sheet_list[MAX_PATIENTS];
	int count;

	int findIndex(CheckSheet cs);	// find index for¡®cs¡¯
public:
	CheckSheetList() {}
	~CheckSheetList() {}

	CheckSheet getCheckSheet(int index) { return check_sheet_list[index]; }
	int getCount() { return count; }

	void insertCheckSheet(CheckSheet cs);
	void deleteCheckSheet(CheckSheet cs);
	CheckSheetList searchCheckSheetForPatient(Patient p);
	string findMaxCheckSheetNo(string year);
	CheckSheet searchCheckSheet(string staff_id);
	void showCheckSheetList();
};