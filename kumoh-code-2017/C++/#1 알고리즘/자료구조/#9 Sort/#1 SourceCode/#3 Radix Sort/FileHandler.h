#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}

	void loadFile(string fileName, int*& arr);
	void saveFile(string fileName, int*& arr, int size);
};