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
	// 두 개의 희소 행렬 *this와 sm을 곱하여 반환한다.
	if (cols != sm.rows) throw "Incompatible matrices";
	SparseMatrix bXpose = sm.FastTranspose();
	SparseMatrix result(rows, sm.cols, 0);

	int currRowIndex = 0;
	int currRowBegin = 0;
	int currRowA = smArray[0].row;

	// 경계 조건 설정
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
		// result의 행 currRowA를 생성
		int currColB = bXpose.smArray[0].row;
		int currColIndex = 0;
		while (currColIndex <= sm.terms)
		{
			// *this의 행 currRowA에 sm의 열 currColB를 곱함
			if (smArray[currRowIndex].row != currRowA)
			{
				// currRowA 행의 끝
				result.StoreSum(sum, currRowA, currColB);
				sum = 0; // sum을 재설정
				currRowIndex = currRowBegin;
				// 다음 열로 넘어감
				while (bXpose.smArray[currColIndex].row == currColB)
				{
					currColIndex++;
				}
				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (bXpose.smArray[currColIndex].row != currColB)
			{
				// b의 열 currColB의 끝
				result.StoreSum(sum, currRowA, currColB);
				sum = 0; // sum을 재설정
						 // currRowA 행을 다음 열과 곱하도록 설정
				currRowIndex = currRowBegin;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else
			{
				if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col)
				{
					currRowIndex++; // 행의 다음 항으로 감
				}
				else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col)
				{
					// sum에 더함
					sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
					currRowIndex++;
					currColIndex++;
				}
				else
				{
					currColIndex++; // 열 currColB의 다음 항으로 감
				}
			}
		} // while(currColIndex <= sm.Terms)의 끝
		while (smArray[currRowIndex].row == currRowA) // 다음 행으로 감
		{
			currRowIndex++;
		}
		currRowBegin = currRowIndex;
		currRowA = smArray[currRowIndex].row;
	} // while(currRowIndex < Terms)의 끝
	return result;
}

SparseMatrix SparseMatrix::FastTranspose()
{
	// *this의 전치를 O(terms + cols) 시간에 반환한다.
	SparseMatrix b(cols, rows, terms);

	if (terms > 0)
	{
		// 0이 아닌 행렬
		int* rowSize = new int[cols];

		int tmp1 = 0;
		int tmp2 = 0;

		// compute rowSize[i] = b의 행 i에 있는 항의 수를 계산
		fill(rowSize, rowSize + cols, 0); // 초기화
		for (int i = 0; i < terms; i++)
		{
			rowSize[smArray[i].col]++;
		}
		// rowStart[i] = b의 행 i의 시작점
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
	// 만일 sum != 0이면 행과 열의 위치와 함께 *this의 마지막 항으로 저장된다.
	if (sum != 0)
	{
		if (terms == capacity)
		{
			ChangeSizeID(2 * capacity); // 두 배 크기
		}
			smArray[terms].row = r;
			smArray[terms].col = c;
			smArray[terms].value = sum;
			terms++;
	}
}

void SparseMatrix::ChangeSizeID(const int newSize)
{
	// smArray 크기를 newSize로 변경한다.
	if (newSize < terms) throw "New size must be >= number of terms";
	MatrixTerm* temp = new MatrixTerm[newSize]; // 새로운 배열

	for (int i = 0; i < terms; i++)
	{
		temp[i] = smArray[i];
	}
	delete[] smArray; // 이전 메모리는 제거

	smArray = temp;
	capacity = newSize;
}