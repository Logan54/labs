#include "huffman.h"

unsigned char get_size_from_file(FILE * in) {
	unsigned char result = '\0';
	
	fread(&result, 1, 1, in);
	
	return(result);	
}
