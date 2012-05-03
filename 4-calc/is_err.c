#include <ctype.h>

int isoper(unsigned char op) {
	if ('-' == op || '+' == op || '*' == op || '/' == op) {
		return(1);
	} else {
		return(0);
	}
}

int is_err(unsigned char first, unsigned char second) {
	if (isdigit(first)) {
		if (isdigit(second)
			|| isoper(second)
			|| ('(' == second)
			|| (')' == second)) {
			return(0);
		} else {
			return(1);
		}
	} else if (isoper(first)) {
		if ('(' == second || isdigit(second)) {
			return(0);
		} else {
			return(1);
		}
	} else if ('(' == first) {
		if (isdigit(second) || '(' == second) {
			return(0);
		} else {
			return(1);
		}
	} else if (')' == first) {
		if (isoper(second) || ')' == second) {
			return(0);
		} else {
			return(1);
		}
	} else {
		return(1);
	}
}