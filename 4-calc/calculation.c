#include "calc.h"
#include <stdlib.h>
#include <stdio.h>

void calculation (struct stack ** oper, struct stack ** numbers, unsigned int prior) {
	unsigned int ch;
	int first, second;
	int cond = (4 > prior);
	
	while ( (((int)prior <= priority(top(oper))) && (!empty(oper)) && cond) || ( (!empty(oper)) && (!cond) ) ) {
		ch = pop(oper);
		if ( ('(' == ch && !empty(numbers)) && (!cond) ) {
			return;
		}
		if ( empty(numbers) || empty(&((*numbers)->next)) ) {
			printf("syntax error");
			exit(0);
		}
		second = pop(numbers);
		first = pop(numbers);
		if (compute(ch, first, second, numbers)) {
			printf("division by zero\n");
			exit(0);//only student solution
		}
	}

	return;
}

