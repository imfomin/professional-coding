#include <stdio.h>
#include "funks_header.h"

int linSearch(int* arr, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) return i;
	}

	return -1;
}

int linSearch_s(int* sorted_arr, int n, int x) {
	int i;
	for (i = 0; sorted_arr[i] < x && i < n - 1; i++);
	
	return sorted_arr[i] == x ? i : -1;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int blockSearch(int* sorted_arr, int n, int x) {
	int p = Isqrt(n);
	int lft = 0, rght = p - 1;

	while (sorted_arr[min(rght, n - 1)] < x) {
		lft += p; rght += p;
		if (lft >= n) return -1;
	}

	rght = min(rght, n - 1);
	while (sorted_arr[lft] < x) {
		lft++;

		if (lft > rght) return -1;
	}

	return sorted_arr[lft] == x ? lft : -1;
}

int binSearch(int* sorted_arr, int n, int x) {
	int lft = 0, rght = n - 1, mid;
	while (lft <= rght) {
		mid = (lft + rght) / 2;

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

int fibSearch(int* sorted_arr, int n, int x) {
	int start = -1, i;

	int f0 = 0, f1 = 1, f2 = 1;
	while (f2 < n) {
		f0 = f1; f1 = f2; f2 = f0 + f1;
	}

	while (f2 > 1) {
		i = min(start + f0, n - 1);

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
		return n - 1;
	}

	return -1;
}	

int interSearch(int* sorted_arr, int n, int x) {
	int lft = 0, rght = n - 1, mid;
	while (lft <= rght) {
		mid = lft + (rght - lft) * (x - sorted_arr[lft]) / (sorted_arr[rght] - sorted_arr[lft]);

		if (mid < 0) return -1;

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

int main() {
	int a[10] = { 3, 9, 4, 4, 8, 5, 12, 18, 17, 6 };
	int b[10] = { 3, 4, 4, 5, 6, 8, 9, 12, 17, 18 };

	// printf("%d %d %d\n", linSearch(a, 10, 12), linSearch(a, 10, 100), linSearch(a, 10, 0));
	// printf("%d %d %d\n", linSearch_s(b, 10, 12), linSearch_s(b, 10, 100), linSearch_s(b, 10, 0));
	// printf("%d %d %d\n", blockSearch(b, 10, 12), blockSearch(b, 10, 100), blockSearch(b, 10, 0));
	// printf("%d %d %d\n", binSearch(b, 10, 12), binSearch(b, 10, 100), binSearch(b, 10, 0));

	printf("%d %d %d\n", fibSearch(b, 10, 9), fibSearch(b, 10, 100), fibSearch(b, 10, 0));

	// printf("%d %d %d\n", interSearch(b, 10, 12), interSearch(b, 10, 100), interSearch(b, 10, 0));

	return 0;
}