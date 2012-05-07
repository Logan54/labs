#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

int main(void) {
	int N = -1, M = -1;
	FILE * in, * out;
	int ** matrix;
	
	in = fopen(IN_FILE, "r");
	out = fopen(OUT_FILE, "w");
	if (NULL == in || NULL == out) {
		fprintf(stderr, ERROR_FILE);
		return(0);
	}
	if (readFirstValues(in, &N, &M) || allocArrayOfMatrix(&matrix, N) || getEdges(matrix, M, N, in)) {
		fclose(in);
		fclose(out);
		return(0);
	}
	if ((M < (N - 1)) || searchTree(matrix, N, out)) {
		fprintf(stdout, ERROR_TREE);
	}
	memoryFree(matrix, N);
	fclose(in);
	fclose(out);
	
	return(0);
}
