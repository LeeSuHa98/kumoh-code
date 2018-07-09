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
		cout << "ù ��° �÷��̾��� �̸��� ";
		cin >> firstPlayer;
		cout << "�� ��° �÷��̾��� �̸��� ";
		cin >> secondPlayer;
		//turn = 1;
	}
	int getStonePosition(int &x, int &y){
		string player;
		if (turn == 1)player = firstPlayer;
		else if (turn == 2)player = secondPlayer;
		string stone;
		if (turn == 1)stone = "������";
		else if (turn == 2)stone = "��";
		cout << "�̹����� " << player << " �����̸� " << stone << "�Դϴ�. ���� ��ġ�� �Է��ϼ���." << endl << " ��, ������ �����ϰ� ������ ������ ���� �Է��ϼ���." << endl;
		cin >> x >> y;
		if (x < 0 || y < 0)
			return -1;
		if (omokBoard.getStone(x, y) == 0) // ��� �ִ� ��ġ�̸�
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
			if (check == -1) break; // ������ �Է� ��
			else if (check == 1) { // �ڸ��� ��� ���� ���
				omokBoard.putStone(i, j, turn);
				omokBoard.display(); 
				flag = checkWinningCondition();

				if (flag == true){
					if (turn == 1)winner = firstPlayer;
					else winner = secondPlayer;
					cout << "�����մϴ�. " << winner << "��(��) �̰���ϴ�.";
					return;
				}
				else {
					if (turn == 1) { // ù��° �����̸�
						cout << endl << getFirstPlayer() << "�� " << i << ", " << j << "��ġ�� ���� ���ҽ��ϴ�." << endl;
						turn = 2;
					}
					else {
						cout << endl << getSecondPlayer() << "�� " << i << ", " << j << "��ġ�� ���� ���ҽ��ϴ�." << endl;
						turn = 1;
					}
				}
			}
			else { // �ڸ��� �� ���� ���
				cout << "�̹� �ִ� �ڸ��Դϴ�. �ٽ� ��������." << endl;
			}
		}
	}
};