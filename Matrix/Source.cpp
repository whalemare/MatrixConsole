#include <iostream>
#include "Matrix.h"
#include <clocale>
#define boolean int // Небольшой костыль
#define false 0
#define true 1

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
	boolean finish = false;
	cout << "В настоящий момент Вы работаете со следующей матрицей:\n";
	matrix.addRandMatrix(); // Инициализируем матрицу
	matrix.printMatrix();


	while (finish == false)
	{
		cout << "Выберите необходимый пункт меню, путем ввода числового значения:\n\n";
		cout << "1. Сгенерировать матрицу заново\n";
		cout << "2. Транспонировать матрицу\n";
		cout << "3. Вычислить определитель\n";
		cout << "Введите любое другое число, чтобы закрыть программу...\n\n";
		cout << ">> ";

		int c = 0; // номер пункта меню
		cin >> c;
		cout << endl;

		switch (c)
		{
		case 1:
			system("cls");

			matrix.addRandMatrix();
			cout << "Ваша новая матрица:\n\n";
			matrix.printMatrix();
			char answer;
			cout << "Продолжить работу? y или n";
			cin >> answer;
			if (answer == 'y')
			{
				finish = false; // для наглядности
				system("cls");
				matrix.printMatrix();
			}
			else
				finish = true;
			break;
		case 2:
			system("cls");
			matrix.getTransMatrix(); // Получаем транспонированную матрицу
			break;
		case 3:
			int **mas;
			mas = new int*[4]; // размерность
			for (int i = 0; i < 4; i++) {
				mas[i] = new int[4];
				for (int j = 0; j < 4; j++) {
					mas[i][j] = matrix.getIntMatrix(i, j);
				}
			}

			cout << "Определитель матрицы равен: " << matrix.determinant(mas, 4) << endl;
			break;
		default:
			return 0;
		}
	}

	system("pause");
return 0;
}