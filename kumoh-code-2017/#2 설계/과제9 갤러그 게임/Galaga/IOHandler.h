#pragma once

#include <vector>
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

class IOHandler
{
public:
	void printMap(vector<vector<int>> map);
	void printMap(vector<vector<int>> before, vector<vector<int>> after);
};