#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "funct.h"

#define SIZE_STR 13

char* dec_to_b_floa (double n, int b2) {
	int i;
	char flo[SIZE_STR + 1];
	double ip;
	char *p;
	
	for (i = 0; i < SIZE_STR; i++) {
		flo[i] = '0';
	}
	flo[0] = '\0';
	for (i = 0; i < SIZE_STR; i++) {
		modf (n * b2, &ip);
		n = n * b2 - ip;
		if ((int)ip < 10) {
			flo[i] = (int)ip + 48;
		} else {
			flo[i] = (int)ip + 55;
		}
	}
	while ((flo[--i] == '0') && (i >= 1)) {
		flo[i] = '\0';
	}
	flo[SIZE_STR] = '\0';
	p = malloc(sizeof(flo));
	if (p == NULL) {
		fprintf (stderr, "Error: Невозможно выделить память\n");
		abort();
	}
	strcpy(p, flo);
	return (p);
}