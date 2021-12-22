#include <stdio.h>
#include <limits>

// выделени памяти для одномерного массива
int* create_arr(int n) {
	return new int[n]; // выделяется память и возвращается адрес первого элемента
}
// заполнение одномерного массива
void fill_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
// освобождение памяти одномерного массива
void delete_arr(int* arr) {
	delete[] arr;
} // не знаю нахуя для этого отдельная функция но пусть будет // не знаю нахуя для этого отдельная функция но пусть будет

// нахождение ближайшего элемента к М в массиве
void clM(int* arr, int n, int M, int& index, int& value) {
	int mindif = INT_MAX, dif;
	for (int i = 0; i < n; i++) {
		dif = abs(M - arr[i]); // разность M и очередного элемента массива

		/*если разность элементов меньше текущего минимума,
		то запоминаем индекс и значение элемента в переменные index и value
		(переданные в функцию по ссылке)*/

		if (dif < mindif) {
			mindif = dif;
			index = i;
			value = arr[i];
		}
	}
}
int n16() {
	// создание заполнение
	int n; scanf_s("%d", &n);
	int* a = create_arr(n);
	fill_arr(a, n);

	int M, ind, val; scanf_s("%d", &M);
	
	// в массиве а размера n находится ближайшйи к M элемент, результат сохраняется в ind и val
	clM(a, n, M, ind, val);

	printf("closest to %d is %d on index %d\n", M, val, ind);

	delete_arr(a);

	return 0;
}

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

// сумма элементов массива
int sum(int* row, int n) {
	// перебор по n элементам массива row
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += row[i]; // складываются все эллемнты
	}
	return sum; // возвращается сумма
}
// нахождение строки с наименьшей суммой
void rowSmSum(int** mat, int n, int m, int& index, int& sum_value) {
	int minSum = INT_MAX, row_sum;
	// перебор по строкам матрицы mat (i - номер очередной строки)
	for (int i = 0; i < n; i++) {
		row_sum = sum(mat[i], m); // считается сумма каждой строки из матрицы mat
		
		/*если очередная сумма меньше минимума,
		результат сохраняется в index - номер строки и sum_value - значение суммы*/
		
		if (row_sum < minSum) {
			minSum = row_sum;
			index = i;
			sum_value = row_sum;
		}
	}

	// ничего не возвращается так как результат записывется в index и value по ссылке
}
int n17() {
	// создание заполнение
	int n, m;
	scanf_s("%d", &n); scanf_s("%d", &m);
	int** a = create_matrix(n, m);
	fill_matrix(a, n, m);

	// работает функция rowSmSum, которая запишет номер строки и её сумму в ind и sum
	int ind, sum;
	rowSmSum(a, n, m, ind, sum);
	
	printf("smallest sum %d has row %d\n", sum, ind);

	delete_matrix(a, n, m);

	return 0;
}

// печать массива, матрицы
void print_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
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

// транспонирование
int** transponented(int** a, int n, int m) {
	// создаётся новая матрица b с изменённой размерностью - будущий результат транспонирования
	int** b = create_matrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// в каждую ячейку b записывается соответствующая ячейка из a
			b[i][j] = a[j][i];
		}
	}
	return b; // возращаем адрес первого элемента новой матрицы
}
void transponent(int** a, int n) {
	// транспонирование исходной матрицы
	// здесь результат записывается в исходную матрицу
	int t;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // перебор идёт только по элементам выше главной диагонали
			// элементы симметрично меняются местами
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}
}
int n18() {
	// создани заполнение
	int n; scanf_s("%d", &n);
	int** a = create_matrix(n, n);
	fill_matrix(a, n, n);

	// создаётся новая матрица - транспонирванная a
	int** aT = transponented(a, n, n);
	// транспонируется исходная матрица a
	transponent(a, n);

	// печать результатов
	printf("\n");
	printf("transponented matrix (a):\n");
	print_matrix(aT, n, n);

	printf("transponented matrix (b):\n");
	print_matrix(a, n, n);

	delete_matrix(a, n, n);
	delete_matrix(aT, n, n);

	return 0;
}

