#include "IOHandler.h"

int IOHandler::getMenu()
{
	putString("------ ȯ�ڰ��� ���α׷� ------");
	putString("------ 1. �Կ�           ------");
	putString("------ 2. ���           ------");
	putString("------ 3. �ڷ���ȸ       ------");
	putString("------ 4. ���α׷� ����  ------");
	putString("-------------------------------");

	int menu = getInteger(" ���� : ");
	if (menu >= CHECK_IN && menu <=EXIT)
	{
		return menu;
	}
}

int IOHandler::getChoiceMenu()
{
	putString("------ �޴� ���� ------");
	putString("------ 1. Yes    ------");
	putString("------ 2. No     ------");
	putString("-----------------------");

	int menu = getInteger(" ���� : ");
	if (menu >= 1 && menu <= 2)
	{
		return menu;
	}
}

char IOHandler::getPatientInfo()
{
	char patient_info;
	while (1)
	{
		putString("ȯ�� �� ���� (1:ȯ�ڹ�ȣ, 2:����, 3:����) -> ");
		cin >> patient_info;

		if (patient_info == '1' || patient_info == '2' || patient_info == '3')
		{
			return patient_info;
		}

		putString("Invalid patient information! retry!");
	}
}

Patient IOHandler::getPatient(char patient_info)
{
	Patient p;

	if (patient_info = '1')
	{
		int id = getInteger("ȯ�ڹ�ȣ : ");
		p.id = id;
	}
	else if (patient_info = '2')
	{
		string sex = getString("���� : ");
		p.sex = sex;
	}
	else if (patient_info = '3')
	{
		string disease = getString("���� : ");
		p.disease = disease;
	}

	return p;
}

void IOHandler::putPatient(Patient p)
{
	putNewLine();
	cout << " ȯ�ڹ�ȣ : " << p.id << "\n";
	cout << " ���� : " << p.name << "\n";
	cout << " ���� : " << p.sex << "\n";
	cout << " ���� : " << p.birth << "\n";
	cout << " �޴�����ȣ : " << p.phone_number << "\n";
	cout << " �Կ��� : " << p.ad_date << "\n";
	cout << " ���� : " << p.disease << "\n";
	cout << " ���� : " << p.room << "\n";
	cout << " ��ġ�� : " << p.doctor << "\n";
	cout << " ��簣ȣ�� : " << p.nurse << "\n";
	cout << " ����� : " << p.leave_date;
	putNewLine();
}

string IOHandler::getString(string msg)
{
	string value;

	cout << msg;
	cin >> value;

	return value;
}

int IOHandler::getInteger(string msg)
{
	int value;

	cout << msg;
	cin >> value;

	return value;
}