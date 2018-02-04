#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_COUNT = 10;

class AAM
{
private:
	string* msg;
	int count;
	string message;
public:
	AAM() 
	{
		msg = new string[MAX_COUNT];
		count = 0;
	}
	~AAM() { delete[] msg; }

	void connect();	// �ʱ� �޽���("���� �Ǿ����ϴ�")�� ȭ�鿡 ����ϰ� ���� ���� ����(����Ǿ��ٰ� ���������� ǥ��)
	void record();	// �Է� �ȳ���("���� �޽��� : ")�� ����ϰ� �޽����� Ű���带 ���� �Է¹���
	void play();
	void play(int n);
	int getMsgNum();	// ����Ǿ� �ִ� �޽��� ������ ���� ��
	void movePos(int n);	// n ��° �޽����� �̵�
	void deleteMsg();	// �� ��ġ�� �޽��� ����
	void disconnect();	// ���� ����
};