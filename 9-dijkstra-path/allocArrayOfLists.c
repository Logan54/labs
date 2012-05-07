#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

#define ERROR(stream, str) fprintf(stream, str);\
						   return(-1)

/* Allocate memory for array of lists
 */

int allocArrayOfLists(unsigned int *** matrix, int size) {
	int i, j;

	*matrix = calloc(size, sizeof(unsigned int *));
	if (NULL == *matrix) {
		ERROR(stderr, ERROR_MEM);
	}
	for (i = 0; i < size; ++i) {
		(*matrix)[i] = calloc(size, sizeof(unsigned int));
		if (NULL == (*matrix)[i]) {
			ERROR(stderr, ERROR_MEM);
		}
		for (j = 0; j < size; ++j) {
			(*matrix)[i][j] = INF;
		}
	}
	
	return(0);
}
