#include "PatientList.h"
#include "ioHandler.h"

// Class Implementations
int PatientList::findIndex(Patient p)
{
	for (int i = 0; i<count; i++) 
	{
		if (patient_list[i].patient_id == p.patient_id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void PatientList::insertPatient(Patient p)
{
	ioHandler ioh;
	if (count >= MAX_PATIENTS)
	{
		ioh.putString("", "���� ���� ����!���α׷� ����!");
		exit(1);
	}
	patient_list[count] = p;
	count++;
}

void PatientList::deletePatient(Patient p)
{
	ioHandler ioh;
	int index = findIndex(p);
	if (index == NOT_FOUND) 
	{
		ioh.putString("", "���� ����� �������� �ƴ���!!");
		return;
	}
	patient_list[index] = patient_list[count - 1];
	count--;
}

string PatientList::findMaxPatientId(string year)
{
	char temp_id[5];
	sprintf(temp_id, "%04d", count);

	string max_id = year + temp_id;	// set dummy minimum value

	for (int i = 0; i<count; i++)
	{
		if (patient_list[i].patient_id.substr(0, 4) != year)
		{
			continue;
		}
		if (patient_list[i].patient_id > max_id)	// find new maximum value
		{
			max_id = patient_list[i].patient_id;
		}
	}
	return max_id;
}

Patient PatientList::searchPatient(string patient_id)
{
	for (int i = 0; i<count; i++) 
	{
		if (patient_list[i].patient_id == patient_id)
		{
			return patient_list[i];
		}
	}
	Patient p;
	p.patient_id = "";			// indicate NOT_FOUND
	return p;
}

PatientList PatientList::searchPatientsInRoom(int room_no)
{
	PatientList result;
	for (int i = 0; i<count; i++) 
	{
		if (patient_list[i].room_no == room_no)
		{
			result.insertPatient(patient_list[i]);
		}
	}
	return result;
}

PatientList PatientList::searchPatientInStaff(string s_id)
{
	PatientList result;
	for (int i = 0; i<count; i++)
	{
		if (patient_list[i].doctor_assigned == s_id || patient_list[i].nurse_assigned == s_id)
		{
			result.insertPatient(patient_list[i]);
		}
	}
	return result;
}

void PatientList::showPatientList()
{
	ioHandler ioh;
	ioh.putString("", "\n\n\t\t\tȯ�� ���");
	ioh.putString("", "\nȯ�ڹ�ȣ\t����\t����\t�޴�����ȣ\t�Կ���\t�Կ��ð�\t����\t����\t��ġ��\t��簣ȣ��\t�����\t����ð�\n");

	for (int i = 0; i<count; i++)
	{
		ioh.putPatient(patient_list[i]);
	}
}