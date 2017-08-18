#pragma once
#include <iostream>
#include <string>
#include <iomanip>

const int MAX_STUDENTS = 100;
enum Menus { REGISTER = 1, UNREGISTER, CHANGE, DISPLAY, EXIT }; // �׸��� ���� ������ ����

using namespace std;

class Student
{
private:
	int id; // �й�
	string name; // �̸�
	int age; // ����
	string phone; // ��ȭ��ȣ

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