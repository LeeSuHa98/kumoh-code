#include "Polynomial.h"

ostream& operator<<(ostream& os, Polynomial& p)
{
	float coef;
	int exp;

	for (int i = 0; i < p.terms; i++)
	{
		coef = p.getIndexNode(i)->getCoef();
		exp = p.getIndexNode(i)->getExp();

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
			else
			{
				os << coef;
			}
		}
	}
	return os;
}

istream& operator >> (istream& is, Polynomial& p)
{
	float coef;
	int exp;

	do
	{
		is >> coef >> exp;
		if (coef == 0)
		{
			break;
		}
		p.NewTerm(coef, exp);
		if (exp == 0)
		{
			break;
		}
	} while (exp != 0);

	return is;
}

Polynomial& Polynomial::operator=(Polynomial& p)
{
	this->~Polynomial();	// �Ҹ��� ȣ�� : ���� ���� ���������� �ȵȴ�.

	last = new Term(0, 0);	// ������ �ʱ�ȭ
	last->link = last;
	first = last;

	terms = 0;

	if (!p.terms)
	{
		return Polynomial();
	}

	Term* curNode = p.first;

	while (1)
	{
		float coef = curNode->coef;
		int exp = curNode->exp;
	
		NewTerm(coef, exp);

		curNode = curNode->link;

		if (curNode == p.first)
		{
			break;
		}
	}

	return *this;
}

Polynomial Polynomial::operator+(Polynomial& p)
{
	// *this�� p�� ���� ����� ��ȯ�Ѵ�.
	Polynomial c;
	int aPos = 0;
	int bPos = 0;

	while ((aPos < terms) && (bPos < p.terms))
	{
		if (getIndexNode(aPos)->exp == p.getIndexNode(bPos)->exp)
		{
			float t = getIndexNode(aPos)->coef + p.getIndexNode(bPos)->coef;
			if (t) c.NewTerm(t, getIndexNode(aPos)->exp);
			aPos++;
			bPos++;
		}
		else if (getIndexNode(aPos)->exp < p.getIndexNode(bPos)->exp)
		{
			c.NewTerm(p.getIndexNode(bPos)->coef, p.getIndexNode(bPos)->exp);
			bPos++;
		}
		else
		{
			c.NewTerm(getIndexNode(aPos)->coef, getIndexNode(aPos)->exp);
			aPos++;
		}
	}
	// *this�� ������ �׵��� �߰��Ѵ�.
	for (; aPos < terms; aPos++)
	{
		c.NewTerm(getIndexNode(aPos)->coef, getIndexNode(aPos)->exp);
	}
	// b(x)�� ������ �׵��� �߰��Ѵ�.
	for (; bPos < p.terms; bPos++)
	{
		c.NewTerm(p.getIndexNode(bPos)->coef, p.getIndexNode(bPos)->exp);
	}
	return c;
}

Polynomial Polynomial::operator*(Polynomial& p)
{
	Polynomial result;
	float coef = 0;
	int exp = 0;

	for (int aPos = 0; aPos < terms; aPos++)
	{
		Polynomial temp;
		for (int bPos = 0; bPos < p.terms; bPos++)
		{
			coef = getIndexNode(aPos)->coef * p.getIndexNode(bPos)->coef;
			exp = getIndexNode(aPos)->exp + p.getIndexNode(bPos)->exp;
			temp.NewTerm(coef, exp);
		}
		
		result = result + temp; // operator=, operator+
		
	}
	return result;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	Term* tempNode = new Term(theCoeff, theExp);

	if (!terms)
	{
		last = new Term(theCoeff, theExp);
		last->setLink(last);
		first = last;
	}
	else
	{
		last->link = new Term(theCoeff, theExp, first);

		last = last->link;
	}
	terms++;
}