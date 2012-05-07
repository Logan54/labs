#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

int allocArrayOfEdges(struct edge ** edges, int size) {
	
	*edges = calloc(size, sizeof(struct edge));
	if (NULL == *edges) {
		fprintf(stderr, ERROR_MEM);
		return(-1);
	}
	
	return(0);
}
