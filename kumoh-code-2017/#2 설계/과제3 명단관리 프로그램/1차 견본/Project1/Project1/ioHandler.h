#pragma once
#include "Member.h"
#include "Faculty.h"
#include "Staff.h"
#include "Undergraduate.h"
#include "Graduate.h"

class ioHandler
{
public:
	ioHandler() {}
	~ioHandler() {}
	void getMenu();

	Faculty insertFaculty();
	Staff insertStaff();
	Undergraduate insertUndergraduate();
	Graduate insertGraduate();

	void getInsertMenu();
	int getInteger(string msg);
	string getString(string msg);

	void printFaculty(Member& m_list);
	void printStaff();
	void printUndergraduate();
	void printGraduate();
};