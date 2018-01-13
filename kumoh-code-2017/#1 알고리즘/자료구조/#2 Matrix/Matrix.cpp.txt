#include "Matrix.h"

Matrix Matrix::turnLeft()
{
	Matrix tmpMat;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			tmpMat.matrix[MAX_SIZE - 1 - j][i] = matrix[i][j];
		}
	}

	return tmpMat;
}

Matrix Matrix::turnRight()
{
	Matrix tmpMat;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			tmpMat.matrix[j][MAX_SIZE - 1 - i] = matrix[i][j];
		}
	}

	return tmpMat;
}

istream& operator >> (istream& is, Matrix& mat)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			is >> mat.matrix[i][j]; // 배열 입력
		}
	}

	return is;
}

ostream& operator<<(ostream& os, const Matrix& mat)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		os << " |";
		for (int j = 0; j < MAX_SIZE; j++)
		{
			os.width(4);
			os <<  mat.matrix[i][j]; // 배열 출력
		}
		os << " |" << endl;
	}

	return os;
}

