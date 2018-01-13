#include "SparseMatrix.h"

int main()
{
	int m;
	int n;
	int p;

	cout << "곱할 행렬이 mxn와 nxp크기일 때, m과 n과 p의 값을 순서대로 입력하세요 : ";
	cin >> m >> n >> p;

	SparseMatrix sm1(m, n, 0);
	SparseMatrix sm2(n, p, 0);

	cout << "첫번째 행렬의 6개 값을 행우선으로 입력하세요 : ";
	cin >> sm1;
	
	cout << "두번째 행렬의 4개 값을 행우선으로 입력하세요 : ";
	cin >> sm2;

	cout << endl << "곱셈 결과" << endl;
	cout << sm1 * sm2;

	return 0;
}