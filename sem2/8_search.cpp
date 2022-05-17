#include <stdio.h>
#include "funks_header.h"
#include <clocale>

void printSearches() {
	printf("1. линейный поиск\n");
	printf("2. оптимизированный линейный поиск\n");
	printf("3. блоковый поиск\n");
	printf("4. двоичный поиск\n");
	printf("5. фибоначчиев поиск\n");
	printf("6. интрепол€ционный поиск\n");
	printf("7. выход\n");
}

void printPos(int* arr, int pos) {
	printf("%d : %d\n", pos, arr[pos]);
}

/* линенйный поиск */ // O(n)
int linSearch(int* arr, int n, int x) {
	for (int i = 0; i < n; i++) {
		printPos(arr, i);

		if (arr[i] == x) return i;
	}

	return -1;
}

/* оптимизированный линейный поиск дл€ отсортированного массива */ // O(n)
int linSearch_s(int* sorted_arr, int n, int x) {
	int i;
	for (i = 0; sorted_arr[i] < x && i < n - 1; i++) {
		printPos(sorted_arr, i);
	}
	printPos(sorted_arr, i);
	
	return sorted_arr[i] == x ? i : -1;
}

/* минимум из двух чисел */
int min(int a, int b) {
	return a < b ? a : b;
}

/* блоковый поиск */ // O(n ^ (1 / 2))
int blockSearch(int* sorted_arr, int n, int x) {
	int p = Isqrt(n);
	int lft = 0, rght = p - 1;

	while (sorted_arr[min(rght, n - 1)] < x) {
		printPos(sorted_arr, min(rght, n - 1));

		lft += p; rght += p;
		if (lft >= n) return -1;
	}

	rght = min(rght, n - 1);
	while (sorted_arr[lft] < x) {
		printPos(sorted_arr, lft);

		lft++;

		if (lft > rght) return -1;
	}
	printPos(sorted_arr, lft);

	return sorted_arr[lft] == x ? lft : -1;
}

/* двоичный поиск */ // O(log(n))
int binSearch(int* sorted_arr, int n, int x) {
	int lft = 0, rght = n - 1, mid;
	while (lft <= rght) {
		mid = (lft + rght) / 2;

		printPos(sorted_arr, mid);

		if (sorted_arr[mid] > x) {
			rght = mid - 1;
		}
		else if (sorted_arr[mid] < x) {
			lft = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

/* фибоначчиев поиск */ // O(log(n))
int fibSearch(int* sorted_arr, int n, int x) {
	int start = -1, i;

	int f0 = 0, f1 = 1, f2 = 1;
	while (f2 < n) {
		f0 = f1; f1 = f2; f2 = f0 + f1;
	}

	while (f2 > 1) {
		i = min(start + f0, n - 1);

		printPos(sorted_arr, i);

		if (sorted_arr[i] < x) {
			f2 = f1; f1 = f0; f0 = f2 - f1;

			start = i;
		}
		else if (sorted_arr[i] > x) {
			f2 = f0; f1 = f1 - f0; f0 = f2 - f1;
		}
		else {
			return i;
		}
	}

	if (f1 && sorted_arr[n - 1] == x) {
		printPos(sorted_arr, n - 1);

		return n - 1;
	}

	return -1;
}	

/* интерпол€ционный поиск */ // O(n)
int interSearch(int* sorted_arr, int n, int x) {
	int lft = 0, rght = n - 1, mid;
	while (lft <= rght) {
		mid = lft + (rght - lft) * (x - sorted_arr[lft]) / (sorted_arr[rght] - sorted_arr[lft]);

		if (mid < 0) return -1;

		printPos(sorted_arr, mid);

		if (sorted_arr[mid] > x) {
			rght = mid - 1;
		}
		else if (sorted_arr[mid] < x) {
			lft = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

/*
int main() {
	setlocale(LC_ALL, "");

	printf("number of elements: "); int n; scanf_s("%d", &n);
	int* a = new int[n];
	printf("fill the array (%d elements)\n", n); scanfArr(a, n);

	int* b = new int[n];
	copyArray(b, a, n);
	nat2MergeSort(a, n);

	printSearches();

	bool cycle = true;
	int nSearch, x;
	while (cycle) {
		printf("элемент дл€ поиска: "); scanf_s("%d", &x);
		printf("номер операции: "); scanf_s("%d", &nSearch);

		switch (nSearch) {
		case 1: {
			printIntArr(b, n);
			printf("%d\n", linSearch(b, n, x));
			break;
		}
		case 2: {
			printIntArr(a, n);
			printf("%d\n", linSearch_s(a, n, x));
			break;
		}
		case 3: {
			printIntArr(a, n);
			printf("%d\n", blockSearch(a, n, x));
			break;
		}
		case 4: {
			printIntArr(a, n);
			printf("%d\n", binSearch(a, n, x));
			break;
		}
		case 5: {
			printIntArr(a, n);
			printf("%d\n", fibSearch(a, n, x));
			break;
		}
		case 6: {
			printIntArr(a, n);
			printf("%d\n", interSearch(a, n, x));
			break;
		}
		case 7: {
			cycle = false;
			break;
		}
		default: {
			printf("something went wrong...\n");
			break;
		}
		}
	}

	delete[] a;
	delete[] b;

	return 0;
}
*/