#include <string.h>
#include "header.h"

int hash (char sub_str[SIZE_PATTERN]) {
	long int res, i, deg, len;
	
	res = 0;
	deg = 1;
	len = strlen(sub_str) - 1;

	for (i = 0; i <= len; i++){
		res += ((unsigned char)sub_str[i] % 3) * deg;
		deg *= 3;
	}

	return (res);
}