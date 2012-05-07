#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

/* This program is realization of algorithm of Dijkstra for search
 * the shortest path and printing this path.
 * Struct of data - array of contiguity lists
 */

int main(void) {
	int N = -1, M = -1, S = -1, F = -1;
	FILE * in, * out;
	unsigned int ** matrix;
	
	in = fopen(IN_FILE, "r");
	out = fopen(OUT_FILE, "w");
	if (NULL == in || NULL == out) {
		fprintf(stderr, ERROR_FILE);
		return(0);
	}
	if (readFirstValues(in, &N, &S, &F, &M) || allocArrayOfLists(&matrix, N) || getEdges(matrix, N, M, in)) {
		fclose(in);
		fclose(out);
		return(0);
	}
	searchAndPrint(matrix, N, S, F, out);
	memoryFree(matrix, N);
	fclose(in);
	fclose(out);
	
	return(0);
}
