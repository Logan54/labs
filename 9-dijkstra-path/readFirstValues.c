#include <stdio.h>
#include "dijkstra.h"

/* N - number of vertices
 * S - number of first vertex of printing path
 * F - number of last vertex of printing path
 * M - number of edges
 */

int readFirstValues(FILE * in, int * N, int * S, int * F, int * M) {
	int res = 0;
	
	res = fscanf(in, "%d%d%d%d", N, S, F, M);
	if (res < 4) {
		fprintf(stdout, ERROR_NUMB_LINE);
		fprintf(stdout, "BAX");
		return(-1);
	} else if (!(MIN_NUMB_VERT <= *N && *N <= MAX_NUMB_VERT)) {
		fprintf(stdout, ERROR_NUMB_VERT);
		return(-1);
	} else if (*S < MIN_NUMB_VERT + 1 || *S > *N || *F > *N || *F < MIN_NUMB_VERT) {
		fprintf(stdout, ERROR_VERT);
		return(-1);
	} else if (!(MIN_NUMB_EDGE <= *M && *M <= (*N)*(*N + 1)/2)) {
		fprintf(stdout, ERROR_NUMB_EDGE);
		return(-1);
	}
	
	return(0);
}
