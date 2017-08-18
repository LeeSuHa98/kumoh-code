#include "Date.h"
#include "Time.h"
#include "Now.h"

int main()
{
	Date d(2015, 1, 2);
	Time t(12, 30, 58);
	Now n1(2015, 1, 2, 12, 30, 58, 99);
	Now n2(2015, 1, 2, 12, 30, 58, 99, true);

	d.print(); // 2015-1-2
	t.print(); // 12:30:58
	n1.print(); // ������ 2015�� 1�� 2�� 12�� 30�� 58�� 99�и����Դϴ�.
	n2.print(); // Now is 2015-1-2, 12:30:58:99

	return 0;
}