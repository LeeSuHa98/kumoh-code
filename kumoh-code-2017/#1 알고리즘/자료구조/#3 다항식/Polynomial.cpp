#include "Polynomial.h"

ostream& operator<<(ostream& os, const Polynomial& p)
{
	float coef;
	int exp;

	for (int i = 0; i < p.terms; i++)
	{
		coef = p.termArray[i].getCoef();
		exp = p.termArray[i].getExp();

		if (coef != 0)
		{
			if (i != 0 && coef > 0) // 계수가 0보다 클 경우
			{
				os << " + ";
			}
			if (coef == -1) // 계수가 -1일 경우
			{
				os << " -";
			}
			else if (coef < 0)	// 계수가 0보다 작을 경우
			{
				os << coef;
			}
			else if (!(coef == 1))	// 계수가 1인 경우를 제외한 경우
			{
				os << coef;
			}
			if (exp != 0)
			{
				if (exp == 1)
				{
					os << "x";
				}
				else
				{
					os << "x^" << exp;
				}
			}
		}
	}
	return os;
}

istream& operator >> (istream& is, Polynomial& p)
{
	float coef;
	int exp;

	for (int i = 0; i < p.capacity; i++)
	{
		is >> coef >> exp;
		p.NewTerm(coef, exp);
		if (coef == 0)
		{
			break;
		}
		else if (exp == 0)
		{
			break;
		}
	}
	return is;
}

const Polynomial& Polynomial::operator=(const Polynomial& p)
{
	capacity = p.capacity;
	terms = p.terms;
	termArray = new Term[capacity];

	for (int i = 0; i < terms; i++)
	{
		termArray[i] = p.termArray[i];
	}
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& p)
{
	// *this와 p를 더한 결과를 반환한다.
	Polynomial c;
	int aPos = 0;
	int bPos = 0;

	while ((aPos < terms) && (bPos < p.terms))
	{
		if (termArray[aPos].exp == p.termArray[bPos].exp)
		{                                   
			float t = termArray[aPos].coef + p.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++;
			bPos++;
		}
		else if (termArray[aPos].exp < p.termArray[bPos].exp)
		{
			c.NewTerm(p.termArray[bPos].coef, p.termArray[bPos].exp);
			bPos++;
		}
		else
		{
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	// *this의 나머지 항들을 추가한다.
	for (; aPos < terms; aPos++)
	{
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	}
	// b(x)의 나머지 항들을 추가한다.
	for (; bPos < p.terms; bPos++)
	{
		c.NewTerm(p.termArray[bPos].coef, p.termArray[bPos].exp);
	}
	return c;
}

Polynomial Polynomial::operator*(const Polynomial& p)
{
	Polynomial result;
	float coef = 0;
	int exp = 0;

	for (int aPos = 0; aPos < terms; aPos++)
	{
		Polynomial temp;
		for (int bPos = 0; bPos < p.terms; bPos++)
		{
			coef = termArray[aPos].coef * p.termArray[bPos].coef;
			exp = termArray[aPos].exp + p.termArray[bPos].exp;
			temp.NewTerm(coef, exp);
		}
		if (aPos == 0)
		{
			result = temp; // operator=
		}
		else
		{
			result = result + temp; // operator=, operator+
		}
	}
	return result;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	// 새로운 항을 termArray 끝에 첨가한다.
	if (terms == capacity) // 항의 수와 배열의 용량이 같다면 
	{
		capacity *= 2; // termArray의 크기를 두 배로 확장
		Term* temp = new Term[capacity]; // 새로운 배열

		for (int i = 0; i < terms; i++) // 기존 항의 수 만큼 반복
		{
			temp[i] = termArray[i]; // 임시 배열에 기존 값을 할당
		}
		delete[] termArray; // 그전 메모리를 반환
		termArray = temp; // 늘어난 용량에 존재하는 값을 기존 배열에 할당
	}

	termArray[terms].coef = theCoeff; // 계수 할당
	termArray[terms].exp = theExp; // 지수 할당

	terms++;
}