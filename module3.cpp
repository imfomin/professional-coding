#include <stdio.h>
#include <string.h>
#include <limits>

// выделение памяти для двумерного массива
int** create_matrix(int n, int m) {
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	return a;
}
// заполнение двумерного массива
void fill_matrix(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &mat[i][j]);
		}
	}
}
// освобождение памяти двумерного массива
void delete_matrix(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}


// 1.1
// является ли число n степенью числа p
bool ispow(int n, int p) {
	while (n % p == 0) n /= p;
	return n == 1;
}
// нахождение всех чисел меньших N, которые дают отстаток в виде степени 3 при делении на них N 
int* task1_func(int N) {
	int* res = new int[N / 2 + 1];
	int* start = res;

	int pot = 1, ost;
	while (pot < N) {
		if (ispow(N % pot, 3)) {
			*res = pot;
			res++;
		}
	}
	*res = 0;

	return start;
}

// 1.2
int nod(int a, int b) {
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}
int* task2_func(int N) {
	int* res = new int[N - 1];
	int* start = res;
	int pot = 1, half = N / 2 + 1;
	while (pot < half) {
		if (nod(pot, N - pot) == 1) {
			*res = pot; res++;
		}
		pot++;
	}

	return start;
}


// 1.3
// след матрицы
int trace(int** matrix, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += matrix[n][n];
	}
	return res;
}
// создание вектора-столбца
int* vcol(int** mat, int n, int j) {
	int* col = new int[n]; // создание массива - будущего вектора столбца
	for (int i = 0; i < n; i++) {
		col[i] = mat[i][j]; // в col записывается i-тый элемент фиксированного j-того столбца
	}
	return col;
}
// скалярное произведение
int sc_prod(int* a, int* b, int n) {
	int prod = 0;
	for (int i = 0; i < n; i++) {
		prod += a[i] * b[i]; // пермножаются соответствующие элементы двух массивов, результат складывается
	}
	return prod;
}
// умножение матриц
int** matxprod(int** A, int** B, int n) {
	int** C = create_matrix(n, n);
	int* help;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			help = vcol(B, n, j);
			C[i][j] = sc_prod(A[i], help, n);
			delete[] help;
		}
	}

	return C;
}
// единичная матрица
int** create_E(int n) {
	int** E = new int* [n];
	for (int i = 0; i < n; i++) {
		E[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			i == j ? E[i][j] = 1 : E[i][j] = 0;
		}
	}
	return E;
}
// создание вектора
int* task3_func(int** matrix, int n, int m) {
	int** help = create_E(n);
	int* vec = new int[m];
	for (int i = 0; i < m; i++) {
		help = matxprod(help, matrix, n);
		vec[i] = trace(help, n);
	}
	delete_matrix(help, n, n);
	return vec;
}


// 2.1
int strlen(char* str) {
	int len = 0;	
	while (*str) {
		len++; str++;
	}
	return len;
}
char* strcat(char* str1, char* str2) {
	char* p = str1;
	while (*str1) str1++;
	while (*str2) {
		*str1 = *str2;
		str1++; str2++;
	}
	return p;
}
int strcmp(char* str1, char* str2) {
	while (*str1 && *str2 && *str1 == *str2) {
		str1++; str2++;
	}
	return *str1 - *str2;
}
char* strcpy(char* str1, char* str2) {
	char* p = str1;
	while (*str2) {
		*str1 = *str2;
		str1++; str2++;
	}
	str1 = 0;
	return p;
}
char* strchr(char* str, char chr) {
	while (*str) {
		if (*str == chr) return str;
	}
	return NULL;
}
char* tolower(char* str) {
	char* start = str;
	char step = 'a' - 'A';
	while (*str) {
		if ('A' <= *str <= 'Z') {
			*str = *str + step;
		}
		str++;
	}

	return start;
}

// 2.2
int* cntltr(char* txt) {
	int* help = new int[26];
	for (int i = 0; i < 26; i++) {
		help[i] = 0;
	}

	txt = tolower(txt);
	for (int i = 0; txt[i]; i++) {
		if ('a' <= txt[i] <= 'z') help[txt[i] - 'a']++;
	}

	return help;
}
void task22_func() {
	char* text = new char[1000];
	text = gets_s(text, 1000);

	int* data = cntltr(text);
	int max = INT_MIN, ind = -1;
	for (int i = 0; i < 26; i++) {
		if (data[i] > max) {
			max = data[i];
			ind = i;
		}
	}

	printf("%c %d\n", ind + 'a', max);
}

// 2.3
int* cntdgt(char* txt) {
	int* help = new int[10];
	for (int i = 0; i < 10; i++) {
		help[i] = 0;
	}

	for (int i = 0; txt[i]; i++) {
		if ('0' <= txt[i] <= '9') help[txt[i] - '0']++;
	}

	return help;
}
int task23_func(int* digits) {
	unsigned long int res = 0;
	int dgt = 9;
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < digits[i]; j++) {
			res = res * 10 + dgt;
		}
		dgt--;
	}

	return res;
}