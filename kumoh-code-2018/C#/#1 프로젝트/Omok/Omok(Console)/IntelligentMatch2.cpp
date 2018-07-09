#include <iostream>
#include <string>
#include "Match.cpp"
using namespace std;

class intelligentMatch : public match {
private:

	int playType;
	int order;

	int getStonePositionAuto(int &x, int &y){
		int value[10][10];
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				value[i][j] = evaluatePosition(i, j);
			}
		}
		int max = 0;
		int maxi = 0, maxj = 0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (max < value[i][j]){
					max = value[i][j];
					maxi = i;
					maxj = j;
				}
			}
		}
		x = maxi;
		y = maxj;
		if (max == 0) return 0;
		else return 1;
	}

	int evaluatePosition(int x, int y){
		int blacks[8], whites[8], blackMax, whiteMax;
		int blockTypeBlack, blockTypeWhite, computerBlockType, humanBlockType;
		bool blackblocked[8], whiteblocked[8];

		if (omokBoard.getStone(x, y) != 0) return 0; // 이미 다른 돌이 놓여 있으면

		//네 방향의 검은돌의 최대 갯수
		for (int i=0; i<8; i++) blacks[i] = 0;
		getCounts(x, y, 1, blacks, blackblocked, 8);
		getMax(blacks, blackblocked, 8, blackMax, blockTypeBlack);

		//네 방향의 흰돌의 최대 갯수
		for (int i=0; i<8; i++) whites[i] = 0;
		getCounts(x, y, 2, whites, whiteblocked, 8);
		getMax(whites, whiteblocked, 8, whiteMax, blockTypeWhite);

		int computerMax, humanMax;
		if (order == 1) { // 사람이 흑돌, 즉 첫번째 주자이면
			humanMax = blackMax;
			computerMax = whiteMax;
			humanBlockType = blockTypeBlack;
			computerBlockType = blockTypeWhite;
		}

		else {
			humanMax = whiteMax;
			computerMax = blackMax;
			humanBlockType = blockTypeWhite;
			computerBlockType = blockTypeBlack;
		}

		if (computerMax == 5) return 100;
		else if (humanMax ==5) return 90;
		else if (computerMax == 4 && computerBlockType == 0) return 80;
		else if (humanMax ==4 && humanBlockType == 0) return 75;
		else if (computerMax == 4 && computerBlockType == 1) return 70;
		else if (humanMax ==4 && humanBlockType == 1) return 65;
		else if (computerMax ==3 && computerBlockType == 0) return 60;
		else if (humanMax ==3 && humanBlockType == 0) return 55;
		else if (computerMax ==3 && computerBlockType == 1) return 50;
		else if (humanMax ==3 && humanBlockType == 1) return 45;
		else if (computerMax == 2 && computerBlockType == 0) return 40;
		else if (humanMax ==2 && humanBlockType == 0) return 35;
		else if (computerMax == 2 && computerBlockType == 1) return 30;
		else if (humanMax ==2 && humanBlockType == 1) return 25;
		else if (computerMax == 1 && computerBlockType == 0) return 20;
		else if (humanMax ==1 && humanBlockType == 0) return 15;
		else if (computerMax == 1 && computerBlockType == 1) return 10;
		else if (humanMax ==1 && humanBlockType == 1) return 5;

		return 0;
	}

	void getMax (int a[], bool b[], int size, int &max, int &blocktype){ // a는 갯수 배열, b는 블락킹 여부 배열
		int d[4];

		for (int i = 0; i < 4; i++) d[i] = 0;
		d[0] = a[0] + a[4] + 1;
		d[1] = a[2] + a[6] + 1;
		d[2] = a[3] + a[7] + 1;
		d[3] = a[1] + a[5] + 1;

		max = 0;
		int dir;
		for (int i=0; i<4; i++) {
			if (d[i] > max){
				max = d[i];
				dir = i;
			}
		}

		switch (dir)
		{
		case 0:
			if (b[0] == true || b[4] == true)blocktype = 2;
			else if (b[0] == false && b[4] == false)blocktype = 0;
			else blocktype = 1;
			break;
		case 1:
			if (b[1] == true || b[5] == true)blocktype = 2;
			else if (b[1] == false && b[5] == false)blocktype = 0;
			else blocktype = 1;
			break;
		case 2:
			if (b[2] == true || b[6] == true)blocktype = 2;
			else if (b[2] == false && b[6] == false)blocktype = 0;
			else blocktype = 1;
			break;
		case 3:
			if (b[3] == true || b[7] == true)blocktype = 2;
			else if (b[3] == false && b[7] == false)blocktype = 0;
			else blocktype = 1;
			break;
		}
	}

	void getCounts(int x, int y, int type, int counts[], bool blocked[], int size){
		int nx, ny, val;

		//0방향
		ny = y - 1;
		while (ny >= 0) {
			val = omokBoard.getStone(x, ny);
			if (val == type){
				counts[0]++;
				ny--;
			}
			else if (val == 2){
				blocked[0] = true;
				break;
			}
			else{//반대인 경우
				blocked[0] = false;
				break;
			}
		}

		//1방향
		nx = x + 1;
		ny = y - 1;
		while (nx < 10 && ny >= 0) {
			val = omokBoard.getStone(nx, ny);
			if (val == type){
				counts[1]++;
				nx++;
				ny--;
			}
			else if (val == 2){
				blocked[1] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[1] = false; // 수정(2015.7.3)
				break;
			}
		}

		//2방향
		nx = x + 1;
		while (nx < 10) {
			val = omokBoard.getStone(nx, y);
			if (val == type){
				counts[2]++;
				nx++;
			}
			else if (val == 2){
				blocked[2] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[2] = false; // 수정(2015.7.3)
				break;
			}
		}

		//3방향
		nx = x + 1;
		ny = y + 1;
		while (nx < 10 && ny < 10) {
			val = omokBoard.getStone(nx, ny);
			if (val == type){
				counts[3]++;
				nx++; 
				ny++;
			}
			else if (val == 2){
				blocked[3] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[3] = false; // 수정(2015.7.3)
				break;
			};
		}

		//4방향
		ny = y + 1;
		while (ny < 10) {
			val = omokBoard.getStone(x, ny);
			if (val == type){
				counts[4]++;
				ny++; 
			}
			else if (val == 2){
				blocked[4] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[4] = false; // 수정(2015.7.3)
				break;
			}
		}

		//5방향
		nx = x - 1;
		ny = y + 1;
		while (nx >= 0 && ny < 10) {
			val = omokBoard.getStone(nx, ny);
			if (val == type){
				counts[5]++;
				nx--;
				ny++;
			}
			else if (val == 2){
				blocked[5] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[5] = false; // 수정(2015.7.3)
				break;
			}
		}

		//6방향
		nx = x - 1; 
		while (nx >= 0) {
			val = omokBoard.getStone(nx, y);
			if (val == type){
				counts[6]++;
				nx--;
			}
			else if (val == 2){
				blocked[6] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[6] = false; // 수정(2015.7.3)
				break;
			}
		}

		//7방향
		nx = x - 1;
		ny = y - 1;
		while (nx >= 0 && ny >= 0) {
			val = omokBoard.getStone(nx, ny);
			if (val == type){
				counts[7]++;
				nx--;
				ny--;
			}
			else if (val == 2){
				blocked[7] = true; // 수정(2015.7.3)
				break;
			}
			else{//반대인 경우
				blocked[7] = false; // 수정(2015.7.3)
				break;
			}
		}

	}

