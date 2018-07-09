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
		// ���� ����
		if (max == 0) return 0;
		else return 1;
	}

	int evaluatePosition(int x, int y){
		int blacks[8], whites[8];

		// ���� ����
		if (omokBoard.getStone(x, y) != 0) return 0; // �̹� �ٸ� ���� ���� ������

		//�� ������ �������� �ִ� ����
		for (int i=0; i<8; i++) blacks[i] = 0;
		getBlackCounts(x, y, blacks, 8);
		int blackMax = getMax(blacks, 8);

		//�� ������ ���� �ִ� ����
		for (int i=0; i<8; i++) whites[i] = 0;
		getWhiteCounts(x, y, whites, 8);
		int whiteMax = getMax(whites, 8);

		int computerMax, humanMax;
		if (order == 1) { // ����� �浹, �� ù��° �����̸�
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

		//0����
		ny = y - 1;
		while (ny >= 0) {
			if (omokBoard.getStone(x, ny) == 1){
				blacks[0]++;
				ny--;
			}
			else break;
		}

		//1����
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

		//2����
		nx = x + 1;
		while (nx < 10) {
			if (omokBoard.getStone(nx, y) == 1){
				blacks[2]++;
				nx++;
			}
			else break;
		}

		//3����
		nx = x + 1;
		ny = y + 1;
		while (nx < 10 && ny < 10) {
			if (omokBoard.getStone(nx, ny) == 1){
				blacks[3]++;
				nx++; // ���� ����
				ny++;
			}
			else break;
		}

		//4����
		ny = y + 1;
		while (ny < 10) { //���� ����
			if (omokBoard.getStone(x, ny) == 1){
				blacks[4]++;
				ny++; // ���� ����
			}
			else break;
		}

		//5����
		nx = x - 1;
		ny = y + 1;
		while (nx >= 0 && ny < 10) { // ���� ����
			if (omokBoard.getStone(nx, ny) == 1){
				blacks[5]++;
				nx--;
				ny++;
			}
			else break;
		}

		//6����
		nx = x - 1; 
		while (nx >= 0) {
			if (omokBoard.getStone(nx, y) == 1){
				blacks[6]++;
				nx--;
			}
			else break;
		}

		//7����
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

		//0����
		int ny = y - 1;
		while (ny >= 0) {
			if (omokBoard.getStone(x, ny) == 2){
				whites[0]++;
				ny--;
			}
			else break;
		}

		//1����
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

		//2����
		nx = x + 1;
		while (nx < 10) {
			if (omokBoard.getStone(nx, y) == 2){
				whites[2]++;
				nx++;
			}
			else break;
		}

		//3����
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

		//4����
		ny = y + 1;
		while (ny >=0) {
			if (omokBoard.getStone(x, ny) == 2){
				whites[4]++;
				ny--;
			}
			else break;
		}

		//5����
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

		//6����
		nx = x - 1;
		while (nx >= 0) {
			if (omokBoard.getStone(nx, y) == 2){
				whites[6]++;
				nx--;
			}
			else break;
		}

		//7����
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

		cout << "1 : 1 �� �Ϸ��� 1��, computer : 1 �� �Ϸ��� 2 �� �����ÿ�." << endl;
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
		omokBoard.display(); // ���� ����
		while (true){
			if (order == getTurn()){
				check = getStonePosition(i, j);
			}
			else{
				check = getStonePositionAuto(i, j);
			}

			if (check == -1) break; // ���� ��ġ �Է� ��
			else if (check == 1) { // �ڸ��� ��� ���� ���

				omokBoard.putStone(i, j, getTurn());
				omokBoard.display(); // ���� ����
				flag = checkWinningCondition();

				if (flag == true){
					if (getTurn() == 1)winner = getFirstPlayer();
					else winner = getSecondPlayer();
					cout << "�����մϴ�. " << winner << "��(��) �̰���ϴ�.";
					return;
				}
				else {
					if (getTurn() == 1) { // ù��° �����̸�
						cout << endl << getFirstPlayer() << "�� " << i << ", " << j << "��ġ�� ���� ���ҽ��ϴ�." << endl << endl;
						setTurn(2);
					}
					else {
						cout << endl << getSecondPlayer() << "�� " << i << ", " << j << "��ġ�� ���� ���ҽ��ϴ�." << endl <<endl;
						setTurn(1);
					}
				}
			}
			else { // �ڸ��� �� ���� ���
				cout << "�̹� �ִ� �ڸ��Դϴ�. �ٽ� ��������." << endl;
			}
		}
	}
	void registerPlayers(){
		string name;

		cout << "�÷��̾� �̸��� �Է��Ͻÿ�." << endl;
		cin >> name;
		cout << "ù��° �÷��̾ ���Ͻø� 1��" << endl << "�ι�° �÷��̾ ���Ͻø� 2���� �Է��Ͻÿ�." << endl;
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