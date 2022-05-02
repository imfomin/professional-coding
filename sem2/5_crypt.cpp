#include <stdio.h>
#include <string.h>
#include "funks_header.h"
#include "const.h"

char* strcrt52(char* str) {
	char* pstr = str;
	int len = strlen(str);
	int move = len % 26;

	while (*str) {
		if (*str >= 'a' && *str <= 'z') {

			if (*str + move <= 'z') *str = *str + move;
			else *str = 'a' - 1 + *str + move - 'z';

		}
		else if (*str >= 'A' && *str <= 'Z') {

			if (*str + move <= 'Z') *str = *str + move;
			else *str = 'A' - 1 + *str + move - 'Z';

		}
		
		str++;
	}

	return pstr;
}

bool iseng(char chr) {
	return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z');
}

char* f52(char* text) {
	char word[WORD_SIZE];
	int j = 0;
	strcat_s(text, TEXT_SIZE, " ");

	for (int i = 0; text[i]; i++) {
		if (iseng(text[i])) {
			word[j++] = text[i];
		}
		else if (j > 0) {
			word[j] = 0;
			strcrt52(word);
			strrpl(text, word, i - j);

			j = 0;
		}
	}

	// text[strlen(text) - 1] = '\0';

	return text;
}

/*
int main() {
	char text[TEXT_SIZE];
	gets_s(text, TEXT_SIZE);

	f52(text);
	puts(text);

	return 0;
}
*/