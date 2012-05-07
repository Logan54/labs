#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

struct stack {
	int from;
	int to;
	struct stack * next;
};

static struct stack ** push(struct stack ** st, int from, int to) {
	struct stack * tmp;

	if (NULL == st) {
		fprintf(stderr, "ERROR: NULL pointer(stack)\n");
		exit(0); //solution only for student
	}
	tmp = malloc(sizeof(struct stack));
	if (NULL == tmp) {
		fprintf(stderr, "ERROR: Out of memory!\n");
		exit(0); //solution only for student
	}
	tmp->to = to;
	tmp->from = from;
	tmp->next = *st;
	(*st) = tmp;

	return(st);
}

static int pop(struct stack ** st, FILE * out) {
	struct stack * tmp = *st;
	
	if (NULL == st) {
		fprintf(stderr, "ERROR: NULL pointer(stack)\n");
		exit(0); //solution only for student
	}
	if (NULL == *st) {
		return(0);
	}
	fprintf(out, "%d %d\n", (*st)->from, (*st)->to);
	(*st) = (*st)->next;
	free(tmp);

	return(1);
}

static int compare(const struct edge * first, const struct edge * second) {
	return(first->weight - second->weight);
}

static int master(int * set, int index) {
	int last = index;

	while (index != set[index]) {
		index = set[index];
	}
	set[last] = index;

	return(index);
}

static void colored(int * set, int N, int prev, int next) {
	int i;

	for (i = 0; i < N; ++i) {
		if (set[i] == prev) {
			set[i] = next;
		}
	}
}

int searchTree(struct edge ** edges, int M, int N, FILE * out) {
	int * set;
	int i, tmp;
	struct stack * st = NULL;
	
	set = malloc(sizeof(int) * N);
	if (NULL == set) {
		fprintf(stderr, ERROR_MEM);
		exit(0); //solution only for student
	}
	for (i = 0; i < N; ++i) {
		set[i] = i;
	}
	qsort(*edges, M, sizeof(struct edge), compare);
	for (i = 0; i < M; ++i) {
		if (master(set, (*edges)[i].from - 1) != master(set, (*edges)[i].to - 1)) {
			colored(set, N, set[(*edges)[i].from - 1], master(set, (*edges)[i].to - 1));
			push(&st, (*edges)[i].from, (*edges)[i].to);
		}
	}
	tmp = set[0];
	for (i = 0; i < N; ++i) {
		master(set, i);
		if (tmp != set[i]) {
			return(-1);
		}
	}
	for (i = 0; i < M && pop(&st, out); ++i) ;
	free(set);
	
	return(0);
}
