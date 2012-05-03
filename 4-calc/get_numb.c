#include "calc.h"
#include <ctype.h>

int get_numb(char in_str[IN_STR_SIZE], int * index) {
	int res = 0;
	
	while ( isdigit(in_str[*index]) ) {
		res = res * 10 + in_str[*index] - '0';
		++(*index);
	}
	
	return(res);
}
