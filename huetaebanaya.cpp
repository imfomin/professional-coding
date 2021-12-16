#include <stdio.h>
#include "head.cpp"

int sumdig(int n) {
	int s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	
	return s;
}
int d(int n) {
	return n + sumdig(n);
}
bool hasgen(int n) {
	if (n == 0) return true;
	for (int i = 1; i < n; i++) {
		if (d(i) == n) return true;
	}
	return false;
}
void selfgens(int N) {
	int i = 0;
	while (i <= N) {
		if (!hasgen(i)) printf("%d ", i);
		i++;
	}
	printf("\n");
}
int n1p() {
	selfgens(100);

	return 0;
}

int** matxprod(int** A, int** B, int n) {
	int** C = create_matrix(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int* help = vcol(B, n, j);
			C[i][j] = sc_prod(A[i], help, n);
			delete[] help;
		}
	}
		
	return C;
}
int** matxsum(int** A, int** B, int n) {
	int** C = create_matrix(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	return C;
}
int** emtx(int n) {
	int** E = create_matrix(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) E[i][j] = 1;
			else E[i][j] = 0;
		}
	}

	return E;
}
int main() {
	int n; scanf_s("%d", &n);
	int** A = create_matrix(n, n);
	fill_matrix(A, n, n);
	int** B = create_matrix(n, n);
	fill_matrix(B, n, n);
	int** E = emtx(n);

	int** R = matxprod(A, matxsum(E, matxprod(B, B, n), n), n);
	print_matrix(R, n, n);

	delete_matrix(A, n, n);
	delete_matrix(B, n, n);
	delete_matrix(E, n, n);
	delete_matrix(R, n, n);
}
