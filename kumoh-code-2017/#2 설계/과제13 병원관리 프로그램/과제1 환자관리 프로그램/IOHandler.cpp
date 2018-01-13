#include "IOHandler.h"

int IOHandler::getMenu()
{
	putString("------ 환자관리 프로그램 ------");
	putString("------ 1. 입원           ------");
	putString("------ 2. 퇴원           ------");
	putString("------ 3. 자료조회       ------");
	putString("------ 4. 프로그램 종료  ------");
	putString("-------------------------------");

	int menu = getInteger(" 선택 : ");
	if (menu >= CHECK_IN && menu <=EXIT)
	{
		return menu;
	}
}

int IOHandler::getChoiceMenu()
{
	putString("------ 메뉴 선택 ------");
	putString("------ 1. Yes    ------");
	putString("------ 2. No     ------");
	putString("-----------------------");

	int menu = getInteger(" 선택 : ");
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
		putString("환자 상세 내역 (1:환자번호, 2:성별, 3:병명) -> ");
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
		int id = getInteger("환자번호 : ");
		p.id = id;
	}
	else if (patient_info = '2')
	{
		string sex = getString("성별 : ");
		p.sex = sex;
	}
	else if (patient_info = '3')
	{
		string disease = getString("병명 : ");
		p.disease = disease;
	}

	return p;
}

void IOHandler::putPatient(Patient p)
{
	putNewLine();
	cout << " 환자번호 : " << p.id << "\n";
	cout << " 성명 : " << p.name << "\n";
	cout << " 성별 : " << p.sex << "\n";
	cout << " 생일 : " << p.birth << "\n";
	cout << " 휴대폰번호 : " << p.phone_number << "\n";
	cout << " 입원일 : " << p.ad_date << "\n";
	cout << " 병명 : " << p.disease << "\n";
	cout << " 병실 : " << p.room << "\n";
	cout << " 주치의 : " << p.doctor << "\n";
	cout << " 담당간호사 : " << p.nurse << "\n";
	cout << " 퇴원일 : " << p.leave_date;
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