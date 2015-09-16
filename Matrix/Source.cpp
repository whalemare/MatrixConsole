#include <iostream>
#include "Matrix.h"
#include <clocale>

using namespace std;

/*
Программа умеет:
+ генерировать рандомную матрицу в диапазоне [0;100] размерности 4х4 (позже добавлю любую размерность)
+ вычислять определитель любой квадратной матрицы (но по дефолту пока стоит 4х4, позже исправлю)
+ транспонировать матрицу
+ пока недопиленное меню
*/


int main()
{
	Matrix matrix;

	setlocale(LC_ALL, "Russian");
	cout << "Выберите необходимый пункт меню, путем ввода числового значения:\n\n";
	cout << "1. Сгенерировать матрицу заново\n";
	cout << "2. Транспонировать матрицу\n";
	cout << "3. Вычислить определитель\n";
	cout << "Введите любое другое число, чтобы закрыть программу...\n\n";
	cout << ">> ";
	
	int c = 0; // номер пункта меню
	cin >> c;

	switch (c)
	{
	case '1':
		system("cls");

		matrix.addRandMatrix(); // Инициализируем матрицу
		cout << "Ваша новая матрица:\n\n";
		matrix.printMatrix();
		break;
	case '2':
		matrix.getTransMatrix(); // Получаем транспонированную матрицу
		break;
	default:
		return 0; // Выключаем программу
	}

	int **mas;
	mas = new int*[4]; // размерность
	for (int i = 0; i<4; i++) {
		mas[i] = new int[4];
		for (int j = 0; j<4; j++) {
			mas[i][j] = matrix.getIntMatrix(i, j);
		}
	}


	cout << "Определитель матрицы равен: " << matrix.determinant(mas, 4) << endl;

	matrix.getTransMatrix(); // Получаем транспонированную матрицу


	system("pause");
return 0;
}