#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class MatrixTerm
{
	friend class SparseMatrix;
private:
	int row; // ��
	int col; // ��
	int value; // ��
public:
	MatrixTerm() {}
	~MatrixTerm() {}

	int getRow() const { return row; }
	int getCol() const { return col; }
	int getValue() const { return value; }
};