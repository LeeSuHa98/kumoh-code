#pragma once
#include <iostream>

using namespace std;

class Term
{
	friend class Polynomial;
private:
	float coef; // ���
	int exp; // ����
public:
	Term() {};
	~Term() {};

	float getCoef() const { return coef; }
	int getExp() const { return exp; }
};