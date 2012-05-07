#include <stdlib.h>
#include "prim.h"

void memoryFree(int ** matrix, int N) {
	int i;

	for (i = 0; i < N; ++i) {
		free(matrix[i]);
	}
	free(matrix);
}