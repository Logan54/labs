#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"

int main (void) {
	int N, i;
	int * aray;
	int flag = 1;
	
	scanf ("%d", &N);
	aray = (int *)malloc (N * sizeof(int));
	if (NULL == aray) {
		printf ("Error: Can't read memory!\n");
		abort();
	}
	for (i = 0; i < N; i++) {
		scanf ("%d", &aray[i]);
		if ( (flag) && (i) && (aray[i] != aray[i - 1]) ) {
			flag = 0;
		}
	}
	if (!(flag)) {
		quick_sort (aray, 0, N - 1);
	}
	for (i = 0; i < N; i++) {
		printf ("%d ", aray[i]);
	}
	free (aray);

	return (0);
}

