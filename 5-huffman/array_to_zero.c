#include "huffman.h"

int array_to_zero (struct smb * alph) {
	int i;

	for (i = 0; i < ALPH_SIZE; i++) {
		alph[i].lengthcode = 0;
	}

	return(0);
}