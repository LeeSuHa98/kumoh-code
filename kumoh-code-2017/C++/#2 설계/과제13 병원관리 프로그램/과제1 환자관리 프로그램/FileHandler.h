#pragma once
#include "IOHandler.h"

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}
	void loadPatient(string fileName, PatientList& p_list);
	void savePatient(string fileName, PatientList& p_list);
};
