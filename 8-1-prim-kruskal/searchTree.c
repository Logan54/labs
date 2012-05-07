#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

struct vert {
	unsigned int path;
	unsigned int from;
};

static int getMin(struct vert ** set, int N, int ** matrix, const int i) {
	int j, min = 0;
	
	while (0 == (*set)[min].path && min < N) min++; 
	for (j = 0; j < N; ++j) {
		if (matrix[i][j] > 0 && (*set)[j].path > matrix[i][j]) {
			(*set)[j].path = matrix[i][j];
			(*set)[j].from = i;
		}
		min = ((*set)[j].path > 0 && (*set)[min].path > (*set)[j].path) ? j : min;
	}

	return(min);
}

/*
 * set - array of length to vertex
 */
int searchTree(int ** matrix, int N, FILE * out) {
	struct vert * set;
	int i, min = 0;
	int count_joined = 1;
	
	set = calloc(N, sizeof(struct vert));
	if (NULL == set) {
		fprintf(stderr, ERROR_MEM);
		exit(0); //solution only for student
	}
	for (i = 0; i < N; ++i) {
		set[i].from = i;
		set[i].path = INF;
	}
	i = 0;
	set[i].path = 0;
	set[i].from = 0;
	while (count_joined < N) {
		min = getMin(&set, N, matrix, i);
		if (INF == set[min].path) {
			return(-1);
		}
		set[min].path = 0;
		fprintf(out, "%d %d\n",  set[min].from + 1, min + 1);
		i = min;
		++count_joined;
	}
	for (i = 0; i < N; ++i) {
		if (i == set[i].from && INF == set[i].path) {
			return(-1);
		}
	}
	free(set);
	
	return(0);
}
