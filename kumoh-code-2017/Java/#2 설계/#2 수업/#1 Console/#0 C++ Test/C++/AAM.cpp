#include "AAM.h"

void AAM::connect()
{
	cout << "연결 되었습니다" << endl;
}

void AAM::record()
{
	try
	{
		cout << "전달 메시지: ";

		if (msg == nullptr)
		{
			throw "DisConnected";
		}
		else if (count > MAX_COUNT)
		{
			cout << "메시지는 최대 10개 까지 저장 가능" << endl;
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
		cout << "연결되지 않는 상태입니다." << endl;
	}
	else
	{
		cout << "받은 메시지 : " << message << endl;
	}
}

void AAM::play(int n)
{
	cout << n+1 << "번째 메시지 : " << msg[n] << endl;
}

int AAM::getMsgNum()
{
	return count;
}

void AAM::movePos(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << n << "번째 메시지로 이동 : " << msg[n-1] << endl;
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