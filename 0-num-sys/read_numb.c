#include <stdio.h>
#include <ctype.h>
#include "funct.h"

#define SIZE_STR 13

int read_numb (char inter[SIZE_STR], char floa[SIZE_STR]) {
	int i;
	char ch;
	
	i = 0;
	inter[0] = '\0';
	floa[0] = '\0';
	while (((ch = getchar()) != EOF) && (ch != '.') && (i < SIZE_STR)) {
		if (!(isspace(ch))) {
			inter[i++] = ch;
		}
	}
	inter[i] = '\0';
	if (ch == '.') {
		i = 0;
		while ((ch = getchar()) != EOF) {
			if (!(isspace(ch))) {
				floa[i++] = ch;
			}
		}
		floa[i] = '\0';
		return (1);
	}
	return (0);
}