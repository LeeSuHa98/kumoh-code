#include "AAM.h"

void AAM::connect()
{
	cout << "���� �Ǿ����ϴ�" << endl;
}

void AAM::record()
{
	try
	{
		cout << "���� �޽���: ";

		if (msg == nullptr)
		{
			throw "DisConnected";
		}
		else if (count > MAX_COUNT)
		{
			cout << "�޽����� �ִ� 10�� ���� ���� ����" << endl;
			throw "DisConnected";
		}
		getline(cin, message);

		msg[count] = message;

		count++;
	}
	catch (char* p)
	{
		cout << p << endl;
	}
}

void AAM::play()
{
	if (msg == nullptr)
	{
		cout << "������� �ʴ� �����Դϴ�." << endl;
	}
	else
	{
		cout << "���� �޽��� : " << message << endl;
	}
}

void AAM::play(int n)
{
	cout << n+1 << "��° �޽��� : " << msg[n] << endl;
}

int AAM::getMsgNum()
{
	return count;
}

void AAM::movePos(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << n << "��° �޽����� �̵� : " << msg[n-1] << endl;
	}
}

void AAM::deleteMsg()
{
	delete[] msg;
}

void AAM::disconnect()
{
	cout << "Disconnect" << endl;
	msg = nullptr;
	count = NULL;
}