#pragma once
#include "IoHandler.h"
class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}
	// 새 도서 입력
	void registerBook(BookList& b_list);
	// 도서 삭제
	void unregisterBook(BookList& b_list);
	// 도서명 순으로 전체 출력
	void printBook(BookList& b_list);
};