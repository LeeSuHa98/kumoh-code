#pragma once
#include "CanStorage.h"
#include "MoneyKeeper.h"
#include "ioHandler.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	// 동전 투입
	void insertCoin(MoneyKeeper& mk);
	// 상품 선택
	void selectMenu(MoneyKeeper& mk, CanStorage& c_list);
	// 잔돈 반환
	void returnCoin(MoneyKeeper& mk);
};