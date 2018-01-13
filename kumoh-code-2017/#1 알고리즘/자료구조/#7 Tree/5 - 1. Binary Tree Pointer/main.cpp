#include "Tree.h"

int main()
{
	int nodeCount = 0;
	Tree<int> t;

	cout << "노드의 개수를 입력하세요 : ";
	cin >> nodeCount;

	t.addTree(nodeCount);
	t.traversalOrder();

	system("pause");

	return 0;
}