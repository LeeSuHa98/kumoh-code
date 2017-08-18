#include "PersonList.h"

int PersonList::findPerson(string name)
{
	for (int i = 0; i < count; i++)
	{
		if (name == person_list[i].getName())
		{
			return i;
		}
	}
	return NOT_FOUND; // 반환값 : 해당 학생이 있으면 인덱스, 없으면 NOT_FOUND를 반환
}

void PersonList::inputPerson()
{
	cout << " 학생의 정보를 등록합니다 " << endl;

	string name;
	int korean;
	int english;
	int math;

	cout << " 이름 : ";
	cin >> name;
	cout << " 국어 성적 : ";
	cin >> korean;
	cout << " 영어 성적 : ";
	cin >> english;
	cout << " 수학 성적 : ";
	cin >> math;

	Person p(name, korean, english, math);

	// 예외처리
	if (count >= MAX_PERSON)
	{
		cout << "학생 수는 " << MAX_PERSON << "명을 초과할 수 없습니다!!" << endl;
		return;
	}
	else if (findPerson(name) == NOT_FOUND)
	{
		person_list[count] = p;
		count++;
	}
	else
	{
		cout << " 동일한 이름입니다. 다시 입력해주십시오. " << endl;
	}
}

void PersonList::deletePerson()
{
	cout << " 학생의 정보를 삭제합니다 " << endl;

	string name;

	cout << " 삭제할 학생의 이름을 입력하시오 : ";
	cin >> name;

	for (int i = findPerson(name); i < count; i++)
	{
		person_list[i + 1];
	}

	count--;
}

void PersonList::displayPerson()
{
	cout << " 학생의 정보를 출력합니다 " << endl;

	for (int i = 0; i < count; i++)
	{
		cout << " 이름 : " << person_list[i].getName() << endl;
		cout << " 국어 성적 : " << person_list[i].getKorean() << endl;
		cout << " 영어 성적 : " << person_list[i].getEnglish() << endl;
		cout << " 수학 성적 : " << person_list[i].getMath() << endl;
		cout << " 학생 평균 성적 : " << person_list[i].getAverage() << endl;
		cout << " 학생 등급 : " << person_list[i].getGrade() << endl;
		cout << endl;
	}
}