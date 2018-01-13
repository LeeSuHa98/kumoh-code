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
	// ������ �������� ��ü ���
	void printReverseBook(BookList& b_list);
	// Ư�� ��������� ��ü ���
	void printFindBook(BookList& b_list);
	// Ư�� ��������� ù ��������� ���� ���
	void printReverseFindBook(BookList& b_list);
};