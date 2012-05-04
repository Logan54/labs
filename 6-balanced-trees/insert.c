#include "header.h"

void insert (struct node ** Thead, long int tmp_data) {	
	if ((*Thead) == NULL) {
		(*Thead) = NewNode(tmp_data);
		return;
	}
	if (tmp_data > (*Thead)->data) {
		insert ( &((*Thead)->right), tmp_data);
		if ( (((*Thead)->right != NULL) || ((*Thead)->left != NULL)) && (abs(height((*Thead)->right) - height((*Thead)->left)) > 1) ) {
			if (tmp_data > (*Thead)->right->data) {
				(*Thead) = RotateR ( (*Thead) );
			} else {
				(*Thead) = RotateRR ( (*Thead) );
			}
		}
	} else if (tmp_data <= (*Thead)->data) {
		insert ( &((*Thead)->left), tmp_data);
		if ( ( ((*Thead)->right != NULL) || ((*Thead)->left != NULL) ) &&  (abs(height((*Thead)->left) - height((*Thead)->right)) > 1) ) {
			if (tmp_data <= (*Thead)->left->data) {
				(*Thead) = RotateL ( (*Thead) );
			} else {
				(*Thead) = RotateLL ( (*Thead) );
			}
		}
	}
	(*Thead)->height = max (height((*Thead)->left), height((*Thead)->right)) + 1;
}