#include"Keypad.h"

Keypad::Keypad(){
	input = '0';
}

int Keypad::getInput(){
	int sum = 0;
	cin >> input;
	for (int i = 0; i < input.length(); i++){ //string입력받을시 자릿수(sum)을 이용하여 int로 바꾸어줌
		sum *= 10;
		input [i] = input[i] - '0';
		sum = sum + input[i];

	}
	return sum;
}