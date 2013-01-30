#include "huffman.h"

unsigned int write_tree(FILE * out, struct node * tree, BARR_ELTYPE * buf) {
	static unsigned int count = 0;
	unsigned char val;
	char i;
	
	count %= BARR_ELBITS;
	if ( (NULL != tree->left) && (NULL != tree->right) ) {
		set_bit(buf, 1, (count++) % BARR_ELBITS, out);
		write_tree(out, tree->left, buf);
		write_tree(out, tree->right, buf);
	} else if (NULL != tree->left) {
		set_bit(buf, 1, (count++) % BARR_ELBITS, out);
		write_tree(out, tree->left, buf);
	} else if (NULL != tree->right) {
		write_tree(out, tree->right, buf);
	} else {
		set_bit(buf, 0, (count++) % BARR_ELBITS, out);
		for (i = 7; i >= 0 ; i--) {
			val = BARR_TEST(&(tree->ch), i) ? 1 : 0;
			set_bit(buf, val, (count++) % BARR_ELBITS, out);
		}
	}
	
	return(count);
}
