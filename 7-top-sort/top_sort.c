#include "top_sort.h"

#define ERROR(stream, str) fprintf(stream, str);\
									fclose(out);\
									exit(0)

struct stack {
	int data;
	struct stack * next;
};

static int DFS(struct node ** list, int ind, char * color, struct stack ** st);

static struct stack ** push(struct stack ** st, int val) {
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
	tmp->data = val;
	tmp->next = *st;
	(*st) = tmp;

	return(st);
}

static int pop(struct stack ** st) {
	int val;
	struct stack * tmp = *st;
	
	if (NULL == st) {
		fprintf(stderr, "ERROR: NULL pointer(stack)\n");
		exit(0); //solution only for student
	}
	val = (*st)->data;
	(*st) = (*st)->next;
	free(tmp);

	return(val);
}

/*
 * if cycle return true
 * color: 0 - white, 1 - grey, 2 - black
 */
int topsort(struct node ** list, int N, FILE * out) {
	char * color = NULL;
	struct stack * st = NULL;
	int i;

	color = malloc(sizeof(char) * N);
	if (NULL == color) {
		ERROR(stderr, "ERROR: Out of memory!\n");
	}
	st = malloc(sizeof(struct stack));
	if (NULL == st) {
		ERROR(stderr, "ERROR: Out of memory!\n");
	}
	for (i = 0; i <= N; ++i) {
		color[i] = (char)0;
	}
	for (i = 1; i <= N; ++i) {
		if ( ((char)2 != color[i]) && ((char)1 == color[i] || DFS(list, i, color, &st)) ) { 
			return(1);
		}
	}
	for (i = 1; i <= N; ++i) {
		fprintf(out, "%d ", pop(&st));
	}
	free(st);
	free(color);

	return(0);
}

/*
 * DFS     - Depth-First search
 * ar_list - array of lists of vertex
 * ind     - index of working vertex
 * color   - array of color of vertex
 * st      - pointer to stack of result of topological sort
 */
static int DFS(struct node ** list, int ind, char * color, struct stack ** st) {
	struct node * vert = list[ind];
	
	if ((char)1 == color[ind]) {
		return(1);
	} else if ((char)2 == color[ind]) {
		return(0);
	}
	color[ind] = 1;
	while (vert && vert->index > 0) {
		if (DFS(list, vert->index, color, st)) {
			return(1);
		}
		vert = vert->next;
	}
	color[ind] = 2;
	st = push(st, ind);

	return(0);
}
