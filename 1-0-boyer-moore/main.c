#include <stdio.h>
#include <string.h>
#include "boyer_moor.h"

int main (void) {
	unsigned int d[SIZE_ALPH];
    unsigned char pattern[SIZE_PATTERN];
    unsigned char tmp[SIZE_TMP];
    unsigned int lenpat;
	unsigned int i = 0;
	unsigned char ch;
    
	while ((ch = (unsigned char)getc(stdin)) != '\n') {
		pattern[i++] = ch;
	}
	pattern[i] = '\0';
	lenpat = (unsigned int)strlen(pattern) - 1;
    for (i = 1; i < SIZE_ALPH; i++) {
		d[i] = lenpat + 1;
    }
    for (i = 0; i < lenpat; i++) {
        d[pattern[i]] = lenpat - i;
    }
    seek_substring_BM (tmp, pattern, d);
        
    return (0);
}