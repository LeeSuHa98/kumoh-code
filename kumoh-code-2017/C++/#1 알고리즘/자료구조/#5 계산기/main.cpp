#include "Expression.h"

int main()
{
	string input_str;
	Expression e;

	while (1)
	{
		cout << "������ �Է��ϼ���(����� quit) : ";
		getline(cin, input_str);

		if (input_str == "quit")
		{
			break;
		}
		try 
		{
			e.setExpression(input_str);
			e.toPostfix();

			cout << "--- ���� ������ : " << e << endl;
			int result = e.eval();

			cout << " ---- ����� " << result << endl;
			cout << endl;
		}
		catch (char* ex) 
		{
			cout << "[����]" << ex << endl;
			cout << endl;
		}
	}

	cout << "**** �����մϴ� ****" << endl;

	return 0;
}