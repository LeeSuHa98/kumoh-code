#include "StudentList.h"

void StudentList::insertStudent(Student s)
{
	student_list[count] = s; // 생성자의 내용을 배열에 삽입할 수 있게 객체 생성

	count++; // 다음 공간에 삽입할 수 있게 증가
}

void StudentList::deleteStudent(int index)
{
	student_list[index] = student_list[index + 1]; // 전의 공간에 다음 공간을 덮어 씌워준다

	count--; // 다음 공간에 삽입할 수 있게 증가된 공간이 비어있기 때문에 입력된 내용까지만 보여주기 위해 감소
}

void StudentList::updateStudent(int index , Student s)
{
	student_list[index] = s; // 학생 정보 검색코드가 들어갈 수 있는 공간의 Index를 생성
}