#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

int main(void) {
	int N = -1, M = -1;
	FILE * in, * out;
	struct edge * edges;
	
	in = fopen(IN_FILE, "r");
	out = fopen(OUT_FILE, "w");
	if (NULL == in || NULL == out) {
		fprintf(stderr, ERROR_FILE);
		return(0);
	}
	if (readFirstValues(in, &N, &M) || allocArrayOfEdges(&edges, M) || getEdges(edges, M, N, in)) {
		fclose(in);
		fclose(out);
		return(0);
	}
	if ((M < (N - 1)) || searchTree(&edges, M, N, out)) {
		fprintf(stdout, ERROR_TREE);
	}
	free(edges);
	fclose(in);
	fclose(out);
	
	return(0);
}
