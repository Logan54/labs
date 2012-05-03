#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funct.h"

#define SIZE_STR 13

int is_bad_input (int b1, int b2, char inter[SIZE_STR], char floa[SIZE_STR], int dot) {
	unsigned int i;
	
	if (!((b1 > 1) && (b1 < 17) && (b2 > 1) && (b2 < 17))) {
		return (1);
	}
	if ((dot) && (!((strlen(inter)) && (strlen(floa))))) {
		return (1);
	}
	for (i = 0; i < strlen(inter); i++) {
		if (!(((isdigit(inter[i])) && ((inter[i] - 48) < b1)) || ((isupper(inter[i])) && ((inter[i] - 55) < b1)) ||
		 ((islower(inter[i])) && ((inter[i] - 87) < b1)))) {
			return (1);
		}
	}
	for (i = 0; i < strlen(floa); i++) {
		if (!(((isdigit(floa[i])) && ((floa[i] - 48) < b1)) || ((isupper(floa[i])) && ((floa[i] - 55) < b1)) || ((islower(floa[i])) && ((floa[i] - 87) < b1)))) {
			return (1);
		}
	}
	return (0);
}