#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

/*
 * This function return number of elemnt of array minimal weight
 */
static int getMin(const unsigned int * set, const char * color, int N) {
	int j, min = -1;
	unsigned int weight = INF;
	
	for (j = 0; j < N; ++j) {
		if ( 0 == color[j] && (weight > set[j] || INF + 1 == set[j]) ) {
			weight = set[j];
			min = j;
		}
	}

	return(min);
}

static void relaxation(unsigned int ** set, const unsigned int * matrix, int min, int * path, int N) {
	int i;
	
	for (i = 0; i < N; ++i) {
		if ( INF != matrix[i] && (matrix[i] + (*set)[min] < (*set)[i] || (INF == (*set)[i] && INF != (*set)[min])) ) {
			(*set)[i] = matrix[i] + (*set)[min];
			path[i] = min;
		}
	}

	return;
}

static int checkPath(FILE * out, const int * path, int F, int S) {
	if (S == F) {
		fprintf(out, "%i %i", S, S);
		return(-1);
	} else if (-1 == path[F - 1]) {
		fprintf(out, NO_PATH);
		return(-1);
	}

	return(0);
}

static void getTwoMin(unsigned int * min1, unsigned int * min2, int * index1, int * index2, const unsigned int * matrix, int N, int prev) {
	int j;
	
	for (j = 0; j < N; ++j) {
		if (j == prev) {
			continue;
		}
		if (matrix[j] < *min1) {
			*min1 = matrix[j];
			*index1 = j;
		} else if (matrix[j] < *min2) {
			*min2 = matrix[j];
			*index2 = j;
		}
	}
}

static int checkOverflow(FILE * out, const unsigned int ** matrix, int S, int F, int N, unsigned int weight) {
	int i = F - 1, prev = F - 1, index1 = 0, index2 = 0;

	while (S - 1 != i) {
		unsigned int min1 = INF, min2 = INF;
		getTwoMin(&min1, &min2, &index1, &index2, matrix[i], N, prev);
		if (min1 == min2 && weight - min1 >= INT_MAX) {
			fprintf(out, OVERFLOW);
			return(-1);
		}
		prev = i;
		i = index1;
		weight -= min1;
	}

	return(0);
}

static void printPath(const int * path, FILE * out, const unsigned int ** matrix, int F, int S, int N, unsigned int weight) {
	int i = F - 1;
	
	if ( checkPath(out, path, F, S) || checkOverflow(out, matrix, S, F, N, weight) ) {
		return;
	}
	i = F - 1;
	while (-1 != path[i]) {
		fprintf(out, "%d ", i + 1);
		i = path[i];
	}
	fprintf(out, "%d", S);
}

static void printDistance(FILE * out, unsigned int * set, int N) {
	int i;

	for (i = 0; i < N; ++i) {
		if (INT_MAX >= set[i]) {
			fprintf(out, "%u ", set[i]);
		} else if (INF == set[i]) {
			fprintf(out, "oo ");
		} else if (INT_MAX < set[i]) {
			fprintf(out, "INT_MAX+ ");
		}
	}
	fprintf(out, "\n");
}

static int initArrays(unsigned int ** set, int ** path, char ** color, int N) {
	int i;

	*set = calloc(N, sizeof(unsigned int));
	*color = calloc(N, sizeof(char));
	*path = calloc(N, sizeof(int));
	if (NULL == *set || NULL == *color || NULL == *path) {
		fprintf(stderr, ERROR_MEM);
		free(*set);
		free(*color);
		free(*path);
		return(-1);
	}
	for (i = 0; i < N; ++i) {
		(*set)[i]= INF;
		(*path)[i] = -1;
	}

	return(0);
}

/*
 * set - array of length to vertex
 * color - joined vertexes
 * min - current vertex
 */
int searchAndPrint(const unsigned int ** matrix, int N, int S, int F, FILE * out) {
	unsigned int * set;
	int * path; //array of ancestor
	char * color;
	int min, count_joined = 1;
	
	if ( initArrays(&set, &path, &color, N) ) {
		return(-1);
	}
	set[S - 1] = 0;
	while (count_joined <= N) {
		if ( -1 == (min = getMin(set, color, N)) ) {
			break;
		}
		color[min] = 1;
		++count_joined;
		relaxation(&set, matrix[min], min, path, N);
	}
	printDistance(out, set, N);
	printPath(path, out, matrix, F, S, N, set[F - 1]);
	free(set);
	free(color);
	free(path);
	
	return(0);
}
