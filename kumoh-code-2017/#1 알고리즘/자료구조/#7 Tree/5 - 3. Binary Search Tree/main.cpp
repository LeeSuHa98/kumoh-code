#include "Tree.h"

int main()
{
	while (1)
	{
		string data;
		cout << "문자열들을 입력하세요 (마지막은 0) : ";
		cin >> data;
		Tree<string> bst(data);
		if (data == "0")
		{
			cout << "종료합니다. " << endl;
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