// проверка строки на попарно различные элементы
int check_per(int* arr, int n) {
	int C;
	// перебор по всем элементам arr
	for (int i = 0; i < n; i++) {
		C = arr[i]; // очередной элемент
		for (int j = i + 1; j < n; j++) { // перебор по всем элементам после C
			if (arr[j] == C) return 0; // если хоть какой-то элемент совпадает, то вернётся 0
		}
	}

	return 1; // 1 вернётся если никакой элемент не повторяется
}
// подсчёт строк с попарно различными элементами
int count_per(int** mat, int n, int m) {
	int i, count = 0;
	for (i = 0; i < n; i++) { // перебор по строкам матрицы mat
		count += check_per(mat[i], m); // каждая строка проверяется функцией check_per
		// если в строке попарно раздичные элементы то count увеличится на 1, иначе не изменится
		// таким образом в count будет лежать количество попрано различных строк в матрице mat
	}
	
	return count; // возвращается искомое количество
}
int n19() {
	// создание заполнение
	int n, m;
	scanf_s("%d", &n); scanf_s("%d", &m);
	int** mat = create_matrix(n, m);
	fill_matrix(mat, n, m);

	int** matT = transponented(mat, n, m); // создание транспониорванной матрицы mat

	int c1 = count_per(mat, n, m), c2 = count_per(matT, m, n); // с1 - количество подходящих строк в mat
	// c2 - количество подходящий строк в matT (количество подходящйи столбцов в mat, так как matT - транспонироанная mat) 
	printf("permutations in rows: %d\n", c1);	
	printf("permutations in columns: %d\n", c2);
	printf("together: %d\n", c1 + c2);

	delete_matrix(matT, m, n);
	delete_matrix(mat, n, m);

	return 0;
}

// проверка числа на совершенность
bool isperfect(int n) {
	// подсчёт суммы делителей
	int hn = n / 2, sum = 0;
	for (int i = 1; i <= hn; i++) {
		if (!(n % i)) sum += i;
	}

	// если сумма делителей равная числу - вернётся true, иначе false
	return sum == n;
}
// нахождение индексов первого и последнего совершенных чисел
void find_sovs(int* arr, int n, int& fst, int& lst) {
	int i;
	// на случай если соверешнных чисел не окажется
	fst = lst = -1;
	// нахождение первого совершенного элемента, его индекс запишется в fst
	for (i = 0; i < n; i++) {
		if (isperfect(arr[i])) {
			fst = i;
			break;
		}
	}
	// нахождение последнего совершенного элемента, его индекс запишется в lst
	for (i = n - 1; i >= 0; i--) {
		if (isperfect(arr[i])) {
			lst = i;
			return;
		}
	}
}
// получение среза и его длины
int* slice(int* arr, int fst, int lst, int& newlen) {
	/*функция принимает массив и индексы между которыми нужно взять элементы и созранить их в новый массив*/
	newlen = lst - fst - 1; // длина нового массива (сразу записывается в какую-то переменную в основной программе)
	int* sl = new int[lst - fst - 1]; // созадается новый массив
	int i, j; // j - индекс элементов в нововм массиве
	for (i = fst + 1, j = 0; i < lst; i++, j++) { // в новый массив записываются только элементы между fst и lst
		sl[j] = arr[i];
	}
	return sl; // возращаем новый массив
}
// проверка на арифметическую прогрессию
bool check_prog(int* arr, int n) {
	int d = arr[1] - arr[0]; // разность первых двух элементов
	for (int i = 1; i < n - 1; i++) { // перебор по элементам массива
		if (arr[i + 1] - arr[i] != d) return false; // если где-то разность элементов не равна d возвращаем false
	}

	// между любыми соседними элементами одинаковая разность - возвращаем true
	return true;
}
int n20() {
	int n; scanf_s("%d", &n);
	int* arr = create_arr(n);
	fill_arr(arr, n);

	int fst, lst;
	// находим совершенные числа в массиве
	find_sovs(arr, n, fst, lst);
	
	if (lst - fst > 2) {
		int nlen;
		// создание среза между индексами fst и lst, новая длина записывается в nlen
		int* slc = slice(arr, fst, lst, nlen);
		if (check_prog(slc, nlen)) { // проврека новой последовательность на прогрессию (slc с длиной nlen)
			printf("it's a progression\n");
		}
		else {
			printf("it's not a progression\n");
		}
		delete_arr(slc);
	}
	else {
		// если разность между индексами совершенных чисел меньше или равно двум -
		// между ними 1 или 0 элементов

		printf("no sequence\n");
	}

	delete_arr(arr);

	return 0;
}

