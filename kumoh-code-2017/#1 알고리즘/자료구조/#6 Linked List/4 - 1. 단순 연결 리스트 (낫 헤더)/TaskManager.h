#pragma once
#include "IoHandler.h"
class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}
	// �� ���� �Է�
	void registerBook(BookList& b_list);
	// ���� ����
	void unregisterBook(BookList& b_list);
	// ������ ������ ��ü ���
	void printBook(BookList& b_list);
};