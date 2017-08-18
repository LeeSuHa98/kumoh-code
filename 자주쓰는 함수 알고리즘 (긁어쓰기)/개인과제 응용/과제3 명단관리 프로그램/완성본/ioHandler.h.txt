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

	void putString(string msg) { cout << msg.c_str() << endl; }
	int getMenu();

	int getInteger(string msg);
	string getString(string msg);

	// 명단 등록부
	Faculty* insertFaculty();
	Staff* insertStaff();
	Undergraduate* insertUndergraduate();
	Graduate* insertGraduate();

	// 명단부
	Member* getMember(char member_type);
	// 명단 선택
	char insertMemberType();
};