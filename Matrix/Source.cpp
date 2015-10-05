#include <iostream>
#include <clocale>
#include "Matrix.h"
#define boolean int // Небольшой костыль
#define false 0
#define true 1

using namespace std;

int main()
{
	Matrix matrix;

	setlocale(LC_ALL, "Russian");
	boolean finish = false; // флаг выхода из программы
	boolean exit = false; // флаг выхода из подменю
	cout << "В настоящий момент Вы работаете со следующей матрицей:\n";
	matrix.addRandMatrix(); // Инициализируем матрицу
	matrix.printMatrix();

	while (finish == false)
	{
		cout << "Выберите необходимый пункт меню, путем ввода числового значения:\n\n";
		cout << "1. Сгенерировать матрицу заново\n";
		cout << "2. Транспонировать матрицу\n";
		cout << "3. Вычислить определитель\n";
		cout << "4. Увеличить все элементы матрицы на единицу\n";
		cout << "5. Уменьшить все элементы матрицы на единицу\n";
		cout << "6. Сложить две рандомные матрицы\n";
		cout << "7. Вычесть две рандомные матрицы\n";
		cout << "Введите любое другое число, чтобы закрыть программу...\n\n";
		cout << ">> ";

		int c = 0; // номер пункта меню
		cin >> c;
		cout << endl;

		switch (c)
		{
		case 1:
			system("cls");
			exit = false;
			while(exit == false)
			{ 
				matrix.addRandMatrix();
				matrix.printMatrix();
				char answer;
				cout << "Продолжить работу (y) или сгенерировать повторно(n)?\n>> ";
				cin >> answer;
				if (answer == 'y')
				{
					finish = false; // для наглядности
					exit = true;
					system("cls");
					matrix.printMatrix();
				}
				else
				{
					system("cls");
				}
			}
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

			system("cls");
			matrix.printMatrix();
			cout << "Определитель матрицы равен: " << matrix.determinant(mas, 4) << endl << endl;
			break;
		case 4:
			system("cls");
			matrix.printMatrix();
			cout << "\nПосле увеличения" << endl;
			++matrix;
			matrix.printMatrix();
			break;
		case 5:
			cout << "Уменьшить все элементы матрицы на единицу" << endl;
			matrix.printMatrix();
			cout << "\nПосле уменьшения" << endl;
			--matrix;
			matrix.printMatrix();
			break;
		case 6:
		{
			system("cls");
			Matrix temp;
			cout << "Сложить две матрицы:" << endl;
			matrix.printMatrix(); // 1 матрицу покажем
			temp.addRandMatrix();
			temp.printMatrix(); // 2 матрицу покажем	
			(matrix+temp).printMatrix(); // складываем две матрицы
			break;
		}
		case 7:
		{
			system("cls");
			Matrix temp;
			cout << "Вычесть две матрицы:" << endl;
			matrix.printMatrix(); // 1 матрицу покажем
			temp.addRandMatrix();
			temp.printMatrix(); // 2 матрицу покажем

			(matrix - temp).printMatrix(); // складываем две матрицы
			break;
		}
		case 8:
			system("cls");
			cout << "Сложение инт";
			cout << "Сложение double";
		default:
			return 0;
		}
	}

	system("pause");
return 0;
}