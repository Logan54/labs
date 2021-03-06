#include "huffman.h"

void clear_buf(BARR_ELTYPE * buf) {
	BARR_CLEARARRAY(buf, BARR_ELBITS);
	
	return;
}

void set_bit(BARR_ELTYPE * buf, char val, unsigned char count, FILE * out) {
	count %= BARR_ELBITS;
	count = BARR_ELBITS - 1 - count;
	if (val) {
		BARR_SET(buf, count);
	} else {
		BARR_CLEAR(buf, count);
	}
	if (0 == count) {
		fwrite(buf, BARR_ELBITS / CHAR_BIT, 1, out);
	}
	
	return;
}

unsigned char get_bit(BARR_ELTYPE * buf, unsigned char count, FILE * in) {
	unsigned char result = '\0';
	
	count %= BARR_ELBITS;
	count = BARR_ELBITS - 1 - count;
	if ( BARR_TEST(buf, count) ) {
		result = 1;
	} else {
		result = '\0';
	}
	if (0 == count) {
		fread(buf, BARR_ELBITS / CHAR_BIT, 1, in);
	}
	
	return(result);
}

char get_byte(BARR_ELTYPE * buf, char count, FILE * in) {
	BARR_ELTYPE * ch;
	char i;
	
	count %= BARR_ELBITS;
	ch = BARR_MALLOC(CHAR_BIT);
	check_pointer(ch);
	for (i = CHAR_BIT - 1; i >= 0; i--) {
		if (get_bit(buf, count, in)) {
			BARR_SET(ch, i);
		} else {
			BARR_CLEAR(ch, i);
		}
		count++;
	}
	
	return(*ch);
}

void fill_buf(BARR_ELTYPE * buf, FILE * in) {
	
	fread(buf, BARR_ELBITS / CHAR_BIT, 1, in);
	
	return;
}
