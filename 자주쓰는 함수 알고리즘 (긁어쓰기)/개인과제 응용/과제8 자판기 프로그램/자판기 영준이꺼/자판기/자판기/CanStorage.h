#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	int id;
	string name;
	int price;
	int stock_quantity;
}Can;

class CanStorage
{
private:
	Can* canList;
	int count;
public:
	CanStorage(void);
	~CanStorage(void);

	void insertCanList(int id,string name,int price,int quantity);
	void updateAmount(int id);

	Can getCanList(int count){return canList[count];}
};

