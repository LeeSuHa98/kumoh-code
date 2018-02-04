#include "TaskManager.h"

void TaskManager::admissionPatient(PatientList& p_list)
{
	IOHandler ioh;
	FileHandler foh;

	ioh.putString("입원할 환자의 번호를 검색합니다. ");
	ioh.putNewLine();
	int id = ioh.getInteger("환자 번호 : ");

	int index = p_list.findPatient(id);
	if (index == NOT_FOUND) // 환자 존재여부 예외처리
	{
		ioh.putString("Patient dose not exist!");

		return;
	}

	ioh.putString("환자의 병실, 주치의, 담당간호사를 배정합니다. ");
	ioh.putNewLine();

	string room = ioh.getString("병실 : "); // 병실
	string doctor = ioh.getString("주치의 : "); // 주치의
	string nurse = ioh.getString("담당간호사 : "); // 담당간호사

	p_list.setPatient(index, room, doctor, nurse);
}

void TaskManager::leavePatient(PatientList& p_list)
{
	IOHandler ioh;
	
	ioh.putString("------ 환자의 신상자료 ------");
	for (int i = 0; i < p_list.getCount(); i++)
	{
		Patient p = p_list.getPatientList(i);
		ioh.putPatient(p);
	}
	
	ioh.putString("퇴원할 환자의 퇴원일을 검색합니다. ");
	ioh.putNewLine();
	string leave_date = ioh.getString("퇴원일 : ");

	int index = p_list.findLeaveDate(leave_date);
	if (index == NOT_FOUND) // 환자 존재여부 예외처리
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

	ioh.putString("환자 명부를 조회합니다.");
	ioh.putNewLine();
	ioh.putString("------ 전체 환자 명단 ------");
	ioh.putNewLine();

	for (int i = 0; i < p_list.getCount(); i++)
	{
		cout << "환자번호 : " << p_list.getPatientList(i).id << endl;
		cout << "성명 : " << p_list.getPatientList(i).name << endl;
		cout << "성별 : " << p_list.getPatientList(i).sex << endl;
		cout << "생년월일 : " << p_list.getPatientList(i).birth << endl;
		cout << "휴대폰번호 : " << p_list.getPatientList(i).phone_number << endl;
		cout << "입원일 : " << p_list.getPatientList(i).ad_date << endl;
		cout << "병명 : " << p_list.getPatientList(i).disease << endl;
		cout << "병실 : " << p_list.getPatientList(i).room << endl;
		cout << "주치의 : " << p_list.getPatientList(i).doctor << endl;
		cout << "담당간호사 : " << p_list.getPatientList(i).nurse << endl;
		cout << "퇴원일 : " << p_list.getPatientList(i).leave_date << endl;
	}

	ioh.putString("환자 정보를 수정합니다.");
	int menu = ioh.getChoiceMenu(); // Yes or No

	if (menu == YES)
	{
		ioh.putString("수정할 환자의 번호를 검색합니다. ");
		ioh.putNewLine();
		int id = ioh.getInteger("환자 번호 : ");

		int index = p_list.findPatient(id);
		if (index == NOT_FOUND) // 환자 존재여부 예외처리
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