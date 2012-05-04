#include "header.h"

void DelTree (struct node * Thead) {
	if (Thead != NULL) {
		if (Thead->left != NULL) {
			DelTree(Thead->left);
		}
		if (Thead->right != NULL) {
			DelTree(Thead->right);
		}
	}
	free(Thead);
}