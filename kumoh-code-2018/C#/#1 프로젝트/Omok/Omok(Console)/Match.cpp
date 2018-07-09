#include <iostream>
#include <string>
#include "Board.cpp"
using namespace std;

class match {
private:
	string firstPlayer;
	string secondPlayer;
	int turn;

	bool check1(int x, int y){
		if (omokBoard.getStone(x, y) != 0 && (y + 4) < 10) {
			return omokBoard.getStone(x, y) == omokBoard.getStone(x, y + 1) && omokBoard.getStone(x, y + 1) == omokBoard.getStone(x, y + 2) && omokBoard.getStone(x, y + 2) == omokBoard.getStone(x, y + 3) && omokBoard.getStone(x, y + 3) == omokBoard.getStone(x, y + 4);
		}
		else return false;
	};
	bool check2(int x, int y){
		if (omokBoard.getStone(x, y) != 0 && (x + 4) < 10) {
			return omokBoard.getStone(x, y) == omokBoard.getStone(x + 1, y) && omokBoard.getStone(x + 1, y) == omokBoard.getStone(x + 2, y) && omokBoard.getStone(x + 2, y) == omokBoard.getStone(x + 3, y) && omokBoard.getStone(x + 3, y) == omokBoard.getStone(x + 4, y);
		}
		else return false;
	};
	bool check3(int x, int y){
		if (omokBoard.getStone(x, y) != 0 && (x + 4) < 10 && (y + 4) < 10) {
			return omokBoard.getStone(x, y) == omokBoard.getStone(x + 1, y + 1) && omokBoard.getStone(x + 1, y + 1) == omokBoard.getStone(x + 2, y + 2) && omokBoard.getStone(x + 2, y + 2) == omokBoard.getStone(x + 3, y + 3) && omokBoard.getStone(x + 3, y + 3) == omokBoard.getStone(x + 4, y + 4);
		}
		else return false;
	};
	bool check4(int x, int y){
		if (omokBoard.getStone(x, y) != 0 && (x + 4) < 10 && (y - 4) >= 0) {
			return omokBoard.getStone(x, y) == omokBoard.getStone(x + 1, y - 1) && omokBoard.getStone(x + 1, y - 1) == omokBoard.getStone(x + 2, y - 2) && omokBoard.getStone(x + 2, y - 2) == omokBoard.getStone(x + 3, y - 3) && omokBoard.getStone(x + 3, y - 3) == omokBoard.getStone(x + 4, y - 4);
		}
		else return false;
	};

protected:
	board omokBoard;
public:
	match() { turn = 1; }
	int getTurn(){
		return turn;
	}
	void setTurn(int t){
		turn = t;
	}
	string getFirstPlayer(){
		return firstPlayer;
	}
	void setFirstPlayer(string name){
		firstPlayer = name;
	}
	string getSecondPlayer(){
		return secondPlayer;
	}
	void setSecondPlayer(string name){
		secondPlayer = name;
	}
	void registerPlayers(){
		cout << "첫 번째 플레이어의 이름은 ";
		cin >> firstPlayer;
		cout << "두 번째 플레이어의 이름은 ";
		cin >> secondPlayer;
		//turn = 1;
	}
	int getStonePosition(int &x, int &y){
		string player;
		if (turn == 1)player = firstPlayer;
		else if (turn == 2)player = secondPlayer;
		string stone;
		if (turn == 1)stone = "검은돌";
		else if (turn == 2)stone = "흰돌";
		cout << "이번에는 " << player << " 차례이며 " << stone << "입니다. 놓을 위치를 입력하세요." << endl << " 단, 게임을 종료하고 싶으면 음수의 값을 입력하세요." << endl;
		cin >> x >> y;
		if (x < 0 || y < 0)
			return -1;
		if (omokBoard.getStone(x, y) == 0) // 비어 있는 위치이면
			return 1;
		else
			return 0;
	}

	bool checkWinningCondition(){
		int x, y;
		for (x = 0; x<10; x++){
			for (y = 0; y<10; y++){
				if (check1(x, y) == true || check2(x, y) == true || check3(x, y) == true || check4(x, y) == true){
					return true;
				}
			}
		}
		return false;
	}
	void play(){
		bool flag;
		int check;
		int i, j;
		string winner;

		omokBoard.clear();
		omokBoard.display(); 
		while (true){
			check = getStonePosition(i, j);
			if (check == -1) break; // 음수값 입력 시
			else if (check == 1) { // 자리가 비어 있을 경우
				omokBoard.putStone(i, j, turn);
				omokBoard.display(); 
				flag = checkWinningCondition();

				if (flag == true){
					if (turn == 1)winner = firstPlayer;
					else winner = secondPlayer;
					cout << "축하합니다. " << winner << "이(가) 이겼습니다.";
					return;
				}
				else {
					if (turn == 1) { // 첫번째 주자이면
						cout << endl << getFirstPlayer() << "가 " << i << ", " << j << "위치에 돌을 놓았습니다." << endl;
						turn = 2;
					}
					else {
						cout << endl << getSecondPlayer() << "가 " << i << ", " << j << "위치에 돌을 놓았습니다." << endl;
						turn = 1;
					}
				}
			}
			else { // 자리가 차 있을 경우
				cout << "이미 있는 자리입니다. 다시 놓으세요." << endl;
			}
		}
	}
};