#include "calc.h"

int compute(int oper, int first, int second, struct stack ** numbers) {
	if ('+' == oper) {
		push(numbers, first + second);
	} else if ('-' == oper) {
		push(numbers, first - second);
	} else if ('*' == oper) {
		push(numbers, first * second);
	} else if ('/' == oper && 0 != second) {
		push(numbers, first / second);
	} else {
		return(-1);
	}
	return(0);
}