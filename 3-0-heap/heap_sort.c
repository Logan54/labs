#include "heap_sort.h"

void heap_sort (int *ar, int n) {
	int i;
	int tmp;
	
	for (i = n / 2; i >= 0; i--) {
		sift (ar, i, n);
	}
	for (i = n; i >= 1; i--) {
		tmp = ar[0];
		ar[0] = ar[i];
		ar[i] = tmp;
		sift(ar, 0, i - 1);
	}
}
