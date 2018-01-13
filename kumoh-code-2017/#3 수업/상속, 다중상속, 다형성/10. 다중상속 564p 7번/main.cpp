#include "Student.h"
#include "Employee.h"
#include "UnderGraduate.h"
#include "Graduate.h"
#include "IndustrialGraduate.h"

int main()
{
	UnderGraduate u("xx", 2001001, "컴소", 1, 50, "비트"); // 이름, 학번, 학과, 학년, 이수학점, 동아리
	u.print();

	Graduate g("yy", 100, "ah", 1, 20, "교육조교", 0);
	g.print();

	IndustrialGraduate i("손우규", 20120691, "컴소공", 2, 100, "교육조교", 200, "소프트웨어");
	i.Graduate::print();
	i.Employee::print();
}