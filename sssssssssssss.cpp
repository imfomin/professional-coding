#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SF(char* fname) {
	char str[80];
	FILE* f;
	if ((f = fopen(fname, "w")) == NULL) {
		printf("error\n");
		return 1;
	}

	gets_s(str, 80);
	int n;
	while (strcmp(str, "***")) {
		n = strlen(str);
		str[n] = '\n'; str[n + 1] = 0;
		fputs(str, f);
		gets_s(str, 80);
	}
	fclose(f);
	
	return 0;
}

int pechatf(char* fname) {
	char str[80];
	FILE* f;
	if ((f = fopen(fname, "r")) == NULL) {
		printf("error\n");
		return 1;
	}

	int n;
	fgets(str, 80, f);
	while (!feof(f)) {
		n = strlen(str);
		str[n - 1] = 0;
		puts(str);
		fgets(str, 80, f);
	}

	fclose(f);
	return 0;
}

int pupupupu() {
	char str[80];
	gets_s(str, 80);

	SF(str);
	pechatf(str);

	return 0;
}