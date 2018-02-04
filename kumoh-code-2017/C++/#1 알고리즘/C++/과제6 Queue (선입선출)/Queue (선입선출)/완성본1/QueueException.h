#pragma once
#include "Exception.h"

class QueueException : public Exception
{
public:
	QueueException() {}
	QueueException(int code)
	{
		switch (code)
		{
		case 1:
			setStr("OverFlow"); // 큐의 공간이 포화상태
			setCode(code);
			break;
		case 2:
			setStr("UnderFlow"); // 큐의 공간이 비어있을 때
			setCode(code);
			break;
		}
	}
	~QueueException() {}
};