#pragma once
#include "Term.h"

class Polynomial
{
private:
	Term* termArray; // 0이 아닌 항의 배열
	int capacity; // termArray의 크기
	int terms; // 0이 아닌 항의 수
public:
	Polynomial()
	{
		capacity = 10;
		termArray = new Term[capacity];
		terms = 0;
	}
	Polynomial(const Polynomial& p) // Deep Copy
	{
		capacity = p.capacity;
		termArray = new Term[capacity];
		terms = p.terms;

		for (int i = 0; i < terms; i++)
		{
			termArray[i] = p.termArray[i];
		}
	}
	~Polynomial() { delete[] termArray; }

	friend ostream& operator<<(ostream& os, const Polynomial& p);
	friend istream& operator >> (istream& is, Polynomial& p);
	const Polynomial& operator=(const Polynomial& p);
	Polynomial operator+(const Polynomial& p);
	Polynomial operator*(const Polynomial& p);
	void NewTerm(const float theCoeff, const int theExp);
};