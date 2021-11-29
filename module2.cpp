#include <stdio.h>
#include <limits>

int* create_arr(int n) {
	return new int[n];
}
void fill_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		scanf_s("%d", arr++);
	}
}
void delete_arr(int* arr) {
	delete[] arr;
}

void n16find_closest(int* arr, int n, int M, int& index, int& value) {
	int mindif = INT_MAX, dif;
	for (int i = 0; i < n; i++) {
		dif = abs(M - arr[i]);
		if (dif < mindif) {
			mindif = dif;
			index = i;
			value = arr[i];
		}
	}
}
int n16() {
	int n; scanf_s("%d", &n);
	int* a = create_arr(n);
	fill_arr(a, n);

	int M, ind, val; scanf_s("%d", &M);
	n16find_closest(a, n, M, ind, val);

	printf("closest to %d is %d on place %d\n", M, val, ind);

	delete_arr(a);

	return 0;
}

int** create_matrix(int n, int m) {
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	return a;
}
void fill_matrix(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &mat[i][j]);
		}
	}
}
void delete_matrix(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

int n17sum_row(int* row, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += row[i];
	}
	return sum;
}
void n17find_smallestSumRow(int** mat, int n, int m, int& index, int& sum_value) {
	int minSum = INT_MAX, row_sum;
	for (int i = 0; i < n; i++) {
		row_sum = n17sum_row(mat[i], m);
		if (row_sum < minSum) {
			minSum = row_sum;
			index = i;
			sum_value = row_sum;
		}
	}
}
int n17() {
	int n, m;
	scanf_s("%d", &n); scanf_s("%d", &m);
	int** a = create_matrix(n, m);
	fill_matrix(a, n, m);

	int ind, sum;
	n17find_smallestSumRow(a, n, m, ind, sum);
	
	printf("smallest sum %d has row %d\n", sum, ind);

	delete_matrix(a, n, m);

	return 0;
}

void print_matrix(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int** n18a_trans_n_copy(int** a, int n, int m) {
	int** b = create_matrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][i];
		}
	}
	return b;
}
void n18b_trans_n_stay(int** a, int n) {
	int t;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}
}
int n18() {
	int n; scanf_s("%d", &n);
	int** a = create_matrix(n, n);
	fill_matrix(a, n, n);

	int** aT = n18a_trans_n_copy(a, n, n);
	n18b_trans_n_stay(a, n);

	printf("\n");
	printf("transponented matrix (a):\n");
	print_matrix(aT, n, n);

	printf("transponented matrix (b):\n");
	print_matrix(a, n, n);

	delete_matrix(a, n, n);
	delete_matrix(aT, n, n);

	return 0;
}

int n19check_purmutation(int* arr, int n) {
	int C;
	for (int i = 0; i < n; i++) {
		C = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == C) return 0;
		}
	}

	return 1;
}
int count_permutations(int** mat, int n, int m) {
	int i, count = 0;
	for (i = 0; i < n; i++) {
		count += n19check_purmutation(mat[i], m);
	}
	
	return count;
}
int n19() {
	int n, m;
	scanf_s("%d", &n); scanf_s("%d", &m);
	int** mat = create_matrix(n, m);
	fill_matrix(mat, n, m);

	int** matT = n18a_trans_n_copy(mat, n, m);

	int c1 = count_permutations(mat, n, m), c2 = count_permutations(matT, m, n);
	printf("permutations in rows: %d\n", c1);	
	printf("permutations in columns: %d\n", c2);
	printf("together: %d\n", c1 + c2);

	delete_matrix(matT, m, n);
	delete_matrix(mat, n, m);

	return 0;
}

bool n20isperfect(int n) {
	int halfn = n / 2, sum = 0;
	for (int i = 0; i <= halfn; i++) {
		if (!(n % i)) sum += i;
	}

	return sum == n;
}
void find_perfects(int* arr, int n, int& p, int& q) {
	int i;
	for (i = 0; i < n; i++) {
		if (n20isperfect(arr[i])) {
			p = i;
			break;
		}
	}
	for (i = n - 1; i >= 0; i--) {
		if (n20isperfect(arr[i])) {
			q = i;
			break;
		}
	}
}
int check_progression(int* arr, int first, int last) {
	if (last - first <= 2) return -1;
	else {
		int d = arr[first + 2] - arr[first + 1];
		for (int i = first + 2; i < last - 1; i++) {
			if (arr[i + 1] - arr[i] != d) return 0;
		}

		return 1;
	}
}
int main() {
	int n;
	scanf_s("%d", &n);
	int* a = create_arr(n);
	fill_arr(a, n);

	int f = 0, l = 0;
	find_perfects(a, n, f, l);
	
	int res = check_progression(a, f, l);
	if (!res) printf("not a progression\n");
	else if (res == 1) printf("progression\n");
	else printf("no sequence\n");

	delete_arr(a);
}