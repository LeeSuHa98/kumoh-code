#include "Expression.h"

int main()
{
	string input_str;
	Expression e;

	while (1)
	{
		cout << "계산식을 입력하세요(종료는 quit) : ";
		getline(cin, input_str);

		if (input_str == "quit")
		{
			break;
		}
		try 
		{
			e.setExpression(input_str);
			e.toPostfix();

			cout << "--- 후위 계산식은 : " << e << endl;
			int result = e.eval();

			cout << " ---- 결과는 " << result << endl;
			cout << endl;
		}
		catch (char* ex) 
		{
			cout << "[오류]" << ex << endl;
			cout << endl;
		}
	}

	cout << "**** 종료합니다 ****" << endl;

	return 0;
}