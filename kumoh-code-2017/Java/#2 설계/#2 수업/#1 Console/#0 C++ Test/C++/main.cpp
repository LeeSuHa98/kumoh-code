#include "AAM.h"

int main()
{
	AAM machine1;
	machine1.connect();
	machine1.record();
	machine1.play();
	machine1.record();
	machine1.record();

	int c = machine1.getMsgNum();
	for (int i = 0; i < c; i++) machine1.play(i);
	machine1.movePos(1);
	machine1.deleteMsg();
	cout << "�� �޽����� ������ " << machine1.getMsgNum() << "�Դϴ�." << endl;
	machine1.disconnect();
	machine1.play(); // "������� �ʴ� �����Դϴ�."��� �޽��� ���
	machine1.connect();
	cout << "�� �޽����� ������ " << machine1.getMsgNum() << "�Դϴ�." << endl;
	machine1.disconnect();

	system("pause");

	return 0;
}