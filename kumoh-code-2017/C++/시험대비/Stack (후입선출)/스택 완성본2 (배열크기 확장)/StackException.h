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
			setStr("OverFlow"); // 스택의 공간이 포화상태
			setCode(code);
			break;
		case 2:
			setStr("UnderFlow"); // 스택의 공간이 비어있을 때
			setCode(code);
			break;
		}
	}
	~StackException() {}
};