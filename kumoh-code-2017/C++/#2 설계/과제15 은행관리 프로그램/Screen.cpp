#include"Screen.h"

Screen::Screen(){
	msg = '0';
	money = 0;
}

void Screen::displayMsg(string msg){
	cout << msg << endl;
}

void Screen::displayAmount(double money){
	cout << money << endl;
}

void Screen::displayrule(){
	cout << "===========<Online-Banking System Rule>==========" << endl;
	cout << "1.������ ������ 1.�������� 2.���̳ʽ����� �� �ֽ��ϴ�." << endl;
	cout << "2.���̳ʽ� ���忡���� �����ܰ� 0���̸��� ��쿡�� ����� �����մϴ�." << endl;
	cout << "3.���¹�ȣ�� ��й�ȣ�� ���� ������� (1,1201) (2,1202)�Դϴ�." << endl;
	cout << "4.����ݽ� �ݾ��� -999�Է��ϸ� �޴�����â���� ���ƿɴϴ�." << endl;
	cout << "�ʱ��ܰ�� �ΰ��� ��� 1000���Դϴ�." << endl;
	cout << "=================================================" << endl;
	cout << "" << endl;;
}