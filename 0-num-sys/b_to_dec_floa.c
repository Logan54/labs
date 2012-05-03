#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funct.h"

#define SIZE_STR 13

double b_to_dec_floa (int b1, char floa[SIZE_STR]) {
	int i;
	double n;
	
	n = 0;
	for (i = (int)strlen(floa); i >= 0; i--) {
		n += floa[i];
		if (isdigit(floa[i])) {
			n -= 48;
		} else if (islower(floa[i])) {
			n -= 87;
		} else if (isupper(floa[i])) {
			n -= 55;
		}
		n /= b1;
	}
	return (n);
}