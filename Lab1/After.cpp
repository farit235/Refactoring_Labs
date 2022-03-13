#include <iostream>
#include <ctime>
using namespace std;

int** MatrixMem(int n, int m) {
	int** M = new int* [n];
	for (int i = 0; i < n; i++)
		M[i] = new int[m];
	return M;
}
int MatrixInit(int** matrix, int n, int m, int check)
{
	if (check == 2) {

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix[i][j] = rand() % 10;
			}
		}
	}
	else
	{
		cout << "Введите данные через пробел: ";
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++)
			{
				cin >> matrix[i][j];
			}
		}
	}
	return **matrix;
};
int** MatrixUpgrade(int length, int n, int m, int** MPrev) {

	int** MUpd = new int* [length];
	for (int i = 0; i < length; i++)
	{
		MUpd[i] = new int[length];
		for (int j = 0; j < length; j++)
			MUpd[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			MUpd[i][j] = MPrev[i][j];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
			cout << MUpd[i][j] << " ";
		cout << endl;
	}
	return MUpd;
}
int** SplitMatrix(int length, int** MUpd) {
	int** splitMat = new int* [length / 2];
	for (int i = 0; i < length / 2; i++)
	{
		splitMat[i] = new int[length / 2];
		for (int j = 0; j < length / 2; j++)
			splitMat[i][j] = MUpd[i][j];
	}
	return splitMat;
}
int** SplitMatrixR(int length, int** MUpd) {
	int** splitMat = new int* [length / 2];
	for (int i = 0; i < length / 2; i++)
	{
		splitMat[i] = new int[length / 2];
		for (int j = 0; j < length / 2; j++)
			splitMat[i][j] = MUpd[i][j + length / 2];
	}
	return splitMat;
}
int** SplitMatrixL(int length, int** MUpd) {
	int** splitMat = new int* [length / 2];
	for (int i = 0; i < length / 2; i++)
	{
		splitMat[i] = new int[length / 2];
		for (int j = 0; j < length / 2; j++)
			splitMat[i][j] = MUpd[i + length / 2][j];
	}
	return splitMat;
}
int** SplitMatrixF(int length, int** MUpd) {
	int** splitMat = new int* [length / 2];
	for (int i = 0; i < length / 2; i++)
	{
		splitMat[i] = new int[length / 2];
		for (int j = 0; j < length / 2; j++)
			splitMat[i][j] = MUpd[i + length / 2][j + length / 2];
	}
	return splitMat;
}
int** IntermidMatrix(int lenght) {
	int** intermidMatrix = new int* [lenght / 2];
	for (int i = 0; i < lenght / 2; i++)
	{
		intermidMatrix[i] = new int[lenght / 2];
	}
	return intermidMatrix;
}
void PrintMatrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
};
int BorderAlign(int length, int x, int sf, int** Matr) {
	for (int i = 0; i < length; i++)
	{
		x = 0;
		for (int j = 0; j < length; j++)
		{
			if (Matr[i][j] != 0)
			{
				x++;
				sf = 100;
			}
		}
		if (x == 0 && i < sf)
		{
			sf = i;
		}
	}
	return sf;
}
void DeleteMatrix(int n, int** M1) {
	for (int i = 0; i < n; i++)
		delete[] M1[i];
}


