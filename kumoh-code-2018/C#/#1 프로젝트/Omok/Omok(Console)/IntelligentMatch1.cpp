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
		// 여기 수정
		if (max == 0) return 0;
		else return 1;
	}

	int evaluatePosition(int x, int y){
		int blacks[8], whites[8];

		// 여기 수정
		if (omokBoard.getStone(x, y) != 0) return 0; // 이미 다른 돌이 놓여 있으면

		//네 방향의 검은돌의 최대 갯수
		for (int i=0; i<8; i++) blacks[i] = 0;
		getBlackCounts(x, y, blacks, 8);
		int blackMax = getMax(blacks, 8);

		//네 방향의 흰돌의 최대 갯수
		for (int i=0; i<8; i++) whites[i] = 0;
		getWhiteCounts(x, y, whites, 8);
		int whiteMax = getMax(whites, 8);

		int computerMax, humanMax;
		if (order == 1) { // 사람이 흑돌, 즉 첫번째 주자이면
		humanMax = blackMax;
		computerMax = whiteMax;
		}

		else {
			humanMax = whiteMax;
			computerMax = blackMax;
		}

		if (computerMax == 5) return 100;
		else if (humanMax ==5) return 90;
		else if (computerMax == 4) return 80;
		else if (humanMax ==4) return 70;
		else if (computerMax == 3) return 60;
		else if (humanMax ==3) return 50;
		else if (computerMax == 2) return 40;
		else if (humanMax ==2) return 30;
		else if (computerMax == 1) return 20;
		else if (humanMax ==2) return 10;

		return 0;
	}

	int getMax (int a[], int size){
		int d[4];

		for (int i = 0; i < 4; i++) d[i] = 0;
		d[0] = a[0] + a[4] + 1;
		d[1] = a[2] + a[6] + 1;
		d[2] = a[3] + a[7] + 1;
		d[3] = a[1] + a[5] + 1;

		int max = 0;
		for (int i=0; i<4; i++) {
			if (d[i] > max) max = d[i];
		}
		return max;
	}

	void getBlackCounts(int x, int y, int blacks[], int size){
		int nx, ny;

		//0방향
		ny = y - 1;
		while (ny >= 0) {
			if (omokBoard.getStone(x, ny) == 1){
				blacks[0]++;
				ny--;
			}
			else break;
		}

		//1방향
		nx = x + 1;
		ny = y - 1;
		while (nx < 10 && ny >= 0) {
			if (omokBoard.getStone(nx, ny) == 1){
				blacks[1]++;
				nx++;
				ny--;
			}
			else break;
		}

		//2방향
		nx = x + 1;
		while (nx < 10) {
			if (omokBoard.getStone(nx, y) == 1){
				blacks[2]++;
				nx++;
			}
			else break;
		}

		//3방향
		nx = x + 1;
		ny = y + 1;
		while (nx < 10 && ny < 10) {
			if (omokBoard.getStone(nx, ny) == 1){
				blacks[3]++;
				nx++; // 여기 수정
				ny++;
			}
			else break;
		}

		//4방향
		ny = y + 1;
		while (ny < 10) { //여기 수정
			if (omokBoard.getStone(x, ny) == 1){
				blacks[4]++;
				ny++; // 여기 수정
			}
			else break;
		}

		//5방향
		nx = x - 1;
		ny = y + 1;
		while (nx >= 0 && ny < 10) { // 여기 수정
			if (omokBoard.getStone(nx, ny) == 1){
				blacks[5]++;
				nx--;
				ny++;
			}
			else break;
		}

		//6방향
		nx = x - 1; 
		while (nx >= 0) {
			if (omokBoard.getStone(nx, y) == 1){
				blacks[6]++;
				nx--;
			}
			else break;
		}

		//7방향
		nx = x - 1;
		ny = y - 1;
		while (nx >= 0 && ny >= 0) {
			if (omokBoard.getStone(nx, ny) == 1){
				blacks[7]++;
				nx--;
				ny--;
			}
			else break;
		}

	}

void getWhiteCounts(int x, int y, int whites[], int size){

		//0방향
		int ny = y - 1;
		while (ny >= 0) {
			if (omokBoard.getStone(x, ny) == 2){
				whites[0]++;
				ny--;
			}
			else break;
		}

		//1방향
		int nx = x + 1;
		ny = y - 1;
		while (nx < 10 && ny >= 0) {
			if (omokBoard.getStone(nx, ny) == 2){
				whites[1]++;
				nx++;
				ny--;
			}
			else break;
		}

		//2방향
		nx = x + 1;
		while (nx < 10) {
			if (omokBoard.getStone(nx, y) == 2){
				whites[2]++;
				nx++;
			}
			else break;
		}

		//3방향
		nx = x + 1;
		ny = y + 1;
		while (nx < 10 && ny < 10) {
			if (omokBoard.getStone(nx, ny) == 2){
				whites[3]++;
				nx--;
				ny++;
			}
			else break;
		}

		//4방향
		ny = y + 1;
		while (ny >=0) {
			if (omokBoard.getStone(x, ny) == 2){
				whites[4]++;
				ny--;
			}
			else break;
		}

		//5방향
		nx = x - 1;
		ny = y + 1;
		while (nx >= 0 && ny >=0) {
			if (omokBoard.getStone(nx, ny) == 2){
				whites[5]++;
				nx--;
				ny++;
			}
			else break;
		}

		//6방향
		nx = x - 1;
		while (nx >= 0) {
			if (omokBoard.getStone(nx, y) == 2){
				whites[6]++;
				nx--;
			}
			else break;
		}

		//7방향
		nx = x - 1;
		ny = y - 1;
		while (nx >= 0 && ny >= 0) {
			if (omokBoard.getStone(nx, ny) == 2){
				whites[7]++;
				nx--;
				ny--;
			}
			else break;
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
		omokBoard.display(); // 여기 수정
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
				omokBoard.display(); // 여기 수정
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