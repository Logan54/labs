#include "header.h"

struct node * NewNode (long int value) {
	struct node * tmp_point;
	
	tmp_point = (struct node *) malloc ( sizeof(struct node) );
	if (tmp_point == NULL) {
		fprintf (stderr, "ERROR: out of memory!\n");
		return (NULL);
	}
	tmp_point->data = value;
	tmp_point->left = tmp_point->right = NULL;
	tmp_point->height = 1;
	
	return (tmp_point);
}