#include "Tree.h"

int main()
{
	while (1)
	{
		string data;
		cout << "���ڿ����� �Է��ϼ��� (�������� 0) : ";
		cin >> data;
		Tree<string> bst(data);
		if (data == "0")
		{
			cout << "�����մϴ�. " << endl;
			break;
		}
		while (1)
		{
			cin >> data;
			if (data == "0")
			{
				break;
			}
			bst.insertTree(data);
		}
		bst.getTree();
		cout << endl;
	}
	system("pause");

	return 0;
}
