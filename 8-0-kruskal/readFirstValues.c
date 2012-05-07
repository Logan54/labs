#include <stdio.h>
#include "kruskal.h"

int readFirstValues(FILE * in, int * N, int * M) {
	int res = 0;
	
	res = fscanf(in, "%d%d", N, M);
	if (res < 2) {
		fprintf(stdout, ERROR_NUMB_LINE);
		return(-1);
	} else if (!(MIN_NUMB_VERT <= *N && *N <= MAX_NUMB_VERT)) {
		fprintf(stdout, ERROR_NUMB_VERT);
		return(-1);
	} else if (!(MIN_NUMB_EDGE <= *M && *M <= (*N)*(*N + 1)/2)) {
		fprintf(stdout, ERROR_NUMB_EDGE);
		return(-1);
	}
	
	return(0);
}