// нахождение последнего минимального элемента матрицы
int find_lst_min(int** mat, int n, int m, int& x, int& y) {
	// стандартный поиск минимума
	int min = INT_MAX;
	// перебор по всем элементам
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] <= min) { // <= чтобы найти последний минимальный элемент
				min = mat[i][j];
				x = i; y = j; // значение индексов по ссылке передаётся в x, y
			}
		}
	}
	return min; // возвращается само минимальное значение
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
int n21() {
	int n; scanf_s("%d", &n);
	int** mat = create_matrix(n, n);
	fill_matrix(mat, n, n);

	int x, y;
	int mn = find_lst_min(mat, n, n, x, y); // находится минимальный элемент, его индексы записываются в x, y
	int* row = mat[x]; // строка, в которой находится минимальный элемент (у неё индекс x)
	int* col = vcol(mat, n, y); // столбец, в котором находится минимальный элемент (у неё индекс y)

	printf("the smallest element is %d on place %d %d\n", mn, x, y); // печать минимального элемента и его индексов
	printf("scalar product of %d row and %d column is %d\n", x, y, sc_prod(row, col, n)); // печать скалярного произведение row и col

	delete_matrix(mat, n, n);
	delete_arr(col);

	return 0;
}

// сумма глваной диагонали
int sum_main(int** sqmat, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += sqmat[i][i];
	}
	return s;
}
// сумма побочной диагонали
int sum_side(int** sqmat, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += sqmat[i][n - 1 - i];
	}
	return s;
}
// сумма над главной диагональю
int sum_above_main(int** sqmat, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			s += sqmat[i][j];
		}
	}
	return s;
}
// сумма под главной диагональю
int sum_under_main(int** sqmat, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			s += sqmat[j][i];
		}
	}
	return s;
}
int n22() {
	int n; scanf_s("%d", &n);
	int** mat = create_matrix(n, n);
	fill_matrix(mat, n, n);

	printf("sum of main diagonal: %d\n", sum_main(mat, n));
	printf("sum of side diagonal: %d\n", sum_side(mat, n));
	printf("sum above main diagonal: %d\n", sum_above_main(mat, n));
	printf("sum under main diagonal: %d\n", sum_under_main(mat, n));

	delete_matrix(mat, n, n);

	return 0;
}

// является ли число числом Фибоначчи
bool isfib(int n) {
	int n1 = 0, n2 = 1, n3 = 1;

	// считается очередной число Фибоначчи, пока оно меньше исходного числа
	while (n > n1) {
		n1 = n2;
		n2 = n3;
		n3 = n1 + n2;		
	}

	// число Фибоначчи стало больше либо равно исходного, если равно то true, иначе false
	return n == n1;
}
// подсчёт чисел Фибоначчи
int count_fib(int* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (isfib(arr[i])) count++; // каждый элемент массива проверяется на Фибоначчи
	}

	return count;
}
int n23() {
	int n; scanf_s("%d", &n);
	int* a = create_arr(n);
	fill_arr(a, n);

	printf("%d fibonacci numbers\n", count_fib(a, n));

	delete_arr(a);

	return 0;
}

// поиск числа в массиве
bool isthere(int* arr, int n, int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num) return true; // если хоть одно число совпадает возвращается true
	}

	return false;
}
// подсчёт элемента для новой матрицы
int calcCij(int* row, int n, int* col, int m) {
	int cij = 0;
	for (int i = 0; i < n; i++) {
		if (!isthere(col, m, row[i])) cij += row[i];
	}

	return cij;
}
// создание новой матрицы
int** createC(int** A, int** B, int n, int m) {
	int** C = create_matrix(n, m);
	int* row; int* col;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			row = A[i];
			col = vcol(B, n, j);
			C[i][j] = calcCij(row, m, col, n);

			delete_arr(col);
		}
	}

	return C;
}
int n24() {
	int n, m; scanf_s("%d", &n); scanf_s("%d", &m);
	int** A = create_matrix(n, m);
	int** B = create_matrix(n, m);
	printf("enter the matrix:\n");
	fill_matrix(A, n, m);
	printf("enter the matrix:\n");
	fill_matrix(B, n, m);

	int** C = createC(A, B, n, m);
	printf("new matrix:\n");
	print_matrix(C, n, m);

	delete_matrix(A, n, m);
	delete_matrix(B, n, m);
	delete_matrix(C, n, m);

	return 0;
}

// проверка на неубывание
int isnondecr(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) return 0;
	}
	return 1;
}
int n25() {
	int n; scanf_s("%d", &n);
	int* a = create_arr(n);
	fill_arr(a, n);
	int m; scanf_s("%d", &m);
	int* b = create_arr(m);
	fill_arr(b, m);

	int k = isnondecr(a, n) + isnondecr(b, m);
	printf("k = %d\n", k);

	delete_arr(a);
	delete_arr(b);

	return 0;
}