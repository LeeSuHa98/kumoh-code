#pragma once
#include "Word.h"

class WordList
{
private:
	vector <Word> v_list;
	int count;
public:
	WordList() { count = 0; }
	~WordList() {}
	// ���� ����
	void insertWord();
	// ���� �׽�Ʈ
	void testWord();
};