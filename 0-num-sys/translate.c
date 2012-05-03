#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funct.h"

#define SIZE_STR 13

char * translate (int b1, int b2, char inte[SIZE_STR], char floa[SIZE_STR]) {
	char str[5 * SIZE_STR + 2];
	char *p, *p1, *p2;
	
	p1 = dec_to_b_int(b_to_dec_int(b1, inte), b2);
	if (strlen(floa) > 0) {
		p2 = dec_to_b_floa(b_to_dec_floa(b1, floa), b2);
		
		sprintf (str, "%s.%s", p1, p2);
		free (p2);
	} else {
		sprintf (str, "%s", p1);
	}
	free (p1);
	p = malloc(sizeof(str));
	if (p == NULL) {
		fprintf (stderr, "Error: Невозможно выделить память\n");
		abort();
	}
	strcpy(p, str);
	return (p);
}
