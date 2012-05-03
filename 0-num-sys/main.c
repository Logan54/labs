#include <stdio.h>
#include <stdlib.h>
#include "funct.h"

#define SIZE_STR 13

int main (void) {
	int b1, b2, dot;
	char nter[SIZE_STR], floa[SIZE_STR];
	char *p;
	
	scanf ("%d%d\n", &b1, &b2);
	dot = read_numb (nter, floa);
	if (is_bad_input(b1, b2, nter, floa, dot)) {
		printf("bad input");
	} else {
		p = translate(b1, b2, nter, floa);
		printf("%s\n", p);
		free (p);
	}
		
	return (0);
}