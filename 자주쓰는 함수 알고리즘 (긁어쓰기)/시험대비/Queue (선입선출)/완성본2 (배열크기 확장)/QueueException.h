#pragma once
#include "Exception.h"

class QueueException : public Exception
{
private:
	Exception e;
public:
	QueueException() {}
	QueueException(int code)
	{
		switch (code)
		{
		case 1:
			setStr("OverFlow"); // ť�� ������ ��ȭ����
			setCode(code);
			break;
		case 2:
			setStr("UnderFlow"); // ť�� ������ ������� ��
			setCode(code);
			break;
		}
	}
	~QueueException() {}
};