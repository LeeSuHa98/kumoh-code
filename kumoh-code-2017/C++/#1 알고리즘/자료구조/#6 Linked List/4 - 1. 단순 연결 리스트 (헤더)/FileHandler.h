#pragma once
#include "IoHandler.h"

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}
	// operations for file handling
	void loadBookList(string fname, BookList& b_list); // ������ �ҷ����� ����
	void saveBookList(string fname, BookList& b_list); // ���Ͽ� �����ϰ� ����
};