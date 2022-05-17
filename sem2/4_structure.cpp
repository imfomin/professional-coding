#include <stdio.h>
#include <string.h>
#include "const.h"
#include "funks_header.h"

struct student {
	int number;
	char fio[40];
	int marks[4];
};

/* удаление пробелов кв конце строки */
char* delSpaceEnd(char* str) {
	int len = strlen(str);
	for (int i = len - 1; str[i] == ' '; i--) str[i] = '\0';
	return str;
}

/* заполнение массива из n студентов */
void scanfStudent(student* destination, int n) {
	char rawInput[STRING_SIZE];
	int j, count;
	
	for (int i = 0; i < n; i++) {
		gets_s(rawInput, STRING_SIZE);

		destination[i].number = i;

		for (j = 0; rawInput[j] < '0' || rawInput[j] >= '9'; j++) {
			destination[i].fio[j] = rawInput[j];
		}
		destination[i].fio[j] = '\0';
		delSpaceEnd(destination[i].fio);

		count = 0;
		while (count < 4) {
			if (rawInput[j] != ' ') {
				destination[i].marks[count++] = rawInput[j] - '0';
			}
			j++;
		}
	}
}

/* возвращает true, если студент получит стипендию,
иначе false */
bool isPaid(student stydent) {
	for (int i = 0; i < 4; i++) {
		if (stydent.marks[i] != 4 && stydent.marks[i] != 5) return false;
	}

	return true;
}

/* по массиву всех n студентов заполняет массив студентов, претендующих на стипендию;
возвращает количество таких студентов */
int findPaidStudents(student* all, student* paid, int n) {
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (isPaid(all[i])) paid[j++] = all[i];
	}

	return j;
}

/*
int main() {
	const int N = 10;

	student* allStudents = new student[N];
	student* paidStudents = new student[N];
	scanfStudent(allStudents, N);

	int number_of_paid_students = findPaidStudents(allStudents, paidStudents, N);

	if (number_of_paid_students) {
		printf("\nStudents that get scholarship:\n");
		for (int i = 0; i < number_of_paid_students; i++) {
			printf("%s with marks:\n", paidStudents[i].fio);
			printIntArr(paidStudents[i].marks, 4);
		}
	}
	else {
		printf("\nno one gets scholarship\n");
	}

	delete[] allStudents;
	delete[] paidStudents;
}
*/