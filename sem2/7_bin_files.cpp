#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct abonent {
	char phone_number[12];
	char fio[50];
	char address[50];
};

struct request {
	char phone_number[12];
	int minutes;
	int town_code;
	float minute_cost;
};

struct check {
	char fio[50];
	char phone_number[12];
	char address[50];
	float pay;
};

/*
int main() {
	FILE* abonents_data;
	fopen_s(&abonents_data, "7_abonents_data.bin", "rb");
	FILE* requests_data;
	fopen_s(&requests_data, "7_requests_data.bin", "rb");
	FILE* checks_data;
	fopen_s(&checks_data, "7_checks_data.bin", "wb");

	if (!abonents_data || !requests_data || !checks_data) {
		printf("something went wrong...\n");
		return 1;
	}

	int number_of_abonents;
	fread(&number_of_abonents, 4, 1, abonents_data);
	abonent* abonents = new abonent[number_of_abonents];
	fread(abonents, sizeof(abonent), number_of_abonents, abonents_data);

	request req;
	check chck;

	while (!feof(requests_data)) {
		fread(&req, sizeof(request), 1, requests_data);
		strcpy(chck.phone_number, req.phone_number);
		chck.pay = req.minutes * req.minute_cost;

		chck.fio[0] = '\0'; chck.address[0] = '\0';
		for (int i = 0; i < number_of_abonents; i++) {
			if (!strcmp(req.phone_number, abonents[i].phone_number)) {
				strcpy(chck.fio, abonents[i].fio);
				strcpy(chck.address, abonents[i].address);
			}
		}

		fwrite(&chck, sizeof(check), 1, checks_data);
	}

	delete[] abonents;
	fclose(requests_data);
	fclose(abonents_data);
	fclose(checks_data);
}
*/