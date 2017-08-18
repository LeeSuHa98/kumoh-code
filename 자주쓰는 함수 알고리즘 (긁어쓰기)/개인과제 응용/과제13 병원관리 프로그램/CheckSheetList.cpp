#include "CheckSheetList.h"
#include "ioHandler.h"

int CheckSheetList::findIndex(CheckSheet cs)
{
	for (int i = 0; i<count; i++)
	{
		if (check_sheet_list[i].check_sheet_no == cs.check_sheet_no)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void CheckSheetList::insertCheckSheet(CheckSheet cs)
{
	ioHandler ioh;
	if (count >= MAX_CHECK_SHEET)
	{
		ioh.putString("", "저장 공간 부족!프로그램 종료!");
		exit(1);
	}
	check_sheet_list[count] = cs;
	count++;
}

void CheckSheetList::deleteCheckSheet(CheckSheet cs)
{
	ioHandler ioh;
	int index = findIndex(cs);
	if (index == NOT_FOUND)
	{
		ioh.putString("", "삭제 대상이 존재하지 아니함!!");
		return;
	}
	check_sheet_list[index] = check_sheet_list[count - 1];
	count--;
}

CheckSheetList CheckSheetList::searchCheckSheetForPatient(Patient p)
{
	CheckSheetList result;
	for (int i = 0; i<count; i++)
	{
		if (check_sheet_list[i].patient_id == p.patient_id)
		{
			result.insertCheckSheet(check_sheet_list[i]);
		}
	}
	return result;
}

string CheckSheetList::findMaxCheckSheetNo(string year)
{
	char temp_id[5];
	sprintf(temp_id, "%04d", count);

	string max_id = year + temp_id;	// set dummy minimum value

	for (int i = 0; i<count; i++)
	{
		if (check_sheet_list[i].check_sheet_no.substr(0, 8) != year)
		{
			continue;
		}
		if (check_sheet_list[i].check_sheet_no > max_id)	// find new maximum value
		{
			max_id = check_sheet_list[i].check_sheet_no;
		}
	}
	return max_id;
}

CheckSheet CheckSheetList::searchCheckSheet(string recording_no)
{
	for (int i = 0; i<count; i++)
	{
		if (check_sheet_list[i].check_sheet_no == recording_no)
		{
			return check_sheet_list[i];
		}
	}
	CheckSheet cs;
	cs.check_sheet_no = "";			// indicate NOT_FOUND
	return cs;
}

void CheckSheetList::showCheckSheetList()
{
	ioHandler ioh;
	ioh.putString("", "\n\n\t\t\t기록지 번호 명단");
	ioh.putString("", "\n기록지번호\t환자번호\t검사일\t검사자\t혈압\t체온\t혈당\n");

	for (int i = 0; i<count; i++)
	{
		ioh.putCheckSheet(check_sheet_list[i]);
	}
}