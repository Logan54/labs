#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

int empty(struct stack ** st) {

	return( NULL == (*st) );
}

int pop(struct stack ** st) {
	struct stack * tmp;
	int res;
	
	if (NULL != (*st)) {
		res = (*st)->data;
		tmp = *st;
		*st = (*st)->next;
		free(tmp);
	} else {
		return(-1);
	}

	return(res);
}

int top(struct stack ** st) {
	int res = -1;

	if ((*st)) {
		res = (*st)->data;
	}

	return(res);
}

void push(struct stack ** stack, unsigned int value) {
	struct stack * tmp = malloc(sizeof(struct stack));

	if (!check_pointer(tmp)) {
		while (pop(stack) > 0) ;
		fprintf(stderr, "No memory!");
		exit(-1);//only student solution
	}
	tmp->data = value;
	tmp->next = *stack;
	*stack = tmp;

	return;
}


