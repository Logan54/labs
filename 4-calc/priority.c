#include "calc.h"

int priority (unsigned int ch) {
	if (('*' == ch) || ('/' == ch)) {
		return(3);
	} else if (('+' == ch) || ('-' == ch)) {
		return(2);
	} else if ('(' == ch) {
		return(1);
	} else {
		return(-1);
	}

}
