# Матрицы
Лабораторная работа за 3 семестр. НГТУ, АВТФ, Власов Антон.
<br>
##Что это?
<br>
Программа осуществляющая работу с матрицами. Также присутствует отчет. Ключевые особенности: <br><br>

<img src="https://raw.githubusercontent.com/whalemare/MatrixConsole/master/Matrix/screen.png">

<br><br>

* Ведется работа с квадратными матрицами 4x4
* Матрица при каждом запуске генерируется автоматически рандомным образом
* Навигация по программе с помощью удобного меню
* Можно генерировать новую матрицу внутри программы
* Можно вычислять определитель матрицы
* Можно транспонировать матрицу
* Поддержка внутри кода перегрузки операторов: ++, --, +, -, т.е.
``` C++
Matrix matrixA, matrixB, matrixResult; // создаем три объекта-матрицы

matrixA.addRandMatrix(); // генерируем рандомную матрицу
matrixB.addRandMatrix();

matrixA++; // увеличим все элементы матрицы на 1 (т.е. + Е)
matrixB--; // уменьшим все элементы матрицы на 1
(matrixA+matrixB).printMatrix(); // распечатает сумму двух матриц

/*
К сожалению, пока нельзя написать так
matrixResult = matrixA+MatrixB;
т.к. оператор '=' еще не перегружен, так же как и '*', '/', '=='
*/
```
<br><br>
## В планах:
* Дописать перегрузку операторов умножения, деления и равенства
* В конструкторе матрицы инициализировать все элементы 0

`Если ты используешь это в целях обучения - то ты нереально крут.`
