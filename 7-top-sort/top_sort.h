#ifndef TOP_SORT
#define TOP_SORT 1

#define ERROR_NUMB_VERT "bad number of vertices\n"
#define ERROR_VERT "bad vertex\n"
#define ERROR_NUMB_EDG "bad number of edges\n"
#define ERROR_NUMB_LINE "bad number of lines\n"
#define ERROR_CYCLE "impossible to sort\n"

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node * next;
	int index;
};

struct node * add_to_list(struct node * list, int ind);
void remove_lists(struct node ** list, int N);
int topsort(struct node ** list, int N, FILE * out);

#endif
