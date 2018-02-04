#pragma once
#include <iostream>

using namespace std;

class Term
{
	friend class Polynomial;
private:
	float coef; // 계수
	int exp; // 지수
public:
	Term() {};
	~Term() {};

	float getCoef() const { return coef; }
	int getExp() const { return exp; }
};