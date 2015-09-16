#include <iostream>
#include "Matrix.h"
#include <clocale>

using namespace std;

/*
��������� �����:
+ ������������ ��������� ������� � ��������� [0;100] ����������� 4�4 (����� ������� ����� �����������)
+ ��������� ������������ ����� ���������� ������� (�� �� ������� ���� ����� 4�4, ����� ��������)
+ ��������������� �������
+ ���� ������������ ����
*/


int main()
{
	Matrix matrix;

	setlocale(LC_ALL, "Russian");
	cout << "�������� ����������� ����� ����, ����� ����� ��������� ��������:\n\n";
	cout << "1. ������������� ������� ������\n";
	cout << "2. ��������������� �������\n";
	cout << "3. ��������� ������������\n";
	cout << "������� ����� ������ �����, ����� ������� ���������...\n\n";
	cout << ">> ";
	
	int c = 0; // ����� ������ ����
	cin >> c;

	switch (c)
	{
	case '1':
		system("cls");

		matrix.addRandMatrix(); // �������������� �������
		cout << "���� ����� �������:\n\n";
		matrix.printMatrix();
		break;
	case '2':
		matrix.getTransMatrix(); // �������� ����������������� �������
		break;
	default:
		return 0; // ��������� ���������
	}

	int **mas;
	mas = new int*[4]; // �����������
	for (int i = 0; i<4; i++) {
		mas[i] = new int[4];
		for (int j = 0; j<4; j++) {
			mas[i][j] = matrix.getIntMatrix(i, j);
		}
	}


	cout << "������������ ������� �����: " << matrix.determinant(mas, 4) << endl;

	matrix.getTransMatrix(); // �������� ����������������� �������


	system("pause");
return 0;
}