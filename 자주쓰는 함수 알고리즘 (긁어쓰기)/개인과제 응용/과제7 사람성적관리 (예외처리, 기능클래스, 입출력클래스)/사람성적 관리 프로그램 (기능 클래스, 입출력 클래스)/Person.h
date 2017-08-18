#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_PERSON = 10;
const int NOT_FOUND = -1;
enum Menus { INSERT = 1, UNREGISTER, DISPLAY, EXIT };

class Person
{
private:
	string name;
	int korean;
	int english;
	int math;
	double avg;
	string grade;
public:
	Person() {}
	Person(string name, int korean, int english, int math)
	{
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}
	~Person() {}

	string getName() { return name; }
	int getKorean() { return korean; }
	int getEnglish() { return english; }
	int getMath() { return math; }
	double getAverage() { return avg = (korean + english + math) / 3; } // 한 사람의 평균점수

	string getGrade() // 성적의 등급
	{
		if (avg >= 90)
		{
			grade = "A";
			return grade;
		}
		else if (avg >= 80)
		{
			grade = "B";
			return grade;
		}
		else if (avg >= 70)
		{
			grade = "C";
			return grade;
		}
		else if (avg >= 60)
		{
			grade = "D";
			return grade;
		}
		else
		{
			grade = "F";
			return grade;
		}
	}
};

