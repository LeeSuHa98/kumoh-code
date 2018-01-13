#include "SparseMatrix.h"

ostream& operator<<(ostream& os, const SparseMatrix& sm)
{
	int rowStart = 0;
	int count = 0;
	for (int i = 0; i < sm.rows; i++)
	{
		os << endl << "|";
		for (int j = 0; j < sm.cols; j++)
		{
			if (sm.smArray[count].getRow() == i && sm.smArray[count].getCol() == j)
			{
				os << setw(5) << sm.smArray[count].getValue();
				count++;
			}
			else
			{
				os << setw(5) << 0;
			}
		}
		os << setw(2) << "|";
	}
	return os;
}

istream& operator >> (istream& is, SparseMatrix& sm)
{
	int value;

	for (int i = 0; i < sm.rows; i++)
	{
		for (int j = 0; j < sm.cols; j++)
		{
			is >> value;
			if (value != 0)
			{
				sm.StoreSum(value, i, j);
			}
		}
	}
	return is;
}

SparseMatrix SparseMatrix::operator*(SparseMatrix& sm)
{
	// �� ���� ��� ��� *this�� sm�� ���Ͽ� ��ȯ�Ѵ�.
	if (cols != sm.rows) throw "Incompatible matrices";
	SparseMatrix bXpose = sm.FastTranspose();
	SparseMatrix result(rows, sm.cols, 0);

	int currRowIndex = 0;
	int currRowBegin = 0;
	int currRowA = smArray[0].row;

	// ��� ���� ����
	if (terms == capacity)
	{
		ChangeSizeID(terms + 1);
	}
	bXpose.ChangeSizeID(bXpose.terms + 1);

	smArray[terms].row = rows;
	bXpose.smArray[sm.terms].row = sm.cols;
	bXpose.smArray[sm.terms].col = -1;
	int sum = 0;

	while (currRowIndex < sm.terms)
	{
		// result�� �� currRowA�� ����
		int currColB = bXpose.smArray[0].row;
		int currColIndex = 0;
		while (currColIndex <= sm.terms)
		{
			// *this�� �� currRowA�� sm�� �� currColB�� ����
			if (smArray[currRowIndex].row != currRowA)
			{
				// currRowA ���� ��
				result.StoreSum(sum, currRowA, currColB);
				sum = 0; // sum�� �缳��
				currRowIndex = currRowBegin;
				// ���� ���� �Ѿ
				while (bXpose.smArray[currColIndex].row == currColB)
				{
					currColIndex++;
				}
				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (bXpose.smArray[currColIndex].row != currColB)
			{
				// b�� �� currColB�� ��
				result.StoreSum(sum, currRowA, currColB);
				sum = 0; // sum�� �缳��
						 // currRowA ���� ���� ���� ���ϵ��� ����
				currRowIndex = currRowBegin;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else
			{
				if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col)
				{
					currRowIndex++; // ���� ���� ������ ��
				}
				else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col)
				{
					// sum�� ����
					sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
					currRowIndex++;
					currColIndex++;
				}
				else
				{
					currColIndex++; // �� currColB�� ���� ������ ��
				}
			}
		} // while(currColIndex <= sm.Terms)�� ��
		while (smArray[currRowIndex].row == currRowA) // ���� ������ ��
		{
			currRowIndex++;
		}
		currRowBegin = currRowIndex;
		currRowA = smArray[currRowIndex].row;
	} // while(currRowIndex < Terms)�� ��
	return result;
}

SparseMatrix SparseMatrix::FastTranspose()
{
	// *this�� ��ġ�� O(terms + cols) �ð��� ��ȯ�Ѵ�.
	SparseMatrix b(cols, rows, terms);

	if (terms > 0)
	{
		// 0�� �ƴ� ���
		int* rowSize = new int[cols];

		int tmp1 = 0;
		int tmp2 = 0;

		// compute rowSize[i] = b�� �� i�� �ִ� ���� ���� ���
		fill(rowSize, rowSize + cols, 0); // �ʱ�ȭ
		for (int i = 0; i < terms; i++)
		{
			rowSize[smArray[i].col]++;
		}
		// rowStart[i] = b�� �� i�� ������
		for (int i = 0; i < cols; i++)
		{
			tmp1 = rowSize[i];
			if (i == 0)
			{
				rowSize[i] = 0;
			}
			else
			{
				rowSize[i] = tmp2 + rowSize[i - 1];
			}

			tmp2 = tmp1;
		}
		for (int i = 0; i < terms; i++)
		{
			int j = rowSize[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			rowSize[smArray[i].col]++;
		}

		delete[] rowSize;
	}
	return b;
}

void SparseMatrix::StoreSum(const int sum, const int r, const int c)
{
	// ���� sum != 0�̸� ��� ���� ��ġ�� �Բ� *this�� ������ ������ ����ȴ�.
	if (sum != 0)
	{
		if (terms == capacity)
		{
			ChangeSizeID(2 * capacity); // �� �� ũ��
		}
			smArray[terms].row = r;
			smArray[terms].col = c;
			smArray[terms].value = sum;
			terms++;
	}
}

void SparseMatrix::ChangeSizeID(const int newSize)
{
	// smArray ũ�⸦ newSize�� �����Ѵ�.
	if (newSize < terms) throw "New size must be >= number of terms";
	MatrixTerm* temp = new MatrixTerm[newSize]; // ���ο� �迭

	for (int i = 0; i < terms; i++)
	{
		temp[i] = smArray[i];
	}
	delete[] smArray; // ���� �޸𸮴� ����

	smArray = temp;
	capacity = newSize;
}