#include "heap_sort.h"

int median (int a, int b, int c, int * aray) {
	if ( ((aray[a] >= aray[b]) && (aray[b] >= aray[c])) || ((aray[c] >= aray[b]) && (aray[b] >= aray[a])) ) {
		return(b);
	} else if ( ((aray[b] >= aray[c]) && (aray[c] >= aray[a])) || ((aray[a] >= aray[c]) && (aray[c] >= aray[b])) ) {
		return (c);
	} else {
		return (a);
	}
}
