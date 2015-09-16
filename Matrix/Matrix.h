#pragma once // ������ �� �������� �����������
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

	void addRandMatrix() // ������ ������� TODO: c������, ����� ����������� ���������� ��������������
	{
		srand(time(NULL)); // ������
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				matrix[i][j] = rand() % 100; // ������� ��������� ����� �� 0 �� 99
			}
		}
		cout << endl;
	}

	void printMatrix()
	{
		cout << "���� �������: \n" << endl;
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	int getIntMatrix(int i, int j) // ������ [i][j] ������� �������
	{
		return matrix[i][j];
	}

	void getTransMatrix()
	{
		cout << "���� ����������������� �������: \n" << endl;
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				trans_matrix[i][j] = matrix[j][i];
				cout << trans_matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;

	}

	// ��������� ������� ��� i-� ������ � j-�� �������
	void GetMatr(int **mas, int **p, int i, int j, int m) {
		int ki, kj, di, dj;
		di = 0;
		for (ki = 0; ki<m - 1; ki++) { // �������� ������� ������
			if (ki == i)  di = 1;
			dj = 0;
			for (kj = 0; kj<m - 1; kj++) { // �������� ������� �������
				if (kj == j)  dj = 1;
				p[ki][kj] = mas[ki + di][kj + dj];
			}
		}
	}

	int determinant(int **mas, int m) {
		int i, j, d, k, n;
		int **p;
		p = new int*[m];

		for (i = 0; i<m; i++)
			p[i] = new int[m];

		j = 0; d = 0;
		k = 1; //(-1) � ������� i
		n = m - 1;

		if (m<1)  
			cout << "������������ ��������� ����������!";

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
	int const DIMENSION = 4; // �����������
	int matrix[4][4]; // �������
	int trans_matrix[4][4]; // ����������������� �������
};

