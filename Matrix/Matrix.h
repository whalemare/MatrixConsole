#pragma once // защита от двойного подключения
#include <iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
class Matrix
{
public:
	Matrix::Matrix()
	{
	}

	Matrix::~Matrix()
	{
	}

	void addRandMatrix() // Генерирует матрицу TODO: cделать, чтобы размерность заносилась самостоятельно
	{
		srand(time(NULL)); // Рандом
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				matrix[i][j] = rand() % 100; // заносим случайное число от 0 до 99
			}
		}
		cout << endl;
	}

	void printMatrix() // Печатает матрицу
	{
		cout << "Ваша матрица: \n" << endl;
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl << endl;
	} 

	int getIntMatrix(int i, int j) // Возвращает [i][j] элемент матрицы
	{
		return matrix[i][j];
	}

	void getTransMatrix() // Возвращает транспонированную матрицу
	{
		int temp[4][4];
		cout << "Ваша транспонированная матрица: \n" << endl;
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				trans_matrix[i][j] = matrix[j][i];
				cout << trans_matrix[i][j] << "\t";
			}
			cout << endl;
		}

		//Присвоим обычной матрице транспонированное значение
		for (int i = 0; i < DIMENSION; i++)
			for (int j = 0; j < DIMENSION; j++)
				matrix[i][j] = trans_matrix[i][j];
	}

	// Получение матрицы без i-й строки и j-го столбца
	void GetMatr(int **mas, int **p, int i, int j, int m) {
		int ki, kj, di, dj;
		di = 0;
		for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
			if (ki == i)  di = 1;
			dj = 0;
			for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
				if (kj == j)  dj = 1;
				p[ki][kj] = mas[ki + di][kj + dj];
			}
		}
	}

	int determinant(int **mas, int m) { // Вычисляет определитель матрицы
		int i, j, d, k, n;
		int **p;
		p = new int*[m];

		for (i = 0; i<m; i++)
			p[i] = new int[m];

		j = 0; d = 0;
		k = 1; //(-1) в степени i
		n = m - 1;

		if (m<1)  
			cout << "Определитель вычислить невозможно!";

		if (m == 1) 
		{
			d = mas[0][0];
			return(d);
		}

		if (m == 2) 
		{
			d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
			return(d);
		}

		if (m>2) 
		{
			for (i = 0; i<m; i++) 
			{
				GetMatr(mas, p, i, 0, m);
				d = d + k * mas[i][0] * determinant(p, n);
				k = -k;
			}
		}
		return(d);
	}

private:
	int const DIMENSION = 4; // размерность
	int matrix[4][4]; // матрица
	int trans_matrix[4][4]; // транспонированная матрица
};

