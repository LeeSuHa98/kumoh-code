#include "Tree.h"

int main()
{
	int nodeCount;

	cout << "��� ������ �Է��ϼ��� : ";
	cin >> nodeCount;

	Tree<int> t(nodeCount);
	t.traversalOrder(nodeCount);

	system("pause");

	return 0;
}