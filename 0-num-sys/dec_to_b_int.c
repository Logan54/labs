#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funct.h"

#define SIZE_STR 13

char* dec_to_b_int (unsigned long long int n, int b2) {
	int i;
	char intr[4 * SIZE_STR + 5];
	char *p;
	
	for (i = 0; n; i++) {
		if ((n % b2) < 10) {
			intr[i] = n % b2 + 48;
		} else {
			intr[i] = n % b2 + 55;
		}
		n /= b2;
	}
	if (i) intr[i] = '\0';
	else {
		intr[i++] = '0';
		intr[i] = '\0';
		i = 0;
	}
	for (i-- ; ((i+1) / 2) && (i != (strlen(intr) - i - 1)); i--) {
		intr[strlen(intr) - i - 1] += intr[i];
		intr[i] = intr[strlen(intr) - i - 1] - intr[i];
		intr[strlen(intr) - i - 1] = intr[strlen(intr) - i - 1] - intr[i];
	}
	p = malloc(sizeof(intr));
	if (p == NULL) {
		fprintf (stderr, "Error: Невозможно выделить память\n");
		abort();
	}
	strcpy(p, intr);
	return (p);
}