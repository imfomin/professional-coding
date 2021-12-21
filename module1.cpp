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

	// делим число на 2 пока оно чётное
	while (n % 2 == 0) n /= 2;

	// если в конце осталась 1, то число было степенью двойки
	if (n == 1) printf("%d is a power of 2\n", n);
	else printf("%d is not a power of 2\n", n);

	return 0;
}

int n7() {
	int n; // количество элементов
	printf("amount: "); scanf_s("%d", &n);

	int a, max = INT_MIN, ind = 0; // ind - позиция текущего элемента

	// i от 1 до n включительно - позиция текущего элемента
	for (int i = 1; i <= n; i++) {
		printf("element: "); scanf_s("%d", &a); // ввод очередного элемента
		
		/*если элемент больше текущего максимиума и при этом отрицательный,
		запоминаем этот элемент и его позицию*/

		if (a < 0 && a > max) {
			max = a;
			ind = i;
		}
	}

	// если элемент нашёлся то ind больше или равен 1 ---> сработает первый printf
	if (ind) printf("the largest negative element %d, it's %d in order\n", max, ind);
	else printf("no negative elements\n");

	return 0;
}

int n8() {
	// проверка на простоту
	int n;
	scanf_s("%d", &n);

	int flag = 1, t = n / 2;
	for (int i = 2; i <= t; i++) {
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
	// перебор по всем цифрам n
	while (n > 0) {
		// если какая-то цифра равна 9, то flag = 1 и происходит выход из цикла
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
	// создание и заполнение статического массива
	const int n = 7;
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	// создание и заполнение нового массива b, в котором будут элементы массива a, кроме нулей
	// идёт перебор по элементам массива a
	int b[n], j = 0; // j - индекс элементов в новом массиве
	for (int i = 0; i < n; i++) {

		/* если очередной элемент из a не равено нулю,
		то записываем его в b по индексу j (j - первая свободная ячейка в b)
		и увеличиваем j на 1 (переходим к следующей свободной ячейке*/

		if (a[i] != 0) {
			b[j] = a[i];
			j++;
		}
	}

	/*после этого цикла в b будет j ненулевых элементов из a (имеется ввиду последнее значение j)
	и n - j свободных ячеек (но это нам не понадобится)*/

	// проверка на чередование знаков
	int flag = 1;
	for (int i = 0; i < j - 1; i++) { // i < j - 1, чтобы во время проверки не попасть на пустую ячейку

		/*если два соседних элемента в произведении дают положительное число,
		то это элементы одного знака, а значит чередования знаков нет,
		flag = 0 и выход из цикла*/

		if (b[i] * b[i + 1] > 0) {
			flag = 0;
			break;
		}
	}

	// печать последовательности без нулей
	for (int i = 0; i < j; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");

	// печать результата
	if (j <= 1) printf("couldn't check alternativity\n");
	else if (flag) printf("alternating\n");
	else printf("not alternating\n");
}

int n11() {
	// создание и заполнение массива
	const int n = 5;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	// нахождение максимального и минимального элемента и их индексов
	/*после этого цикла в max и p будет лежать значение и индекс максимального элемента,
	а в min и q - минимального*/
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

	// максимальный и минимальный элемент меняются местами
	t = a[q];
	a[q] = a[p];
	a[p] = t;

	// печать результата
	printf("new sequence:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

int n12() {
	// создание и заполнение массива
	const int n = 5;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	// проверка на строгое возрастание (возрастание в уссс...ком смысле слова))
	int flag = 1;
	for (i = 0; i < n - 1; i++) {
		/* если последующий элемент меньше либо равен предущего, то последовательность не возрастает,
		flag = 0 и выход из цикла*/
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
	int n; // исходное число
	scanf_s("%d", &n);

	int x[10] = { 0 }; // создание массива из 10 нулей
	// перебор по цифрам числа
	while (n > 0) {

		/*при считывании очередной цифры увеличивается на 1 соответсвующая ему ячейка в массиве
		(ячейке с индексом 0 соотвествует цифра 0, индексу 1 - цифра 1 и так далее до 9)*/

		x[n % 10]++;
		n /= 10;
	}
	//после цикла в массиве x по i-тому индексу будет лежать количество цифр i в числе n

	// для каждой цифры выводим их количество в числе n (если оно не 0)
	// здесь i - цифра от 0 до 9, x[i] - количество этих цифр в n
	for (int i = 0; i < 10; i++) {
		if (x[i]) {
			printf("digits \"%d\": %d\n", i, x[i]); // \" - служебный символ для печати кавычек
		}
	}

	return 0;
}

int n14() {
	// создание и заполнение массива
	const int n = 10;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	int k, t; // k - количество сдигов
	printf("number of moves: "); scanf_s("%d", &k);
	/* одна итерация цикла - один сдвиг
	результат k сдвигов равен результату k % n сдвигов 
	(каждые n сдвигов возвращают исходную последовательность*/

	for (i = 0; i < k % n; i++) {
		/*запоминаем крайний справа элемент в t*/
		t = a[n - 1];
		/*каждый элемент записываем на место следующего*/
		for (int j = n - 1; j > 0; j--) {
			a[j] = a[j - 1];
		}
		/*на место крайнего левого элемента записываем старый крайний справа*/
		a[0] = t;
	}

	// печать результата
	printf("the result of %d moves:\n", k);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

int n15() {
	// создание и заполненеи массива
	const int n = 5;
	int a[n], i;
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf_s("%d", &a[i]);
	}

	// ввод искомого элемента
	int C, ind = -1;
	printf("number to search: "); scanf_s("%d", &C);

	// перебор элементов массива
	for (i = 0; i < n; i++) {
		// если искомый элемент нашёлся, запоминаем его индекс и выходим из цикла
		if (a[i] == C) {
			ind = i;
			break;
		}
	}

	// если элемент нашёлся то ind больше либо равен 0, если не нашёлся - ind остался равным -1
	if (ind >= 0) printf("element %d has index %d\n", C, ind);
	else printf("no %d in sequence\n", C);

	return 0;
}