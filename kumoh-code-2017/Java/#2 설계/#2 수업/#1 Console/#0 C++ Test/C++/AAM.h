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

	void connect();	// 초기 메시지("연결 되었습니다")를 화면에 출력하고 연결 상태 유지(연결되었다고 내부적으로 표시)
	void record();	// 입력 안내문("전달 메시지 : ")을 출력하고 메시지를 키보드를 통해 입력받음
	void play();
	void play(int n);
	int getMsgNum();	// 저장되어 있는 메시지 개수를 돌려 줌
	void movePos(int n);	// n 번째 메시지로 이동
	void deleteMsg();	// 현 위치의 메시지 삭제
	void disconnect();	// 연결 해제
};