void main()
{
	srand(time(NULL));
	int n1, m1, n2, m2, k, l = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (;;) {
		cout << "Введите размеры первой матрицы\n\n";
		cout << "Количество столбцов: ";
		cin >> n1;
		cout << "Количество строк: ";
		cin >> m1;
		if (n1 >= 1 || m1 >= 1)
			break;
		cout << "Введите правильные размеры матрицы! - > 0 \n" << endl;
	}
	for (;;) {
		cout << "Введите размеры второй матрицы\n\n";
		cout << "Количество столбцов: ";
		cin >> n2;
		cout << "Количество строк: ";
		cin >> m2;
		if (n2 >= 1 || m2 >= 1)
			break;
		cout << "Введите правильные размеры матрицы! - > 0 \n" << endl;
	}
	int** M1 = MatrixMem(n1, m1);
	int** M2 = MatrixMem(n2, m2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////
	
	for (;;) {
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> k;
		if (k > 0 || k < 3)
			break;
		cout << "Ввели неправельный способ!" << endl;
	}
	switch (k)
	{
	case 1:
		MatrixInit(M1, n1, m1, k);
		MatrixInit(M2, n2, m2, k);
		cout << "\nМатрица 1\n\n";
		PrintMatrix(M1, n1, m1);
		cout << "\nМатрица 2\n\n";
		PrintMatrix(M2, n2, m2);
		break;

	case 2:
		MatrixInit(M1, n1, m1, k);
		MatrixInit(M2, n2, m2, k);
		cout << "\nМатрица 1\n\n";
		PrintMatrix(M1, n1, n2);
		cout << "\nМатрица 2\n\n";
		PrintMatrix(M1, n1, n2);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (l < n1 || l < n2 || l < m1 || l < m2)
		l *= 2;
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	int**M3 = MatrixUpgrade(l, n1, m1, M1);
	cout << "\nМатрица 2\n\n";
	int**M4 = MatrixUpgrade(l, n2, m2, M2);
	
	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРазбиение\n\n";
	int** mat1 = SplitMatrix(l, M3);
	int** mat2 = SplitMatrixR(l, M3);
	int** mat3 = SplitMatrixL(l, M3);
	int** mat4 = SplitMatrixF(l, M3);
	int** mat5 = SplitMatrix(l, M4);
	int** mat6 = SplitMatrixR(l, M4);
	int** mat7 = SplitMatrixL(l, M4);
	int** mat8 = SplitMatrixF(l, M4);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** p1 = IntermidMatrix(l);
	int** p2 = IntermidMatrix(l);
	int** p3 = IntermidMatrix(l);
	int** p4 = IntermidMatrix(l);
	int** p5 = IntermidMatrix(l);
	int** p6 = IntermidMatrix(l);
	int** p7 = IntermidMatrix(l);
	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			p1[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);
			}

			p2[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];
			}

			p3[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);
			}

			p4[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);
			}

			p5[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];
			}

			p6[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);
			}

			p7[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** mat9 = IntermidMatrix(l);
	int** mat10 = IntermidMatrix(l);
	int** mat11 = IntermidMatrix(l);
	int** mat12 = IntermidMatrix(l);
	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			mat9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
			mat10[i][j] = p3[i][j] + p5[i][j];
			mat11[i][j] = p2[i][j] + p4[i][j];
			mat12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = MatrixMem(l, l);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			M5[i][j] = mat9[i][j];
			M5[i][j + l / 2] = mat10[i][j];
			M5[i + l / 2][j] = mat11[i][j];
			M5[i + l / 2][j + l / 2] = mat12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	f = BorderAlign(l, x, f, M5);
	s = BorderAlign(l, x, s, M5);
	int** M6 = new int* [f];
	for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	PrintMatrix(M6, f, s);
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	DeleteMatrix(n1, M1);
	DeleteMatrix(n2, M2);
	DeleteMatrix(l, M3);
	DeleteMatrix(l, M4);
	DeleteMatrix(l, M5);
	DeleteMatrix(f, M6);
	DeleteMatrix(l / 2, mat1);
	DeleteMatrix(l / 2, mat2);
	DeleteMatrix(l / 2, mat3);
	DeleteMatrix(l / 2, mat4);
	DeleteMatrix(l / 2, mat5);
	DeleteMatrix(l / 2, mat6);
	DeleteMatrix(l / 2, mat7);
	DeleteMatrix(l / 2, mat8);
	DeleteMatrix(l / 2, mat9);
	DeleteMatrix(l / 2, mat10);
	DeleteMatrix(l / 2, mat11);
	DeleteMatrix(l / 2, mat12);
	DeleteMatrix(l / 2, p1);
	DeleteMatrix(l / 2, p2);
	DeleteMatrix(l / 2, p3);
	DeleteMatrix(l / 2, p4);
	DeleteMatrix(l / 2, p5);
	DeleteMatrix(l / 2, p6);
	DeleteMatrix(l / 2, p7);	
	delete[] M1, M2, M3, M4, M5, M6;
	delete[] mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10, mat11, mat12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}