#include "Tree.h"

int main()
{
	int nodeCount = 0;
	Tree<int> t;

	cout << "����� ������ �Է��ϼ��� : ";
	cin >> nodeCount;

	t.addTree(nodeCount);
	t.traversalOrder();

	system("pause");

	return 0;
}