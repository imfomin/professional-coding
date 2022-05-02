#include <stdio.h>
#include "funks_header.h"

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
	if (lft == rght) return;

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

	if (lft <= j) qSort_r(arr, lft, j);
	if (i <= rght) qSort_r(arr, i, rght);
}

int main() {
	int a[10] = { 13, 7, 8, 12, 4, 10, 1, 21, 9, 2 };
	printIntArr(a, 10);
	int help[3] = { 9, 3, 1 };

	// insSort(a, 10);
	// shellSort(a, 10, help, 3);
	// bubbleSort(a, 10);
	qSort_r(a, 0, 9);

	printIntArr(a, 10);

	return 0;
}