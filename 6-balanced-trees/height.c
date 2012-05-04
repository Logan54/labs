#include "header.h"

long int height (struct node * node_point) {
	if (node_point == NULL) {
		return (0);
	} else {
		return (node_point->height);
	}
}