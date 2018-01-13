#include "PatientList.h"
#include "IOHandler.h"
#include "TaskManager.h"
int main()
{
	PatientList p_list;
	IOHandler ioh;
	FileHandler foh;
	TaskManager tm;
	// load data from files
	foh.loadPatient("patient.txt", p_list);
	while (1)
	{
		int menu = ioh.getMenu();
		switch (menu)
		{
		case CHECK_IN:
			tm.admissionPatient(p_list);
			break;
		case CHECK_OUT:
			tm.leavePatient(p_list);
			break;
		case QUERY:
			tm.checkPatient(p_list);
			break;
		case EXIT:
			exit(1);
		}
	}
	// save data to files
	foh.savePatient("patient.txt", p_list);
	return 0;
}