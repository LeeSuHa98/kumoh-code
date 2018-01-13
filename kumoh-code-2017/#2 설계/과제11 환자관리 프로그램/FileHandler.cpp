#include "FileHandler.h"

void FileHandler::loadPatient(string fileName, PatientList& p_list) // ���� �б��
{
	IOHandler ioh;
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int id; // ȯ�ڹ�ȣ
	string name; // ����
	string sex; // ����
	int birth; // ����
	string phone_number; // �޴�����ȣ
	string ad_date; // �Կ���
	string disease; // ����
	string room; // ����
	string doctor; // ��ġ��
	string nurse; // ��簣ȣ��
	string leave_date; // �����
	
	while (!fin.eof()) // ������ ���� �������� �ʾҴٸ� ��� �ݺ�
	{
		fin >> id >> name >> sex >> birth >> phone_number >> ad_date >> disease >> leave_date; // ������ ���� ����
		Patient p(id, name, sex, birth, phone_number, ad_date, disease, room, doctor, nurse, leave_date); // ������

		int index = p_list.findLeaveDate(leave_date);
		if (index != NOT_FOUND) // �ߺ� ����ó��
		{
			ioh.putString("Already exists!"); // �̹� �����Ѵ�

			return;
		}
		p_list.insertPatient(p);
	}

	fin.close();
}

void FileHandler::savePatient(string fileName, PatientList& p_list) // ���� �����
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