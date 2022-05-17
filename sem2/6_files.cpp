#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "const.h"

/* создание файла + запись строк в файл;
признак конца записи - "***" */
int createFile(char* fname) {
	char str[STRING_SIZE];
	FILE* f;
	if ((f = fopen(fname, "w")) == NULL) {
		printf("error\n");
		return 1;
	}

	gets_s(str, STRING_SIZE);
	int n;
	while (strcmp(str, "***")) {
		n = strlen(str);
		str[n] = '\n'; str[n + 1] = 0;
		fputs(str, f);
		gets_s(str, STRING_SIZE);
	}
	fclose(f);

	return 0;
}

/* печать файла */
int printFile(char* fname) {
	char str[STRING_SIZE];
	FILE* f;
	if ((f = fopen(fname, "r")) == NULL) {
		printf("error\n");
		return 1;
	}

	int n;
	fgets(str, STRING_SIZE, f);
	while (!feof(f)) {
		n = strlen(str);
		str[n - 1] = 0;
		puts(str);
		fgets(str, STRING_SIZE, f);
	}

	fclose(f);
	return 0;
}

/* чтение файла;
возвращает строку, содержащую текст файла с заменой \n на пробел */
char* readFile(const char* fname) {
	char* text = new char[TEXT_SIZE];
	*text = 0;
	char* str = new char[STRING_SIZE];
	FILE* f;

	if ((f = fopen(fname, "r")) == NULL) {
		printf("error\n");
		return text;
	}

	while (!feof(f)) {
		str = fgets(str, STRING_SIZE, f);
		str[strlen(str) - 1] = ' '; str[strlen(str)] = 0;
		text = strcat(text, str);
	}

	fclose(f);
	delete[] str;

	return text;
}

/* ввод с клавиатуры n слов;
возвращает массив из этих слов */
char** getwords(int n) {
	char** words = new char* [n];
	for (int i = 0; i < n; i++) {
		words[i] = new char[WORD_SIZE];
		gets_s(words[i], WORD_SIZE);
	}

	return words;
}

/* поиск слова в массиве pack;
возвращает адрес первого вхождения или -1, если такого слова нет */
int windex(char* word, char** pack, int n) {
	for (int i = 0; i < n; i++) {
		if (!strcmp(word, pack[i])) return i;
	}

	return -1;
}

/* возвращает true, если предложение содержит не меньше половины слов из words,
false иначе */
bool chsent(char* sentence, char** words, int n) {
	char* word = new char[WORD_SIZE];
	int k = 0, ind, i;

	int* help = new int[n];
	for (i = 0; i < n; i++) {
		help[i] = 0;
	}

	for (i = 0; sentence[i]; i++) {

		if (sentence[i] != ' ') {
			word[k++] = sentence[i];
		}
		else if (k > 0) {
			word[k] = 0;
			ind = windex(word, words, n);
			if (ind >= 0) {
				help[ind]++;
			}
			k = 0;
		}
	}

	int cnt = 0;
	for (i = 0; i < n; i++) {
		if (help[i]) cnt++;
	}

	int hn;
	if (n % 2) hn = n / 2 + 1;
	else hn = n / 2;

	delete[] word;
	delete[] help;

	return cnt >= hn;
}

/* из строки text печатаются только те предложения, где не меньше половины слов из words */
void chtext(char* text, char** words, int n) {
	char* sent = new char[STRING_SIZE];
	int k = 0, i;

	for (i = 0; text[i]; i++) {
		if (text[i] != '.' && text[i] != '!' && text[i] != '?') {
			sent[k++] = text[i];
		}
		else if (k > 0) {
			sent[k] = 0; sent = strcat(sent, "  \0");
			if (chsent(sent, words, n)) puts(sent);
			k = 0;
		}
	}

	delete[] sent;
}

/*task 1
int main() {
	char str[STRING_SIZE];
	gets_s(str, STRING_SIZE); // 6_test.txt

	createFile(str);
	printFile(str);

	return 0;
}
*/

/*task 2 (индивидуальное)
int main() {
	char* text = readFile("6_individ.txt");
	puts(text);

	int n; scanf_s("%d", &n);
	char t; scanf_s("%c", &t);
	char** words = getwords(n);

	chtext(text, words, n);

	delete[] text;
	for (int i = 0; i < n; i++) {
		delete[] words[i];
	}
	delete[] words;

	return 0;
}
*/