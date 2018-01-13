#include "FileHandler.h"

void FileHandler::loadStudent(string fileName, StudentList& s_list) // ���� �б��
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int id;
	string name;
	int kor;
	int eng;
	int math;

	while (!fin.eof()) // ������ ���� �������� �ʾҴٸ� ��� �ݺ�
	{
		fin >> id >> name >> kor >> eng >> math; // ������ ���� ����
		Student s(id, name, kor, eng, math); // Student �ӽ� ��ü ����

		s_list.insertStudent(s);
	}

	fin.close();
}

void FileHandler::saveStudent(string fileName, StudentList& s_list) // ���� �����
{
	ofstream fout;

	fout.open(fileName, ios_base::out);

	for (int i = 0; i < s_list.getCount(); i++)
	{
		fout << s_list.getStudentList(i).getId() << "\t";
		fout << s_list.getStudentList(i).getName() << "\t";
		fout << s_list.getStudentList(i).getKor() << "\t";
		fout << s_list.getStudentList(i).getMath() << "\t";
		fout << s_list.getStudentList(i).getEng() << "\t";
		fout << s_list.getStudentList(i).getAvgRecord() << "\t";
		fout << endl;
	}

	fout.close();
}
