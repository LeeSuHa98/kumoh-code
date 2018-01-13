#include "FileHandler.h"

void FileHandler::loadPatient(string fileName, PatientList& p_list) // 파일 읽기용
{
	IOHandler ioh;
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int id; // 환자번호
	string name; // 성명
	string sex; // 성별
	int birth; // 생일
	string phone_number; // 휴대폰번호
	string ad_date; // 입원일
	string disease; // 병명
	string room; // 병실
	string doctor; // 주치의
	string nurse; // 담당간호사
	string leave_date; // 퇴원일
	
	while (!fin.eof()) // 파일의 끝에 도달하지 않았다면 계속 반복
	{
		fin >> id >> name >> sex >> birth >> phone_number >> ad_date >> disease >> leave_date; // 파일의 값을 읽음
		Patient p(id, name, sex, birth, phone_number, ad_date, disease, room, doctor, nurse, leave_date); // 생성자

		int index = p_list.findLeaveDate(leave_date);
		if (index != NOT_FOUND) // 중복 예외처리
		{
			ioh.putString("Already exists!"); // 이미 존재한다

			return;
		}
		p_list.insertPatient(p);
	}

	fin.close();
}

void FileHandler::savePatient(string fileName, PatientList& p_list) // 파일 쓰기용
{
	ofstream fout;
	fout.open(fileName, ios_base::out);

	for (int i = 0; i < p_list.getCount(); i++)
	{
		fout << p_list.getPatientList(i).id << "\t";
		fout << p_list.getPatientList(i).name << "\t";
		fout << p_list.getPatientList(i).sex << "\t";
		fout << p_list.getPatientList(i).birth << "\t";
		fout << p_list.getPatientList(i).phone_number << "\t";
		fout << p_list.getPatientList(i).ad_date << "\t";
		fout << p_list.getPatientList(i).disease << "\t";
		fout << p_list.getPatientList(i).room << "\t";
		fout << p_list.getPatientList(i).doctor << "\t";
		fout << p_list.getPatientList(i).nurse << "\t";
		fout << p_list.getPatientList(i).leave_date << "\t";
		fout << endl;
	}

	fout.close();
}