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
	// 도서명 역순으로 전체 출력
	void printReverseBook(BookList& b_list);
	// 특정 도서명부터 전체 출력
	void printFindBook(BookList& b_list);
	// 특정 도서명부터 첫 도서명까지 역순 출력
	void printReverseFindBook(BookList& b_list);
};