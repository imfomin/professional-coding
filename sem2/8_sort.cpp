#include <stdio.h>
#include "funks_header.h"
#include <limits>

void insSort(int* arr, int n) {
	int temp, j;
	for (int i = 1; i < n; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;

		// printIntArr(arr, n);
	}
}

void shellSort(int* arr, int n, int* seq, int t) {
	int h, b, j;
	for (int s = 0; s < t; s++) {
		h = seq[s];
		for (int i = h; i < n; i++) {
			b = arr[i];
			j = i - h;
			while (j >= 0 && arr[j] > b) {
				arr[j + h] = arr[j];
				j -= h;
			}
			arr[j + h] = b;
		}

		// printIntArr(arr, n);
	}
}

void bubbleSort(int* arr, int n) {
	int B = n, t;
	while (B) {
		t = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;

				t = i;
			}
		}
		B = t;

		// printIntArr(arr, n);
	}
}

void qSort_r(int* arr, int lft, int rght) {
	if (lft >= rght) {
		// printIntArr(arr, 10);
		return;
	}

	int i = lft, j = rght;
	int x = arr[(i + j) / 2];
	int t;

	while (i <= j) {
		while (arr[i] < x && i <= rght) i++;
		while (arr[j] >= x && j >= lft) j--;

		if (i < j) {
			t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
			i++; j--;
		}
	}

	// printIntArr(arr, 10);

	if (i == lft && j < i) i++;
	if (j == rght && i > j) j--;

	if (lft <= j) qSort_r(arr, lft, j);
	if (i <= rght) qSort_r(arr, i, rght);
}

struct edges {
	int left;
	int right;
};

void qSort_i(int* arr, int n) {
	edges* b = new edges[n];
	int k = 0;
	b[k].left = 0; b[k].right = n - 1;

	int lft, rght, x, t, i, j;

	while (k >= 0) {
		lft = b[k].left; rght = b[k].right;
		k--;

		i = lft, j = rght;
		x = arr[(i + j) / 2];

		while (i <= j) {
			while (arr[i] < x && i <= rght) i++;
			while (arr[j] >= x && j >= lft) j--;

			if (i < j) {
				t = arr[j];
				arr[j] = arr[i];
				arr[i] = t;
				i++; j--;
			}
		}

		// printIntArr(arr, n);

		if (i == lft && j < i) i++;
		if (j == rght && i > j) j--;

		if (lft <= j) {
			k++;
			b[k].left = lft; b[k].right = j;
		}
		if (i <= rght) {
			k++;
			b[k].left = i; b[k].right = rght;
		}
	}

	delete[] b;
}

void brushSort(int* arr, int n, int* seq, int t) {
	int h, temp;
	for (int s = 0; s < t; s++) {
		h = seq[s];
		for (int i = 0; i < n - h; i++) {
			if (arr[i] > arr[i + h]) {
				temp = arr[i];
				arr[i] = arr[i + h];
				arr[i + h] = temp;
			}
		}

		printIntArr(arr, n);
	}
	bubbleSort(arr, n);
}

void choiceSort(int* arr, int n) {
	int k, t;
	for (int i = 0; i < n; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[k]) k = j;
		}
		t = arr[i];
		arr[i] = arr[k];
		arr[k] = t;

		printIntArr(arr, n);
	}
}

/*int Isqrt(int n) {
	int pr = 0;
	for (int i = 1; i < n; i++) {
		if (i * i > n) return pr;
		pr = i;
	}

	return 0;
}

int blockmin(int* arr, int n, int lft, int rght) {
	int j = lft;
	for (int i = lft + 1; i <= rght && i < n; i++) {
		if (arr[i] < arr[j]) j = i;
	}

	return j;
}

struct local_min {
	int value;
	int global_index;
};

int min(local_min* arr, int n) {
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i].value < arr[k].value) k = i;
	}
	return k;
}

void sqChoiceSort(int* arr, int n) {
	int p = Isqrt(n), q = p;
	if (p * p != n) q++;

	local_min* mins = new local_min[q];
	int* sorted = new int[n];
	int k, t;



	delete[] mins;
	delete[] sorted;
}*/

int main() {
	int a[10] = { 13, 7, 8, 12, 4, 10, 1, 21, 9, 2 };
	printIntArr(a, 10);
	int help1[3] = { 9, 3, 1 };
	int help2[4] = { 7, 5, 3, 2 };

	// insSort(a, 10);
	// shellSort(a, 10, help1, 3);
	// bubbleSort(a, 10);
	// qSort_r(a, 0, 9);
	// qSort_i(a, 10);
	// brushSort(a, 10, help2, 4);
	// choiceSort(a, 10);
	// !!!!!!!sqChoiceSort(a, 10);

	printIntArr(a, 10);

	return 0;
}
