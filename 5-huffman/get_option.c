#include "huffman.h"

short int get_option (FILE * in) {
	char ch;
	
	fread(&ch, 1, 1, in);
	if ('c' == ch) {
		return(1);
	} else if ('d' == ch) {
		return(0);
	} else {
		return(-1);
	}
}
