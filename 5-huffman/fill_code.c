#include "huffman.h"

void fill_code(struct node * tree, struct smb * alph, BARR_ELTYPE tmp_code[], unsigned int deep) {
	
	if ( (NULL == tree->right) && (NULL == tree->left) ) { //если мы в листе
		if (deep) {
			alph[(unsigned char)tree->ch].lengthcode = deep;
		} else {
			alph[(unsigned char)tree->ch].lengthcode = 1;
		}
		memcpy(alph[(unsigned char)tree->ch].code, tmp_code, MAX_BITS);
	} else {
		if (NULL != tree->left) {
			BARR_SET(tmp_code, deep);
			fill_code(tree->left, alph, tmp_code, deep + 1);
		}
		if (NULL != tree->right) {
			BARR_CLEAR(tmp_code, deep);
			fill_code(tree->right, alph, tmp_code, deep + 1);
		}
	}
	
	return;
}
