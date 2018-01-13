#include "PatientList.h"

int PatientList::findPatient(int id)
{
	for (int i = 0; i < count; i++)
	{
		if (patient_list[i].id == id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

int PatientList::findLeaveDate(string leave_date)
{
	for (int i = 0; i < count; i++)
	{
		if (patient_list[i].leave_date == leave_date)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void PatientList::insertPatient(Patient& p)
{
	if (count > MAX_PATIENT) // 메모리 초과 예외처리
	{
		cout << "Memory Full!" << endl; // 충분한 메모리

		return;
	}
	patient_list[count] = p;

	count++;
}

void PatientList::deletePatient(int index)
{
	patient_list[index] = patient_list[index + 1];

	count--;
}

void PatientList::updatePatient(int index, Patient p)
{
	patient_list[index] = p;
}

void PatientList::setPatient(int index, string room, string doctor, string nurse)
{
	patient_list[index].room;
	patient_list[index].doctor;
	patient_list[index].nurse;
}