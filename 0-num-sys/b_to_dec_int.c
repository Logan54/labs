#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funct.h"

#define SIZE_STR 13

unsigned long long int b_to_dec_int (int b1, char inter[SIZE_STR]) {
	unsigned long long int n, i;
	
	n = inter[0];
	if (isdigit(inter[0])) {
		n -= 48;
	} else if (islower(inter[0])) {
		n -= 87;
	} else if (isupper(inter[0])) {
		n -= 55;
	}
	for (i = 1; i <= (strlen(inter) - 1); i++) {
		n = n * b1 + inter[i];
		if (isdigit(inter[i])) {
			n -= 48;
		} else if (islower(inter[i])) {
			n -= 87;
		} else if (isupper(inter[i])) {
			n -= 55;
		}
	}
	return (n);
}