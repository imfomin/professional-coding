#include <stdio.h>

/* ввод массива с клавиатуры */
void scanfArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

/* печать массива */
void printIntArr(int* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/* выделение памяти для матрицы n*m */
int** newMatrix(int n, int m) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++){
		matrix[i] = new int[m];
	}

	return matrix;
}

/* заполнение целочисленной матрицы с клавиатуры */
void scanfMatrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

/* печать матрицы */
void printMatrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

/* освобождение памяти матрицы */
void deleteMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

/* произведение матриц */
int** prodMatrix(int** nm_Mat, int** mk_Mat, int n, int m, int k) {
	int** nk_Mat = newMatrix(n, k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			nk_Mat[i][j] = 0;
			for (int l = 0; l < m; l++) {
				nk_Mat[i][j] += nm_Mat[i][l] * mk_Mat[l][j];
			}
		}
	}

	return nk_Mat;
}

/* копирование матрицы */
void copyMatrix(int** Destination, int** Source, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Destination[i][j] = Source[i][j];
		}
	}
}

/* копирование массива */
void copyArray(int* Destination, int* Source, int n) {
	for (int i = 0; i < n; i++) {
		Destination[i] = Source[i];
	}
}
