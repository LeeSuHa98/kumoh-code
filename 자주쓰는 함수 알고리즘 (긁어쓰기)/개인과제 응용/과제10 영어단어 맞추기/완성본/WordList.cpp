#include "WordList.h"

void WordList::insertWord()
{
	string eng_word;
	string kor_word;

	cout << " ���� �߰��� �����մϴ�. (����� ����ܾ exit�� �Է�) " << endl;
	cout << " ----- �ּ� 4�� �̻��� �ܾ �Է��Ͻÿ�. -----" << endl;

	while (1)
	{
		cout << " ����ܾ� : ";
		cin >> eng_word;

		if (eng_word == "exit")
		{
			break;
		}

		cout << " �ѱ۴ܾ� : ";
		cin >> kor_word;

		Word w(eng_word, kor_word);
		v_list.push_back(w);

		count++;
	}
}

void WordList::testWord()
{
	cout << " ���� �׽�Ʈ�� �����մϴ�. (����� 0 �Է�)" << endl;

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
		for (int i = 0; i < 4; i++) // ���� 4������ �ݺ�
		{
			do {
				index2 = rand() % count;
			} while (checkList[index2] == true); // ������ ��ġ�� ���� ������ �ݺ�
			checkList[index2] = true;
			answerList[i] = index2;

			cout << "(" << (i + 1) << ")" << v_list[index2].getKorWord() << endl;

			index2 = rand() % count;
		}

		break;
	}

	int answer;

	cout << " ������ �Է��Ͻÿ� : ";
	cin >> answer;

	if (answerList[answer - 1] == index)
	{
		cout << "�����Դϴ�!" << endl;
	}
	else
	{
		cout << "Ʋ�Ƚ��ϴ�!" << endl;
	}
	delete[] checkList;
	

}