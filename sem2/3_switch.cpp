#include <stdio.h>
#include "str_header.h"
#include "const.h"

void printMenu() {
	printf("1. Ввести строки\n");
	printf("2. Посчитать длины\n");
	printf("3. Конкатенация\n");
	printf("4. Копировать\n");
	printf("5. Найти символ\n");
	printf("6. Найти подстроку\n");
	printf("7. Сравнить\n");
	printf("8. Печать строк\n");
	printf("9. Выход\n");
}

/*
int main() {
	char* str1 = new char[STRING_SIZE];
	char* str2 = new char[STRING_SIZE];
	char* substr = new char[STRING_SIZE];
	char chr;
	int nFunc;
	bool cycle = true;

	printMenu();

	while (cycle) {
		scanf_s("%d", &nFunc);
		scanf_s("%c", &chr);

		switch (nFunc) {
		case 1: {
			gets_s(str1, STRING_SIZE);
			gets_s(str2, STRING_SIZE);

			printf("ok\n");
			break;
		}
		case 2: {
			printf("1st string: %d\n", strlen_a(str1, STRING_SIZE));
			printf("2nd string: %d\n", strlen_a(str2, STRING_SIZE));
			break;
		}
		case 3: {
			if (!strcat_a(str1, STRING_SIZE, str2, STRING_SIZE)) {
				printf("something went wrong...\n");
			}
			else {
				printf("ok\n");
			}
			break;
		}
		case 4: {
			if (!strcpy_a(str1, STRING_SIZE, str2, STRING_SIZE)) {
				printf("something went wrong...\n");
			}
			else {
				printf("ok\n");
			}
			break;
		}
		case 5: {
			printf("enter char: "); scanf_s("%c", &chr);

			char* chr1 = strchr_a(str1, STRING_SIZE, chr);
			char* chr2 = strchr_a(str2, STRING_SIZE, chr);

			if (chr1) {
				printf("%c is on %d position in str1\n", chr, (int)(chr1 - str1));
			}
			else {
				printf("no char in str1\n");
			}
			if (chr2) {
				printf("%c is on %d position in str2\n", chr, (int)(chr2 - str1));
			}
			else {
				printf("no char in str2\n");
			}

			break;
		}
		case 6: {
			printf("enter substring: "); gets_s(substr, STRING_SIZE);

			char* sub1 = strstr_a(str1, STRING_SIZE, substr, STRING_SIZE);
			char* sub2 = strstr_a(str2, STRING_SIZE, substr, STRING_SIZE);

			if (sub1) {
				printf("%s is on %d position in str1\n", substr, (int)(sub1 - str1));
			}
			else {
				printf("no substring in str1\n");
			}
			if (sub2) {
				printf("%s is on %d position in str2\n", substr, (int)(sub2 - str1));
			}
			else {
				printf("no substring in str2\n");
			}

			break;
		}
		case 7: {
			int cmp = strcmp_a(str1, STRING_SIZE, str2, STRING_SIZE);
			if (!cmp) {
				printf("something went wrong...\n");
			}
			else {
				printf("compare {%s} to {%s}: %d\n", str1, str2, cmp);
			}

			break;
		}
		case 8: {
			puts(str1);
			puts(str2);s
			break;
		}
		case 9: {
			cycle = false;
			break;
		}
		default:
			printf("wrong number\n");
			break;
		}
	}

	delete[] str1;
	delete[] str2;
	delete[] substr;
}
*/