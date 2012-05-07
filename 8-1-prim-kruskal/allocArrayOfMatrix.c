#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

#define ERROR(stream, str) fprintf(stream, str);\
						   return(-1)

int allocArrayOfMatrix(int *** matrix, int size) {
	int i;

	*matrix = calloc(size, sizeof(int *));
	if (NULL == *matrix) {
		ERROR(stderr, ERROR_MEM);
	}
	for (i = 0; i < size; ++i) {
		(*matrix)[i] = calloc(size, sizeof(int));
		if (NULL == (*matrix)[i]) {
			ERROR(stderr, ERROR_MEM);
		}
	}
	
	return(0);
}
