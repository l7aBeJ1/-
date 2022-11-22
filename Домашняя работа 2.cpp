#include<iostream>
#include <iostream>
#include <time.h>

using namespace std;

//Функция выделения памяти для матрицы
int** InitMatrix(int n, int m)
{
	int** Matrix = new int* [n];
	for (int i = 0; i < n; i++)
		Matrix[i] = new int[m];
	return Matrix;
}

//Функция освобождения памяти для матрицы
void DeleteMatrix(int** Matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete[] Matrix[i];
	delete[] Matrix;
}


//Функция транспонирования матрицы
int** TranspMatrix(int** Matrix, int& n, int& m)
{
	int** tMatrix = InitMatrix(m, n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tMatrix[i][j] = Matrix[j][i];
	int temp = n;
	n = m;
	m = temp;

	return tMatrix;
}

//Функция вывода матрицы на экран
void PrintMatrix(int** Matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
}

//Основная функция программы
void main(void)
{
	setlocale(LC_ALL, "Russian"); //Установим локаль в .1251
	srand(time(NULL)); //Инициализация генератора случайно величины
	int n, m; //размерность матрицы
	int** Matrix; //Наша матрица
	cout << "Введите кол-во строк в матрицы n = ";
	cin >> n; //Введем n
	cout << "Введите кол-во столбцов матрицы m = ";
	cin >> m; //Введем m
	Matrix = InitMatrix(n, m); //Выделим память для матрицы

	//Заполним матрицу случайными величинами
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Matrix[i][j] = rand() % 100;

	cout << "Получена Матрица:" << endl;
	PrintMatrix(Matrix, n, m); //Выведим на экран матрицу

	Matrix = TranspMatrix(Matrix, n, m); //Транспонирование матрицы

	cout << endl << "Транспонированная матрица:" << endl;
	PrintMatrix(Matrix, n, m);
	DeleteMatrix(Matrix, n, m); //Очистим память матрицы
}

int main()
{
	int row1, row2, col1, col2;
	double** a, ** b, ** c;
	system("chcp 1251");
	system("cls");
	cout << "Введите количество строк первой матрицы: ";
	cin >> row1;
	cout << "Введите количество столбцов первой матрицы: ";
	cin >> col1;
	cout << "Введите количество строк второй матрицы: ";
	cin >> row2;
	cout << "Введите количество столбцов второй матрицы: ";
	cin >> col2;
	if (col1 != row2)
	{
		cout << "Умножение невозможно!";
		cin.get(); cin.get();
		return 0;
	}
	// Ввод элементов первой матрицы
	a = new double* [row1];
	cout << "Введите элементы первой матрицы" << endl;
	for (int i = 0; i < row1; i++)
	{
		a[i] = new double[col1];
		for (int j = 0; j < col1; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
	// Вывод элементов первой матрицы
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	// Ввод элементов второй матрицы
	b = new double* [row2];
	cout << "Введите элементы второй матрицы" << endl;
	for (int i = 0; i < row2; i++)
	{
		b[i] = new double[col2];
		for (int j = 0; j < col2; j++)
		{
			cout << "b[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}
	}
	// Вывод элементов второй матрицы
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	// Умножение матриц
	c = new double* [row1];
	for (int i = 0; i < row1; i++)
	{
		c[i] = new double[col2];
		for (int j = 0; j < col2; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < col1; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	// Вывод матрицы произведения
	cout << "Матрица произведения" << endl;
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cin.get(); cin.get();
	return 0;
}