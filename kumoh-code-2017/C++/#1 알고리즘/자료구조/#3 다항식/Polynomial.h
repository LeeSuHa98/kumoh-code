#pragma once
#include "Term.h"

class Polynomial
{
private:
	Term* termArray; // 0�� �ƴ� ���� �迭
	int capacity; // termArray�� ũ��
	int terms; // 0�� �ƴ� ���� ��
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