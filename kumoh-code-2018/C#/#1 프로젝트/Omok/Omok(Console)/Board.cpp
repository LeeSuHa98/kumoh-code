#include <iostream>
#include <string>
using namespace std;

class board {
private:
	int matrix[10][10];
public:
	void putStone(int x, int y, int stone){
		matrix[x][y] = stone;
	}
	void removeStone(int x, int y){
		matrix[x][y] = 0;
	}
	int getStone(int x, int y){
		return matrix[x][y];
	}
	void display(){
		int x, y;
		cout << "¢Ù ";
		for (x = 0; x<10; x++){
			cout << x << " ";
		}
		cout << endl;
		for (x = 0; x<10; x++){
			cout << " " << x;
			for (y = 0; y<10; y++){
				if (matrix[x][y] == 0) cout << "¡à";
				else if (matrix[x][y] == 1) cout << "¡Ü";
				else if (matrix[x][y] == 2) cout << "¡Û";
				else cout << "¡à";
			}
			cout << endl;
		}
	}
	void clear(){
		int x, y;
		for (x = 0; x<10; x++){
			for (y = 0; y<10; y++){
				matrix[x][y] = 0;
			}
		}
	}
};