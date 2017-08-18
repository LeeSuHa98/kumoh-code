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
		cout << " 보낼 메세지를 입력하세요 : ";
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

	cout << " 받은 메세지 : ";
	return tmp;
}

void Telephone::disconnect()
{
	tmp = NULL;
}