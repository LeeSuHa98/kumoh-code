#pragma once
#include "Graduate.h"
#include "Employee.h"

class IndustrialGraduate : public Graduate, public Employee
{
public:
	IndustrialGraduate() {}
	IndustrialGraduate(string name, int id, string major, int grade, int credit, string assistant, int bursary, string job) : Graduate(name, id, major, grade, credit, assistant, bursary), Employee(name, id, job) {}
	~IndustrialGraduate() {}
};