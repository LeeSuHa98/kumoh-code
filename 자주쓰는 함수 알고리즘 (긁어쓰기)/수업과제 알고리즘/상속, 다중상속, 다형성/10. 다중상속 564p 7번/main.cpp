#include "Student.h"
#include "Employee.h"
#include "UnderGraduate.h"
#include "Graduate.h"
#include "IndustrialGraduate.h"

int main()
{
	UnderGraduate u("xx", 2001001, "�ļ�", 1, 50, "��Ʈ"); // �̸�, �й�, �а�, �г�, �̼�����, ���Ƹ�
	u.print();

	Graduate g("yy", 100, "ah", 1, 20, "��������", 0);
	g.print();

	IndustrialGraduate i("�տ��", 20120691, "�ļҰ�", 2, 100, "��������", 200, "����Ʈ����");
	i.Graduate::print();
	i.Employee::print();
}