public:

	int selectPlayType(){
		int type;

		cout << "1 : 1 을 하려면 1번, computer : 1 를 하려면 2 를 누르시오." << endl;
		cin >> type;
		return type;
	}
	void setPlayType(int type){
		playType = type;
	}
	int getPlayType(){
		return playType;
	}
	void play(){
		int m = selectPlayType();
		if (m == 1){
			match::registerPlayers();
			match::play();
		}
		else{
			registerPlayers();
			playwithcomputer();
		}
	}
	void playwithcomputer(){
		bool flag;
		int check;
		int i, j;
		string winner;

		omokBoard.clear();
		omokBoard.display();
		while (true){
			if (order == getTurn()){
				check = getStonePosition(i, j);
			}
			else{
				check = getStonePositionAuto(i, j);
			}

			if (check == -1) break; // 음수 위치 입력 시
			else if (check == 1) { // 자리가 비어 있을 경우

				omokBoard.putStone(i, j, getTurn());
				omokBoard.display();
				flag = checkWinningCondition();

				if (flag == true){
					if (getTurn() == 1)winner = getFirstPlayer();
					else winner = getSecondPlayer();
					cout << "축하합니다. " << winner << "이(가) 이겼습니다.";
					return;
				}
				else {
					if (getTurn() == 1) { // 첫번째 주자이면
						cout << endl << getFirstPlayer() << "가 " << i << ", " << j << "위치에 돌을 놓았습니다." << endl << endl;
						setTurn(2);
					}
					else {
						cout << endl << getSecondPlayer() << "가 " << i << ", " << j << "위치에 돌을 놓았습니다." << endl <<endl;
						setTurn(1);
					}
				}
			}
			else { // 자리가 차 있을 경우
				cout << "이미 있는 자리입니다. 다시 놓으세요." << endl;
			}
		}
	}
	void registerPlayers(){
		string name;

		cout << "플레이어 이름을 입력하시오." << endl;
		cin >> name;
		cout << "첫번째 플레이어를 원하시면 1번" << endl << "두번째 플레이어를 원하시면 2번을 입력하시오." << endl;
		cin >> order;


		if (order == 1){
			setFirstPlayer(name);
			setSecondPlayer("Computer");
		}
		else {
			setFirstPlayer("Computer");
			setSecondPlayer(name);
		}
		//cout << getFirstPlayer() << endl;
	}

};