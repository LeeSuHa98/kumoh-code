#include "SparseMatrix.h"

int main()
{
	int m;
	int n;
	int p;

	cout << "���� ����� mxn�� nxpũ���� ��, m�� n�� p�� ���� ������� �Է��ϼ��� : ";
	cin >> m >> n >> p;

	SparseMatrix sm1(m, n, 0);
	SparseMatrix sm2(n, p, 0);

	cout << "ù��° ����� 6�� ���� ��켱���� �Է��ϼ��� : ";
	cin >> sm1;
	
	cout << "�ι�° ����� 4�� ���� ��켱���� �Է��ϼ��� : ";
	cin >> sm2;

	cout << endl << "���� ���" << endl;
	cout << sm1 * sm2;

	return 0;
}