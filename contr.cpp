#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

const int TEXT_SIZE = 2048;
const int STRING_SIZE = 256;
const int WORD_SIZE = 64;

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
char** getwords(int n) {
	char** words = new char* [n];
	for (int i = 0; i < n; i++) {
		words[i] = new char[WORD_SIZE];
		gets_s(words[i], WORD_SIZE);
	}

	return words;
}
int windex(char* word, char** pack, int n) {
	for (int i = 0; i < n; i++) {
		if (!strcmp(word, pack[i])) return i;
	}

	return -1;
}
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


int main() {
	char* text = readFile("1.txt");
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