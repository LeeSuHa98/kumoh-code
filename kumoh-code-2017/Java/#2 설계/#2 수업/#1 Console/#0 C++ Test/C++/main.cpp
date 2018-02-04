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
	cout << "총 메시지의 개수는 " << machine1.getMsgNum() << "입니다." << endl;
	machine1.disconnect();
	machine1.play(); // "연결되지 않는 상태입니다."라는 메시지 출력
	machine1.connect();
	cout << "총 메시지의 개수는 " << machine1.getMsgNum() << "입니다." << endl;
	machine1.disconnect();

	system("pause");

	return 0;
}