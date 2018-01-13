#pragma once
#include "IoHandler.h"

class SetsGraph
{
private:
	int* parent;
	int size;	// ���� ������ ����

public:
	SetsGraph() {}
	~SetsGraph() { delete[] parent; }

	void setGraph(int numberOfElements);	// �׷��� ����
	void weightedUnion(int i, int j);	// ���߱�Ģ�� �̿��� ������
	int collapsingFind(int i);	// �ر���Ģ�� �̿��� �˰���

	int getArr(int i) { return parent[i]; }
	int getSize() { return size; }
};