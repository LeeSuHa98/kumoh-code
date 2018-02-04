#include "Telephone.h"

int main()
{
	Telephone t1("451-0173"), t2("467-4277"), t3("467-4271"); // 생성자 3점

	t1.connect(t2); // 현재 연결된 전화 객체, 즉 t2를 t1의 데이터 멤버에 유지
	t1.send(); // 사용자에게 메시지를 받은 후, 이를 연결 전화 객체의 메시지 부분에 저장
	cout << t2.receive() << endl; // 현 메시지를 화면에 출력하고 메시지 clear
	t1.send();
	cout << t2.receive() << endl;
	t1.disconnect(); // gus 연결 객체 정보 삭제

	t1.connect(t3);
	t1.send();
	cout << t3.receive() << endl;
	t1.disconnect();

	return 0;
}