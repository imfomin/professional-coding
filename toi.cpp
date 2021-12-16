#include <stdio.h>

int mod(int x, int y) {
	if (x < y) {
		return x;
	}
	else {
		return mod(x - y, y);
	}
}

int sumdels(int x, int d) {
	if (d <= x) {
		if (mod(x, d) == 0) {
			return sumdels(x, d + d) + d;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}