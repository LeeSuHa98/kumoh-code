#include"Keypad.h"

Keypad::Keypad(){
	input = '0';
}

int Keypad::getInput(){
	int sum = 0;
	cin >> input;
	for (int i = 0; i < input.length(); i++){ //string�Է¹����� �ڸ���(sum)�� �̿��Ͽ� int�� �ٲپ���
		sum *= 10;
		input [i] = input[i] - '0';
		sum = sum + input[i];

	}
	return sum;
}