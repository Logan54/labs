#include "huffman.h"

int is_empty_file (FILE * in) {
	int res = 0;
	
	fseek(in, WIN_NEW_LINE + 1, SEEK_SET);
	fgetc(in);
	if (feof(in)) {
		res = 1;
	}

	return(res);
}