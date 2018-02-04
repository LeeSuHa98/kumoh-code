#include "WordList.h"

void WordList::insertWord()
{
	string eng_word;
	string kor_word;

	cout << " 어휘 추가를 시작합니다. (종료는 영어단어에 exit를 입력) " << endl;
	cout << " ----- 최소 4개 이상의 단어를 입력하시오. -----" << endl;

	while (1)
	{
		cout << " 영어단어 : ";
		cin >> eng_word;

		if (eng_word == "exit")
		{
			break;
		}

		cout << " 한글단어 : ";
		cin >> kor_word;

		Word w(eng_word, kor_word);
		v_list.push_back(w);

		count++;
	}
}

void WordList::testWord()
{
	cout << " 어휘 테스트를 시작합니다. (종료는 0 입력)" << endl;

	int index = rand() % count;
	int index2;
	bool *checkList = new bool[count];
	int answerList[4];

	while (1)
	{
		cout << v_list[index].getEngWord() << "?" << endl;
		
		for (int i = 0; i < count; ++i)
		{
			checkList[i] = false;
		}
		for (int i = 0; i < 4; i++) // 보기 4개까지 반복
		{
			do {
				index2 = rand() % count;
			} while (checkList[index2] == true); // 정답이 겹치지 않을 때까지 반복
			checkList[index2] = true;
			answerList[i] = index2;

			cout << "(" << (i + 1) << ")" << v_list[index2].getKorWord() << endl;

			index2 = rand() % count;
		}

		break;
	}

	int answer;

	cout << " 정답을 입력하시오 : ";
	cin >> answer;

	if (answerList[answer - 1] == index)
	{
		cout << "정답입니다!" << endl;
	}
	else
	{
		cout << "틀렸습니다!" << endl;
	}
	delete[] checkList;
	

}