#pragma once
#include "MatrixTerm.h"

class SparseMatrix
{
private:
	int rows; // ���� ��
	int cols; // ���� ��
	int terms; // 0�� �ƴ� ���� ��
	int capacity; // ũ��
	MatrixTerm* smArray;
public:
	SparseMatrix() 
	{
		rows = 0;
		cols = 0;
		terms = 0;
		capacity = 10;
		smArray = new MatrixTerm[capacity];
	}
	SparseMatrix(int rows, int cols, int terms)
	{
		this->rows = rows;
		this->cols = cols;
		this->terms = terms;
		this->capacity = 10;
		smArray = new MatrixTerm[capacity];

		if (terms >= capacity)
		{
			ChangeSizeID(capacity * 2);
		}
	}
	SparseMatrix(const SparseMatrix& sm) // Deep Copy
	{
		this->rows = sm.rows;
		this->cols = sm.cols;
		this->terms = sm.terms;
		this->capacity = sm.capacity;
		smArray = new MatrixTerm[capacity];

		for (int i = 0; i < terms; i++)
		{
			smArray[i] = sm.smArray[i];
		}
	}
	~SparseMatrix() 
	{
		if (smArray != NULL)
		{
			delete[] smArray;
		}
	}

	friend ostream& operator<<(ostream& os, const SparseMatrix& sm);
	friend istream& operator >> (istream& in, SparseMatrix& sm);
	SparseMatrix operator*(SparseMatrix& sm);

	SparseMatrix FastTranspose();
	void StoreSum(const int sum, const int r, const int c);
	void ChangeSizeID(const int newSize);

};