#pragma once
#include "IoHandler.h"

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}
	// operations for file handling
	void loadBookList(string fname, BookList& b_list); // 파일을 불러오고 시작
	void saveBookList(string fname, BookList& b_list); // 파일에 저장하고 종료
};