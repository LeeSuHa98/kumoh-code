#include "PersonList.h"

int PersonList::findPerson(string name)
{
	// 학생 정보 검색
	for (int i = 0; i < count; i++)
	{
		if (name == person_list[i].getName()) // id에 저장된 값(입력 값) == 출력된 값
		{
			return i; // 검색해서 찾은 값을 반환
		}
	}
	return NOT_FOUND; // 반환값 : 해당 학생이 있으면 인덱스, 없으면 NOT_FOUND를 반환
}

void PersonList::inputPerson(Person p)
{
	if (count >= MAX_PERSON)
	{
		cout << "학생 수는 " << MAX_PERSON << "명을 초과할 수 없습니다!!" << endl;
		return;
	}

	person_list[count] = p; // 생성자의 내용을 배열에 삽입할 수 있게 객체 생성

	count++; // 다음 공간에 삽입할 수 있게 증가
}

void PersonList::deletePerson(int index)
{
	person_list[index] = person_list[count - 1]; // 전의 공간에 다음 공간을 덮어 씌워준다

	count--; // 다음 공간에 삽입할 수 있게 증가된 공간이 비어있기 때문에 입력된 내용까지만 보여주기 위해 감소
}