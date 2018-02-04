#pragma once
#include "Exception.h"

class StackException : public Exception
{
public:
	StackException() {}
	StackException(int code)
	{
		switch (code)
		{
		case 1:
			setStr("overflow"); // ������ ������ ��ȭ����
			break;
		case 2:
			setStr("underflow"); // ������ ������ ������� ��
			break;
		}
	}
	~StackException() {}
};