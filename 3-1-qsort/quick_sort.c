#include "quick_sort.h"
#include <stdio.h>

void quick_sort (int * aray, int l, int r) {
	int i = l, j = r;
	int med = median (l, r, (l + r) / 2, aray);
	int tmp;
	for ( ; i <= j; ) {
		for ( ; (i < med) && (aray[i] <= aray[med]); i++) ;
		for ( ; (j > med) && (aray[j] >= aray[med]); j--) ;
		if (i <= j) {
			tmp = aray[i];
			aray[i++] = aray[j];
			aray[j--] = tmp;
		}
	}
	if (l < j) {
		quick_sort(aray, l, j);
	}
	if (i < r) {
		quick_sort(aray, i - 1, r);
	}
}
