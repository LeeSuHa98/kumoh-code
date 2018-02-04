#include "TaskManager.h"

void TaskManager::registerBook(BookList& b_list)
{
	IoHandler ioh;
	Book* b = ioh.getBook();
	b_list.insertBook(b);
}

void TaskManager::unregisterBook(BookList& b_list)
{
	IoHandler ioh;
	string book_no = ioh.getString("������ȣ�� �Է��ϼ��� : ");
	b_list.deleteBook(book_no);
}

void TaskManager::printBook(BookList& b_list)
{
	b_list.displayBook();
}