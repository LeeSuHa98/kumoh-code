#include "TaskManager.h"

void TaskManager::admissionPatient(PatientList& p_list)
{
	IOHandler ioh;
	FileHandler foh;

	ioh.putString("�Կ��� ȯ���� ��ȣ�� �˻��մϴ�. ");
	ioh.putNewLine();
	int id = ioh.getInteger("ȯ�� ��ȣ : ");

	int index = p_list.findPatient(id);
	if (index == NOT_FOUND) // ȯ�� ���翩�� ����ó��
	{
		ioh.putString("Patient dose not exist!");

		return;
	}

	ioh.putString("ȯ���� ����, ��ġ��, ��簣ȣ�縦 �����մϴ�. ");
	ioh.putNewLine();

	string room = ioh.getString("���� : "); // ����
	string doctor = ioh.getString("��ġ�� : "); // ��ġ��
	string nurse = ioh.getString("��簣ȣ�� : "); // ��簣ȣ��

	p_list.setPatient(index, room, doctor, nurse);
}

void TaskManager::leavePatient(PatientList& p_list)
{
	IOHandler ioh;
	
	ioh.putString("------ ȯ���� �Ż��ڷ� ------");
	for (int i = 0; i < p_list.getCount(); i++)
	{
		Patient p = p_list.getPatientList(i);
		ioh.putPatient(p);
	}
	
	ioh.putString("����� ȯ���� ������� �˻��մϴ�. ");
	ioh.putNewLine();
	string leave_date = ioh.getString("����� : ");

	int index = p_list.findLeaveDate(leave_date);
	if (index == NOT_FOUND) // ȯ�� ���翩�� ����ó��
	{
		ioh.putString("Patient dose not exist!");

		return;
	}

	p_list.deletePatient(index);
}

void TaskManager::displayPatient(PatientList p_list)
{
	IOHandler ioh;
	FileHandler foh;

	ioh.putString("ȯ�� ��θ� ��ȸ�մϴ�.");
	ioh.putNewLine();
	ioh.putString("------ ��ü ȯ�� ��� ------");
	ioh.putNewLine();

	for (int i = 0; i < p_list.getCount(); i++)
	{
		cout << "ȯ�ڹ�ȣ : " << p_list.getPatientList(i).id << endl;
		cout << "���� : " << p_list.getPatientList(i).name << endl;
		cout << "���� : " << p_list.getPatientList(i).sex << endl;
		cout << "������� : " << p_list.getPatientList(i).birth << endl;
		cout << "�޴�����ȣ : " << p_list.getPatientList(i).phone_number << endl;
		cout << "�Կ��� : " << p_list.getPatientList(i).ad_date << endl;
		cout << "���� : " << p_list.getPatientList(i).disease << endl;
		cout << "���� : " << p_list.getPatientList(i).room << endl;
		cout << "��ġ�� : " << p_list.getPatientList(i).doctor << endl;
		cout << "��簣ȣ�� : " << p_list.getPatientList(i).nurse << endl;
		cout << "����� : " << p_list.getPatientList(i).leave_date << endl;
	}

	ioh.putString("ȯ�� ������ �����մϴ�.");
	int menu = ioh.getChoiceMenu(); // Yes or No

	if (menu == YES)
	{
		ioh.putString("������ ȯ���� ��ȣ�� �˻��մϴ�. ");
		ioh.putNewLine();
		int id = ioh.getInteger("ȯ�� ��ȣ : ");

		int index = p_list.findPatient(id);
		if (index == NOT_FOUND) // ȯ�� ���翩�� ����ó��
		{
			ioh.putString("Patient dose not exist!");

			return;
		}

		char patient_info = ioh.getPatientInfo();
		Patient p = ioh.getPatient(patient_info);

		p_list.updatePatient(index, p);
	}
	else if (menu == NO)
	{
		return;
	}
}