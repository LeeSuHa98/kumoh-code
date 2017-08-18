#pragma once
#include <iostream>
#include <string>
#include <iomanip>

const int MAX_STUDENTS = 100;
enum Menus { REGISTER = 1, UNREGISTER, CHANGE, DISPLAY, EXIT }; // 항목을 숫자 순서로 지정

using namespace std;

class Student
{
private:
	int id; // 학번
	string name; // 이름
	int age; // 나이
	string phone; // 전화번호

public:
	Student() {}
	Student(int id, string name, int age, string phone)
	{
		this->id = id;
		this->name = name;
		this->age = age;
		this->phone = phone;
	}
	~Student() {}

	int getId() { return id; }
	string getName() { return name; }
	int getAge() { return age; }
	string getPhone() { return phone; }
};