#pragma once
#include "common.h"
#include "Student.h"

class DataHandler
{
public:
	DataHandler() {}
	~DataHandler() {}

	void generateData(int* a, int numOfData);
	void generateData(double* a, int numOfData);
	void generateData(string* a, int numOfData);
	void generateData(Student* a, int numOfData);
};