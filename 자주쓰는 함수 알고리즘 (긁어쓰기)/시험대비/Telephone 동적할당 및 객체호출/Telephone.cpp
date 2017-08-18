#include "Telephone.h"

void Telephone::connect(Telephone& p)
{
	tmp = &p;
}

void Telephone::send()
{
	try
	{
		if (tmp == NULL)
		{
			throw "DisConnected";
		}
		cout << " ���� �޼����� �Է��ϼ��� : ";
		getline(cin, message);
		tmp->setMessage(message);
	}
	catch (char* p)
	{
		cout << p << endl;
	}
}

string Telephone::receive()
{
	string tmp = message;

	cout << " ���� �޼��� : ";
	return tmp;
}

void Telephone::disconnect()
{
	tmp = NULL;
}