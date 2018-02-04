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
			if (i != 0 && coef > 0) // ����� 0���� Ŭ ���
			{
				os << " + ";
			}
			if (coef == -1) // ����� -1�� ���
			{
				os << " -";
			}
			else if (coef < 0)	// ����� 0���� ���� ���
			{
				os << coef;
			}
			else if (!(coef == 1))	// ����� 1�� ��츦 ������ ���
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
	// *this�� p�� ���� ����� ��ȯ�Ѵ�.
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
	// *this�� ������ �׵��� �߰��Ѵ�.
	for (; aPos < terms; aPos++)
	{
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	}
	// b(x)�� ������ �׵��� �߰��Ѵ�.
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
	// ���ο� ���� termArray ���� ÷���Ѵ�.
	if (terms == capacity) // ���� ���� �迭�� �뷮�� ���ٸ� 
	{
		capacity *= 2; // termArray�� ũ�⸦ �� ��� Ȯ��
		Term* temp = new Term[capacity]; // ���ο� �迭

		for (int i = 0; i < terms; i++) // ���� ���� �� ��ŭ �ݺ�
		{
			temp[i] = termArray[i]; // �ӽ� �迭�� ���� ���� �Ҵ�
		}
		delete[] termArray; // ���� �޸𸮸� ��ȯ
		termArray = temp; // �þ �뷮�� �����ϴ� ���� ���� �迭�� �Ҵ�
	}

	termArray[terms].coef = theCoeff; // ��� �Ҵ�
	termArray[terms].exp = theExp; // ���� �Ҵ�

	terms++;
}