#include <stdio.h>
#include <limits>

int n1() {
	int n;
	scanf_s("%d", &n);

	int count = 0, sum = 0;

	while (n > 0) {
		count++;
		sum += n % 10;
		n /= 10;
	}

	printf("%d digits\nsum of digits: %d\n", count, sum);

	return 0;
}

int n2() {
	int n;
	scanf_s("%d", &n);
	int copy = n;

	int rev = 0;

	while (n > 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	if (rev == copy) printf("%d is a palindrome\n", copy);
	else printf("%d is not a palindrome\n", copy);

	return 0;
}

int n3() {
	int n;
	scanf_s("%d", &n);

	if (n < 10) {
		int mult = 1, fact = 1;
		while (mult <= n) {
			fact *= mult++;
		}
		printf("%d! = %d\n", n, fact);
	}
	else {
		int k;
		scanf_s("%d", &k);

		int prod = 1;
		for (int i = 0; i < k; i++) {
			prod *= n;
		}

		printf("%d^%d = %d\n", n, k, prod);
	}

	return 0;
}

int n4() {
	int n;
	printf("amount: "); scanf_s("%d", &n);

	int x, max = INT_MIN;
	for (int i = 0; i < n; i++) {
		printf("element: "); scanf_s("%d", &x);
		if (x > max) max = x;
	}

	if (max % 2) printf("the largest element %d is odd\n", max);
	else printf("the largest element %d is even\n", max);

	return 0;
}

int n5() {
	int n;
	printf("amount: "); scanf_s("%d", &n);

	int a, sum = 0;
	for (int i = 0; i < n; i++) {
		printf("element: "); scanf_s("%d", &a);
		if (a % 10 == 5) sum += a;
	}
	printf("sum of elements with the last digit 5: %d\n", sum);

	return 0;
}

int n6() {
	int n;
	scanf_s("%d", &n);

	int flag = 0, p = 1;
	for (int i = 1; i < 31; i++) {
		if (n == p) {
			flag = 1;
			break;
		}
		p <<= 1;
	}


	if (flag) printf("%d is a power of 2\n", n);
	else printf("%d is not a power of 2\n", n);

	return 0;
}

int n7() {
	int n;
	printf("amount: "); scanf_s("%d", &n);

	int a, max = INT_MIN, ind = 0;
	for (int i = 0; i < n; i++) {
		printf("element: "); scanf_s("%d", &a);
		if (a < 0 && a > max) {
			max = a;
			ind = i + 1;
		}
	}

	if (ind) printf("the largest negative element %d, it's %d in order\n", max, ind);
	else printf("no negative elements\n");

	return 0;
}

int n8() {
	int n;
	scanf_s("%d", &n);

	int flag = 1;
	for (int i = 2; i <= n / 2; i++) {
		if (!(n % i)) {
			flag = 0;
			break;
		}
	}

	if (flag && n != 1) printf("%d is a prime\n", n);
	else printf("%d is not a prime\n", n);

	return 0;
}

int n9() {
	int n;
	scanf_s("%d", &n);
	int copy = n;

	int flag = 0;
	while (n > 0) {
		if (n % 10 == 9) {
			flag = 1;
			break;
		}
		n /= 10;
	}

	if (flag) printf("9 is in %d\n", copy);
	else printf("9 is not in %d\n", copy);

	return 0;
}

int n10() {
	const int n = 5;
	int a[n], i, sgn1, sgn2, j = 0, flag = 1;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
		if (a[i]) {
			a[j] = a[i];
			j++;
		}
	}

	if (a[0] > 0) sgn1 = 1;
	else sgn1 = -1;
	for (i = 1; i < j; i++) {
		if (a[i] > 0) sgn2 = 1;
		else sgn2 = -1;

		if (sgn1 == sgn2) {
			flag = 0;
			break;
		}

		sgn1 = sgn2;
	}

	printf("sequence without 0:\n");
	for (i = 0; i < j; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	if (j <= 1) printf("can't check alternativity\n");
	else if (flag) printf("the sequence is alternating\n");
	else printf("the sequence is not alternating\n");

	return 0;
}

int n11() {
	const int n = 5;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	int min = INT_MAX, max = INT_MIN, p, q, t;
	for (i = 0; i < n; i++) {
		if (a[i] > max) {
			p = i;
			max = a[i];
		}
		if (a[i] < min) {
			q = i;
			min = a[i];
		}
	}

	t = a[q];
	a[q] = a[p];
	a[p] = t;

	printf("new sequence:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

int n12() {
	const int n = 5;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	int flag = 1;
	for (i = 0; i < n - 1; i++) {
		if (a[i] >= a[i + 1]) {
			flag = 0;
			break;
		}
	}

	if (flag) printf("sequence is increasing\n");
	else printf("sequence is not increasing\n");

	return 0;
}

int n13() {
	int n;
	scanf_s("%d", &n);

	int x[10] = { 0 };
	while (n > 0) {
		x[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (x[i]) {
			printf("digits \"%d\": %d\n", i, x[i]);
		}
	}

	return 0;
}

int n14() {
	const int n = 10;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	int k, t;
	printf("number of moves: "); scanf_s("%d", &k);
	for (i = 0; i < k % n; i++) {
		t = a[n - 1];
		for (int j = n - 1; j > 0; j--) {
			a[j] = a[j - 1];
		}
		a[0] = t;
	}

	printf("the result of %d moves:\n", k);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

int n15() {
	const int n = 5;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	int C, ind = -1;
	printf("number to search: "); scanf_s("%d", &C);

	for (i = 0; i < n; i++) {
		if (a[i] == C) {
			ind = i;
			break;
		}
	}

	if (ind >= 0) printf("element %d has index %d\n", C, ind);
	else printf("no %d in sequence\n", C);

	return 0;
}