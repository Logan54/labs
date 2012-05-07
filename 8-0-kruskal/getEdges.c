#include <stdio.h>
#include <limits.h>
#include "kruskal.h"

int getEdges(struct edge * edges, int size, const int N, FILE * in) {
	int from = 0, to = 0, weight = 0;
	int res = -1;
	const int M = size;
	size = 0;
	
	if (0 == M && 1 != N) {
		fprintf(stdout, ERROR_TREE);
		return(-1);
	} else if (0 == M && 1 == N) {
		fprintf(stdout, "");
		return(-1);
	}
	while (size < M) {
		res = fscanf(in, "%d%d%d", &from, &to, &weight);
		if (3 > res) {
			fprintf(stdout, ERROR_NUMB_LINE);
			return(-1);
		} else if ( (MIN_NUMB_VERT + 1 > from || N < from) || (1 > to || N < to) ) {
			fprintf(stdout, ERROR_VERT);
			return(-1);
		} else if ( (0 > weight) || (weight > INT_MAX) ) {
			fprintf(stdout, ERROR_LENG);
			return(-1);
		}
		edges[size].from = from;
		edges[size].to = to;
		edges[size].weight = weight;
		++size;
	}
	
	return(0);
}
