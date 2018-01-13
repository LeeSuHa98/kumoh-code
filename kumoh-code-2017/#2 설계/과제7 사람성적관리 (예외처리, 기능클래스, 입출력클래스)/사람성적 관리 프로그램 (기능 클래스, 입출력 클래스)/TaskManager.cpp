#include "TaskManager.h"
#include "ioHandler.h"

void TaskManager::registerPerson(PersonList& p_list)
{
	ioHandler ioh;

	ioh.putString(" 학생 정보를 등록합니다 ");

	string name = ioh.getString(" 이름 : ");

	while (p_list.findPerson(name) != NOT_FOUND)
	{
		ioh.putString(" 동일한 이름입니다. 다시 입력해주십시오. ");
		name = ioh.getString(" 이름 : ");
	}
	Person p = ioh.getStudent(name, p_list);

	//int index = p_list.findPerson(p.getName());

	//if (index != NOT_FOUND)
	//{
	//	ioh.putString(" 동일한 이름입니다. 다시 입력해주십시오. ");
	//	return;
	//}
	p_list.inputPerson(p); // 생성자의 내용을 배열 함수에 삽입
}

void TaskManager::unregisterPerson(PersonList& p_list)
{
	ioHandler ioh;

	ioh.putString(" 학생 정보를 삭제합니다 ");

	string name = ioh.getString(" 삭제할 학생의 이름을 입력하시오 : ");

	int index = p_list.findPerson(name);
	if (index == NOT_FOUND)
	{
		ioh.putString(" 존재하지 않는 학생입니다. 다시 입력해주십시오. ");
		return;
	}
	p_list.deletePerson(index);
}

void TaskManager::displayPerson(PersonList p_list)
{
	ioHandler ioh;

	ioh.putString(" 학생 정보를 출력합니다 ");

	for (int i = 0; i < p_list.getCount(); i++) // 출력을 계속 해주기 위해 반복
	{
		Person p = p_list.getPersonList(i);
		ioh.putStudent(p);
	}
}