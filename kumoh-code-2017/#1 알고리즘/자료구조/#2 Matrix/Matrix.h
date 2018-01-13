#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 4;

class Matrix
{
	friend istream& operator >> (istream& is, Matrix& mat);
	friend ostream& operator<<(ostream& os, const Matrix& mat);

private:
	int matrix[MAX_SIZE][MAX_SIZE];
public:
	Matrix() {}
	~Matrix() {}

	Matrix turnLeft(); // 행렬 좌측 회전
	Matrix turnRight(); // 행렬 우측 회전
};