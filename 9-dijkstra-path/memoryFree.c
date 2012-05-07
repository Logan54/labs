#include <stdlib.h>
#include "dijkstra.h"

void memoryFree(unsigned int ** matrix, int N) {
	int i;

	for (i = 0; i < N; ++i) {
		free(matrix[i]);
	}
	free(matrix);
}
