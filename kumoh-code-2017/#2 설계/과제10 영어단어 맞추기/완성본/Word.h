#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Word
{
private:
	string eng_word;
	string kor_word;
public:
	Word() {}
	Word(string eng_word, string kor_word)
	{
		this->eng_word = eng_word;
		this->kor_word = kor_word;
	}
	~Word() {}

	string getEngWord() { return eng_word; }
	string getKorWord() { return kor_word; }
};