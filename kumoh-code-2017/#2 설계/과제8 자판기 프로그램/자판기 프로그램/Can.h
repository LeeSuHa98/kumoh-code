#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum menus { COIN_DEPOSIT = 1, ITEM_SELECTION, CHANGE_RETURN, EXIT };

const int MAX_CAN = 60;
const int lACK_MONEY = -1;
const int ENOUGH_MONEY = 1;

class Can
{
private:
	string id;
	string name; // 상품명
	int price; // 단가
	int stock_quantity; // 재고 수량
public:
	Can() {}
	Can(string id, string name, int price, int stock_quantity)
	{
		this->id = id;
		this->name = name;
		this->price = price;
		this->stock_quantity = stock_quantity;
	}
	~Can() {}

	string getId() { return id; }
	string getName() { return name; }
	int getPrice() { return price; }
	int getQuantity() { return stock_quantity; }

	int minusQuantity() { return stock_quantity--; }
};