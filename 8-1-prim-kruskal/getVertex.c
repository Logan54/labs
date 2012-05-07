#include <stdio.h>
#include <limits.h>
#include "prim.h"

int getEdges(int ** matrix, int size, const int N, FILE * in) {
	int from = 0, to = 0, weight = 0;
	const int M = size;
	size = 0;
	
	if (0 == M && 1 != N) {
		fprintf(stdout, ERROR_TREE);
		return(-1);
	} else if (0 == M && 1 == N) {
		fprintf(stdout, "");
		return(-1);
	}
	while (size++ < M) {
		if (3 > fscanf(in, "%d%d%d", &from, &to, &weight)) {
			fprintf(stdout, ERROR_NUMB_LINE);
			return(-1);
		} else if ( (MIN_NUMB_VERT + 1 > from || N < from) || (1 > to || N < to) ) {
			fprintf(stdout, ERROR_VERT);
			return(-1);
		} else if ( (0 > weight) || (weight > INT_MAX) ) {
			fprintf(stdout, ERROR_LENG);
			return(-1);
		}
		matrix[from - 1][to - 1] = matrix[to - 1][from - 1] = weight;
	}
	
	return(0);
}
