#include "top_sort.h"

struct node * add_to_list(struct node * list, int ind) {
	struct node * tmp = NULL;

	tmp = malloc(sizeof(struct node));
	if (NULL == tmp) {
		fprintf(stderr, "Memory error!\n");
		exit(0);
	}
	tmp->next = NULL;
	tmp->index = ind;
	while (NULL != list && NULL != list->next) {
		list = list->next;
	}
	list->next = tmp;

	return(tmp);
}
/*
 * rmv - remove
 */
static void rmv(struct node * list) {
	if (NULL != list->next) {
		rmv(list->next);
	}
	free(list);
}

void remove_lists(struct node ** list, int N) {
	if (NULL == list) {
		fprintf(stderr, "ERROR: NULL pointer(remove_lists)!\n");
		return;
	}
	while (N >= 0) {
		if (NULL != list[N]) {
			rmv(list[N]);
		}
		N--;
	}
}
