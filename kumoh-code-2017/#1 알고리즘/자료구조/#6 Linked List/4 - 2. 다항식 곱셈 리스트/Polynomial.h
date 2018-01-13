#pragma once
#include <iostream>

using namespace std;

class Term
{
	friend class Polynomial;
private:
	float coef; // 계수
	int exp; // 지수
	Term* link;
public:
	Term()
	{
		coef = 0;
		exp = 0;
		link = NULL;
	}
	Term(float coef, int exp, Term* link = NULL) 
	{ 
		this->coef = coef;
		this->exp = exp;
		this->link = link;
	};
	~Term() {};

	float getCoef() const { return coef; }
	int getExp() const { return exp; }
	Term* getLink() { return link; }
	void setLink(Term* link)
	{
		this->link = link;
	}
};

class Polynomial
{
private:
	// 원형 리스트
	Term* first;	// 헤더
	Term* last;	// 테일
	int terms; // 항의 수
public:
	Polynomial()
	{
		last = new Term(0, 0);
		last->link = last;
		first = last;

		terms = 0; 
	}
	Polynomial(Polynomial& p)	// Deep Copy
	{
		last = new Term(0, 0);
		last->link = last;
		first = last;

		terms = 0;

		Term* curNode = p.first;

		while (1)
		{
			float coef = curNode->coef;
			int exp = curNode->exp;

			NewTerm(coef, exp);

			curNode = curNode->link;

			if (curNode == p.first)
				break;
		}
	}
	~Polynomial()	// 소멸자
	{
		while (1)
		{
			if (first == last)	// 원형 리스트에서 처음과 끝이 같음은 값이 없음
			{
				delete first;
				break;
			}
			Term* tmp = first;	// 해제할 임시 공간
			first = first->link;	// 노드 이동

			delete tmp;	// 동적 해제
		}
	}

	friend ostream& operator<<(ostream& os, Polynomial& p);
	friend istream& operator >> (istream& is, Polynomial& p);
	Polynomial& operator=(Polynomial& p);
	Polynomial operator+(Polynomial& p);
	Polynomial operator*(Polynomial& p);
	void NewTerm(const float theCoeff, const int theExp);
	

	Term* getIndexNode(int index)
	{
		Term* curNode = first;
		int count = 0;
		while (1)
		{
			if (count == index)
			{
				return curNode;
			}
			curNode = curNode->link;
			count++;
		}
	}

	/*void insertNode(Term* newNode)
	{
		last->link = newNode;
		last = last->link;
	}*/
};