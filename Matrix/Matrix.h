#pragma once // защита от двойного подключения
#if !defined(Matrix_H)
	#define Matrix_H

class Matrix
{
public:

	Matrix::Matrix()
	{
	}

	Matrix::~Matrix()
	{
	}


	void addRandMatrix(); // Генерирует матрицу TODO: cделать, чтобы размерность заносилась самостоятельно

	void printMatrix(); // Печатает матрицу

	int getIntMatrix(int i, int j); // Возвращает [i][j] элемент матрицы

	void getTransMatrix(); // Возвращает транспонированную матрицу

	void GetMatr(int **mas, int **p, int i, int j, int m); // Получение матрицы без i-й строки и j-го столбца

	int determinant(int **mas, int m); // Вычисляет определитель матрицы

private:
	int const DIMENSION = 4; // размерность
	int matrix[4][4]; // матрица
	int trans_matrix[4][4]; // транспонированная матрица
};

#endif
