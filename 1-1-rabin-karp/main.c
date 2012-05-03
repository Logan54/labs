#include <stdio.h>
#include <string.h>

#include "header.h"

int main (void) {
    struct pattern PAT;
        
    fgets (PAT.value, SIZE_PATTERN + 1, stdin);
    PAT.value[strlen(PAT.value) - 1] = '\0';
	PAT.length = strlen(PAT.value);
	PAT.hashpat = hash (PAT.value);
	printf ("%d ", PAT.hashpat);
    seek_substring_RK (&PAT);

    return (0);
}