#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void reverse(char* str) {
	int len = strlen(str);
	int hlen = len / 2;
	char temp;
	for (int i = 0; i < hlen; i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

char* transformation(char* txt) {
	int len = strlen(txt);
	char* mod_txt = new char[len];
	char* slovo = new char[len];
	char* start = slovo;

	*mod_txt = 0;
	txt = strcat(txt, " ");
	while (*txt) {
		if (*txt == ' ') {
			*slovo = 0;
			slovo = start;
			int slovolen = strlen(slovo);
			if (slovolen % 2) {
				reverse(slovo);
				slovo = strcat(slovo, " ");
				mod_txt = strcat(mod_txt, slovo);
			}

			txt++; 
		}
		else {
			*slovo++ = *txt++;
		}
	}

	return mod_txt;
}

int main() {
	int n; scanf_s("%d", &n);
	char* text = new char[n];
	
	char t;
	scanf_s("%c", 1, &t);

	gets_s(text, n);

	char* new_text = transformation(text);

	puts(new_text);

	delete[] text;
	delete[] new_text;

	return 0;

}

