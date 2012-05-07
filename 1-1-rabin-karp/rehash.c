#include "header.h"
#include <stdio.h>

int rehash (int old_hash, char old_ch, char new_ch, int lenpat) {
	int i, deg, new_hash;
	
	deg = 1;
	for (i = 1; i <= lenpat - 1; i++) deg *= 3;
	new_hash = ((old_hash - 3*(unsigned int)old_ch%3) / 3) + ((unsigned int)new_ch%3) * deg;

	return (new_hash);
}
