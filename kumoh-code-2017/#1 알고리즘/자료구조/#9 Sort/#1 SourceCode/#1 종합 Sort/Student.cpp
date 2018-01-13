#include "Student.h"

bool operator < (Student& s1, Student& s2)
{
	double averS1 = double(s1.kor + s1.math + s1.eng) / 3;
	double averS2 = double(s2.kor + s2.math + s2.eng) / 3;

	if (averS1 < averS2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator > (const Student& s1, const Student& s2)
{
	double averS1 = double(s1.kor + s1.math + s1.eng) / 3;
	double averS2 = double(s2.kor + s2.math + s2.eng) / 3;

	if (averS1 > averS2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <=(Student& s1, Student& s2)
{
	double averS1 = double(s1.kor + s1.math + s1.eng) / 3;
	double averS2 = double(s2.kor + s2.math + s2.eng) / 3;

	if (averS1 <= averS2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator >=(Student& s1, Student& s2)
{
	double averS1 = double(s1.kor + s1.math + s1.eng) / 3;
	double averS2 = double(s2.kor + s2.math + s2.eng) / 3;

	if (averS1 >= averS2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator ==(Student& s1, Student& s2)
{
	double averS1 = double(s1.kor + s1.math + s1.eng) / 3;
	double averS2 = double(s2.kor + s2.math + s2.eng) / 3;

	if (averS1 == averS2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ofstream& operator << (ofstream& ofs, Student& s1)
{
	double averS1 = double(s1.kor + s1.math + s1.eng) / 3;

	ofs << averS1;

	return ofs;
}