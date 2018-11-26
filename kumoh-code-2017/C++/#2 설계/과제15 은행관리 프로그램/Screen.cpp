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
	cout << "1.계좌의 종류는 1.자유계좌 2.마이너스계좌 가 있습니다." << endl;
	cout << "2.마이너스 통장에서만 현재잔고가 0원미만인 경우에도 출금이 가능합니다." << endl;
	cout << "3.계좌번호와 비밀번호는 각각 순서대로 (1,1201) (2,1202)입니다." << endl;
	cout << "4.입출금시 금액을 -999입력하면 메뉴선택창으로 돌아옵니다." << endl;
	cout << "초기잔고는 두계좌 모두 1000원입니다." << endl;
	cout << "=================================================" << endl;
	cout << "" << endl;;
}