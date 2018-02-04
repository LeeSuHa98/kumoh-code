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
			setStr("overflow"); // 스택의 공간이 포화상태
			break;
		case 2:
			setStr("underflow"); // 스택의 공간이 비어있을 때
			break;
		}
	}
	~StackException() {}
};