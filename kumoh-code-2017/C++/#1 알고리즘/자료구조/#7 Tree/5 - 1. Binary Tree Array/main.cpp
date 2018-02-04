#include "Tree.h"

int main()
{
	int nodeCount;

	cout << "노드 개수를 입력하세요 : ";
	cin >> nodeCount;

	Tree<int> t(nodeCount);
	t.traversalOrder(nodeCount);

	system("pause");

	return 0;
}