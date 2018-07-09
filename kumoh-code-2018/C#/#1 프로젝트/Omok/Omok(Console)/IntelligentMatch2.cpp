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

		if (omokBoard.getStone(x, y) != 0) return 0; // �̹� �ٸ� ���� ���� ������

		//�� ������ �������� �ִ� ����
		for (int i=0; i<8; i++) blacks[i] = 0;
		getCounts(x, y, 1, blacks, blackblocked, 8);
		getMax(blacks, blackblocked, 8, blackMax, blockTypeBlack);

		//�� ������ ���� �ִ� ����
		for (int i=0; i<8; i++) whites[i] = 0;
		getCounts(x, y, 2, whites, whiteblocked, 8);
		getMax(whites, whiteblocked, 8, whiteMax, blockTypeWhite);

		int computerMax, humanMax;
		if (order == 1) { // ����� �浹, �� ù��° �����̸�
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

	void getMax (int a[], bool b[], int size, int &max, int &blocktype){ // a�� ���� �迭, b�� ���ŷ ���� �迭
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

		//0����
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
			else{//�ݴ��� ���
				blocked[0] = false;
				break;
			}
		}

		//1����
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
				blocked[1] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[1] = false; // ����(2015.7.3)
				break;
			}
		}

		//2����
		nx = x + 1;
		while (nx < 10) {
			val = omokBoard.getStone(nx, y);
			if (val == type){
				counts[2]++;
				nx++;
			}
			else if (val == 2){
				blocked[2] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[2] = false; // ����(2015.7.3)
				break;
			}
		}

		//3����
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
				blocked[3] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[3] = false; // ����(2015.7.3)
				break;
			};
		}

		//4����
		ny = y + 1;
		while (ny < 10) {
			val = omokBoard.getStone(x, ny);
			if (val == type){
				counts[4]++;
				ny++; 
			}
			else if (val == 2){
				blocked[4] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[4] = false; // ����(2015.7.3)
				break;
			}
		}

		//5����
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
				blocked[5] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[5] = false; // ����(2015.7.3)
				break;
			}
		}

		//6����
		nx = x - 1; 
		while (nx >= 0) {
			val = omokBoard.getStone(nx, y);
			if (val == type){
				counts[6]++;
				nx--;
			}
			else if (val == 2){
				blocked[6] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[6] = false; // ����(2015.7.3)
				break;
			}
		}

		//7����
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
				blocked[7] = true; // ����(2015.7.3)
				break;
			}
			else{//�ݴ��� ���
				blocked[7] = false; // ����(2015.7.3)
				break;
			}
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
		omokBoard.display();
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
				omokBoard.display();
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