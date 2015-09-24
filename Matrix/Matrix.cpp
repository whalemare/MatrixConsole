#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"
using namespace std;

	void Matrix::addRandMatrix() // ���������� ������� TODO: c������, ����� ����������� ���������� ��������������
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

	void Matrix::printMatrix() // �������� �������
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
		cout << endl << endl;
	}

	int Matrix::getIntMatrix(int i, int j) // ���������� [i][j] ������� �������
	{
		return matrix[i][j];
	}

	void Matrix::getTransMatrix() // ���������� ����������������� �������
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

		//�������� ������� ������� ����������������� ��������
		for (int i = 0; i < DIMENSION; i++)
			for (int j = 0; j < DIMENSION; j++)
				matrix[i][j] = trans_matrix[i][j];
	}

	// ��������� ������� ��� i-� ������ � j-�� �������
	void Matrix::GetMatr(int **mas, int **p, int i, int j, int m) {
		int ki, kj, di, dj;
		di = 0;
		for (ki = 0; ki < m - 1; ki++) { // �������� ������� ������
			if (ki == i)  di = 1;
			dj = 0;
			for (kj = 0; kj < m - 1; kj++) { // �������� ������� �������
				if (kj == j)  dj = 1;
				p[ki][kj] = mas[ki + di][kj + dj];
			}
		}
	}

	int Matrix::determinant(int **mas, int m) { // ��������� ������������ �������
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

	Matrix Matrix::operator++()
	{
		Matrix temp;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				matrix[i][j]++;
				temp.matrix[i][j] = matrix[i][j];
			}
		return temp;
	}

	Matrix Matrix::operator--()
	{
		Matrix temp;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				matrix[i][j]--;
				temp.matrix[i][j] = matrix[i][j];
			}
		return temp;
	}

	Matrix Matrix::operator+(Matrix m2)
	{
		Matrix result;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];

		return result;
	}

	Matrix Matrix::operator-(Matrix m2)
	{
		Matrix result;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];

		return result;
	}

	