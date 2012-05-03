#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

#define ERROR(str) fprintf(out, str);\
			while (!empty(&numbers)) pop(&numbers);\
			while (!empty(&oper)) pop(&oper);\
			fclose(in);\
			fclose(out);\
			return(0)

int main (void) {
	FILE * in, * out;
	struct stack * numbers = NULL, * oper = NULL;
	unsigned char in_str[IN_STR_SIZE];
	unsigned int tmp_oper;
	int numb, first, second, index = 0;

	in = fopen(FILE_NAME_RD, "r");
	out = fopen(FILE_NAME_WR, "w");
	fgets(in_str, IN_STR_SIZE + 1, in);
	while ((10 != in_str[index]) && (13 != in_str[index])) {
		if ((10 != in_str[index + 1]) && (13 != in_str[index + 1]) && is_err(in_str[index], in_str[index + 1])) {
			ERROR("syntax error");
		}
		if (isdigit(in_str[index])) { //numbers
			numb = get_numb(in_str, &index);
			push(&numbers, numb);
			continue;
		}
		if (sorter(in_str[index++], &numbers, &oper)) {
			ERROR("syntax error");
		}
	}
	while ( 0 < (int)(tmp_oper = pop(&oper)) ) {
		if ((empty(&numbers)) || (empty( &((numbers)->next) ))) {
			ERROR("syntax error");
		}
		second = pop(&numbers);
		first = pop(&numbers);
		if (compute(tmp_oper, first, second, &numbers)) {
			ERROR("division by zero\n");
		}
	}
	if (!empty(&numbers)) {
		fprintf(out, "%d", pop(&numbers));
	} else {
		ERROR("syntax error");
	}
	fclose(in);
	fclose(out);

	return(0);
}
