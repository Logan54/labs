#include "huffman.h"

int is_RLE (int * alph_val) {
	short int smbs = 0;
	int i;
	short int count_smbs = 0;

	for (i = 0; i < ALPH_SIZE; i++) {
		if (0 != alph_val[i]) {
			smbs = (short int)i;
			count_smbs++;
		}
		if (count_smbs > 1) {
			return(0);
		}
	}

	return(smbs);
}

void RLE (FILE * out, unsigned long int count, short int ch) {
	
	fputc(128, out);
	fwrite(&count, sizeof(unsigned long int), 1, out);
	fputc(ch, out);

	return;
}

void UNRLE (FILE * in, FILE * out) {
	unsigned long int count;
	unsigned char ch;

	fread(&count, sizeof(unsigned long int), 1, in);
	fread(&ch, 1, 1, in);
	for ( ; count > 0; count--) {
		fwrite(&ch, 1, 1, out);
	}

	return;
}