#include "Telephone.h"

int main()
{
	Telephone t1("451-0173"), t2("467-4277"), t3("467-4271"); // ������ 3��

	t1.connect(t2); // ���� ����� ��ȭ ��ü, �� t2�� t1�� ������ ����� ����
	t1.send(); // ����ڿ��� �޽����� ���� ��, �̸� ���� ��ȭ ��ü�� �޽��� �κп� ����
	cout << t2.receive() << endl; // �� �޽����� ȭ�鿡 ����ϰ� �޽��� clear
	t1.send();
	cout << t2.receive() << endl;
	t1.disconnect(); // gus ���� ��ü ���� ����

	t1.connect(t3);
	t1.send();
	cout << t3.receive() << endl;
	t1.disconnect();

	return 0;
}