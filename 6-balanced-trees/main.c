#include "header.h"

int main (void) {
	long int i, N, tmp_data;
	struct node * node_point, * Thead = NULL;
	
	scanf ("%ld", &N);
	if (N > 0) { 
		for (i = 1; i <= N; i++) {
			scanf ("%ld", &tmp_data);
			insert (&Thead, tmp_data);
		}
		printf ("%ld\n", Thead->height);
	} else {
		printf ("0\n");
	}
	DelTree (Thead);

	return (0);
}