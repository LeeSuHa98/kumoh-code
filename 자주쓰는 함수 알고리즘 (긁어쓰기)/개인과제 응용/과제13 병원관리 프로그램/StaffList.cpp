#include "StaffList.h"
#include "ioHandler.h"

int StaffList::findIndex(Staff s)
{
	for (int i = 0; i<count; i++)
	{
		if (staff_list[i].staff_id == s.staff_id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void StaffList::insertStaff(Staff s)
{
	ioHandler ioh;
	if (count >= MAX_STAFFS)
	{
		ioh.putString("", "���� ���� ����!���α׷� ����!");
		exit(1);
	}
	staff_list[count] = s;
	count++;
}

void StaffList::deleteStaff(Staff s)
{
	ioHandler ioh;
	int index = findIndex(s);
	if (index == NOT_FOUND)
	{
		ioh.putString("", "���� ����� �������� �ƴ���!!");
		return;
	}
	staff_list[index] = staff_list[count - 1];
	count--;
}

string StaffList::findMaxStaffId(string year)
{
	char temp_id[5];
	sprintf(temp_id, "%04d", count);

	string max_id = year + temp_id;	// set dummy minimum value

	for (int i = 0; i<count; i++)
	{
		if (staff_list[i].staff_id.substr(0, 4) != year)
		{
			continue;
		}
		if (staff_list[i].staff_id > max_id)	// find new maximum value
		{
			max_id = staff_list[i].staff_id;
		}
	}
	return max_id;
}

Staff StaffList::searchStaff(string staff_id)
{
	for (int i = 0; i<count; i++)
	{
		if (staff_list[i].staff_id == staff_id)
		{
			return staff_list[i];
		}
	}
	Staff s;
	s.staff_id = "";			// indicate NOT_FOUND
	return s;
}

StaffList StaffList::searchStaffInRoom(string staff_sep)
{
	StaffList result;
	for (int i = 0; i<count; i++)
	{
		if (staff_list[i].staff_sep == staff_sep)
		{
			result.insertStaff(staff_list[i]);
		}
	}
	return result;
}

void StaffList::showStaffList()
{
	ioHandler ioh;
	ioh.putString("", "\n\n\t\t\t���� ���");
	ioh.putString("", "\n������ȣ\t��������\t����\t�������\t�޴�����ȣ\t�Ի���\t�����\n");

	for (int i = 0; i<count; i++)
	{
		ioh.putStaff(staff_list[i]);
	}
}