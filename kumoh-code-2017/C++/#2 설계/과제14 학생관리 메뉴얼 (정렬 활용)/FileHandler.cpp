#include "FileHandler.h"

void FileHandler::loadStudent(string fileName, StudentList& s_list) // 파일 읽기용
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	int id;
	string name;
	int kor;
	int eng;
	int math;

	while (!fin.eof()) // 파일의 끝에 도달하지 않았다면 계속 반복
	{
		fin >> id >> name >> kor >> eng >> math; // 파일의 값을 읽음
		Student s(id, name, kor, eng, math); // Student 임시 객체 생성

		s_list.insertStudent(s);
	}

	fin.close();
}

void FileHandler::saveStudent(string fileName, StudentList& s_list) // 파일 쓰기용
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
