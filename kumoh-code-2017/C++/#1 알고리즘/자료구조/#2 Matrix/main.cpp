#include "Matrix.h"

int main()
{
	Matrix mat, tmpMat;

	cout << "����� ä�� 16���� ���� �Է��ϼ��� :";
	cin >> mat; // ���� 16�� �Է� �޾� ä���
	cout << "�������\n" << mat;

	tmpMat = mat.turnRight(); // ��� ���� ȸ��
	cout << "�������� 90�� ȸ��\n" << tmpMat;

	tmpMat = mat.turnLeft();  // ��� ���� ȸ��
	cout << "�������� 90�� ȸ��\n" << tmpMat;
}