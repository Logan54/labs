#include <stdlib.h>
#include "huffman.h"

int main (void) {
	short int option; //compression or decompression
	FILE * in;
	FILE * out;
	struct smb * alph;
	BARR_ELTYPE tmp_code[MAX_BITS] = {0, };

	alph = (struct smb *) malloc(sizeof(struct smb) * ALPH_SIZE);
	//fprintf(stderr, "MALLOC main: alph\n");
	check_pointer(alph);
	array_to_zero(alph);
	in = fopen(FILE_NAME_RD, "rb");
	out = fopen(FILE_NAME_WR, "wb");
	option = get_option(in);
	if (is_empty_file(in)) {
		free(alph);
		//fprintf(stderr, "FREE main: alph\n");
		fclose(in);
		fclose(out);
		return(0);
	}
	if (option == -1) {
		fprintf(stderr, "Error: invalid option\n");
		free(alph);
		//fprintf(stderr, "FREE main: alph\n");
		return(-1);
	}
	if (option == 1) { //compression
		struct node * tree = NULL;
		unsigned long int * alph_val;
		short int smbs = 0;
		
		tree = malloc( sizeof(struct node) );
		//fprintf(stderr, "MALLOC main: tree\n");
		check_pointer(tree);
		alph_val = get_probtree(&tree, in);
		if (smbs = is_RLE(alph_val)) {
			RLE(out, alph_val[smbs], smbs);
			free(alph);
			//fprintf(stderr, "FREE main: alph\n");
			free(alph_val);
			//fprintf(stderr, "FREE main: alph_val\n");
			fclose(in);
			fclose(out);
			return(0);
		}
		fill_code(tree, alph, tmp_code, 0);
		free(alph_val);
		//fprintf(stderr, "FREE main: alph_val\n");
		fill_file(in, out, alph, tree);
		remove_tree(tree);
	} else { //decompression
		char size_lost_byte = '\0';

		fseek(in, WIN_NEW_LINE + 1, SEEK_SET);
		size_lost_byte = get_size_from_file(in);
		if (7 < abs(size_lost_byte)) {
			UNRLE(in, out);
			free(alph);
			//fprintf(stderr, "FREE main: alph\n");
			fclose(in);
			fclose(out);
			return(0);
		}
		decompres(in, out, size_lost_byte);
	}
	free(alph);
	//fprintf(stderr, "FREE main: alph\n");
	fclose(in);
	fclose(out);
	
	return(0);
}
