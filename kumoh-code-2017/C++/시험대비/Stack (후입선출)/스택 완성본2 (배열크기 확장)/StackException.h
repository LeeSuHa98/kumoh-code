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
			setStr("OverFlow"); // ������ ������ ��ȭ����
			setCode(code);
			break;
		case 2:
			setStr("UnderFlow"); // ������ ������ ������� ��
			setCode(code);
			break;
		}
	}
	~StackException() {}
};