#include "TaskManager.h"
#include "ioHandler.h"

void TaskManager::registerPerson(PersonList& p_list)
{
	ioHandler ioh;

	ioh.putString(" �л� ������ ����մϴ� ");

	string name = ioh.getString(" �̸� : ");

	while (p_list.findPerson(name) != NOT_FOUND)
	{
		ioh.putString(" ������ �̸��Դϴ�. �ٽ� �Է����ֽʽÿ�. ");
		name = ioh.getString(" �̸� : ");
	}
	Person p = ioh.getStudent(name, p_list);

	//int index = p_list.findPerson(p.getName());

	//if (index != NOT_FOUND)
	//{
	//	ioh.putString(" ������ �̸��Դϴ�. �ٽ� �Է����ֽʽÿ�. ");
	//	return;
	//}
	p_list.inputPerson(p); // �������� ������ �迭 �Լ��� ����
}

void TaskManager::unregisterPerson(PersonList& p_list)
{
	ioHandler ioh;

	ioh.putString(" �л� ������ �����մϴ� ");

	string name = ioh.getString(" ������ �л��� �̸��� �Է��Ͻÿ� : ");

	int index = p_list.findPerson(name);
	if (index == NOT_FOUND)
	{
		ioh.putString(" �������� �ʴ� �л��Դϴ�. �ٽ� �Է����ֽʽÿ�. ");
		return;
	}
	p_list.deletePerson(index);
}

void TaskManager::displayPerson(PersonList p_list)
{
	ioHandler ioh;

	ioh.putString(" �л� ������ ����մϴ� ");

	for (int i = 0; i < p_list.getCount(); i++) // ����� ��� ���ֱ� ���� �ݺ�
	{
		Person p = p_list.getPersonList(i);
		ioh.putStudent(p);
	}
}