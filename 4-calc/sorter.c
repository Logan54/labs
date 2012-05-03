#include "calc.h"
#include <ctype.h>

int sorter(unsigned char ch, struct stack ** numbers, struct stack ** oper) {
	if (43 == ch) { //plus
		if (2 > priority(top(oper))) {
			push(oper, 43);
		} else {
			calculation(oper, numbers, priority(top(oper)));
			push(oper, 43);
		}
	} else if (45 == ch) { //minus
		if (2 > priority(top(oper))) {
			push(oper, 45);
		} else {
			calculation(oper, numbers, priority(top(oper)));
			push(oper, 45);
		}
	} else if (47 == ch) { //division
		calculation(oper, numbers, 3);
		push(oper, 47);
	} else if (42 == ch) { //multiply
		calculation(oper, numbers, 3);
		push(oper, 42);
	} else if (40 == ch) { //open parenthesis
		push(oper, 40);
	} else if (41 == ch) { //close parenthesis
		calculation(oper, numbers, 4);
	} else {
		return(-1);
	}

	return(0);
}