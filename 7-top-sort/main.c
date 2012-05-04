#include "top_sort.h"

#define ERROR(stream, str) fprintf(stream, str);\
									fclose(in);\
									fclose(out);\
									exit(0)

static void readFirstValues(FILE * in, int * N, int * M, FILE * out) {
	int res = 0;

	if (NULL == in || NULL == out) {
		fprintf(stderr, "File error!\n");
		exit(0); //solution only for student
	}
	res = fscanf(in, "%d %d", N, M);
	if (res < 2) {
		ERROR(out, ERROR_NUMB_LINE);
	} else if ( !(0 <= *N && *N <= 1000) ) {
		ERROR(out, ERROR_NUMB_VERT);
	} else if ( !(0 <= *M && *M <= (*N)*((*N) + 1)/2) ) {
		ERROR(out, ERROR_NUMB_EDG);
	}
}

static void allocMemForLists(struct node *** lists, int N) {
	int i;

	*lists = malloc(sizeof(struct node *) * (N + 1));
	if (NULL == (*lists)) {
		fprintf(stderr, "Memory error!\n");
		exit(0); //solution only for student
	}
	for (i = 0; i <= N; ++i) {
		(*lists)[i] = malloc(sizeof(struct node));
		if (NULL == (*lists)[i]) {
			fprintf(stderr, "Memory error!\n");
			exit(0); //solution only for student
		}
		(*lists)[i]->next = NULL;
		(*lists)[i]->index = -1;
	}
}

static struct node ** getValues(int N, int M, struct node ** lists, FILE * in, FILE * out) {
	struct node ** tails;
	int res = 0;
	int from, to, i;
	
	tails = malloc(sizeof(struct node *) * (N + 1));
	if (NULL == tails) {
		fprintf(stderr, "Memory error!\n");
		exit(0);
	}
	for (i = 0; i <= N; ++i) {
		tails[i] = NULL;
	}
	for (i = 0; i < M; ++i) {
		res = fscanf(in, "%d %d", &from, &to);
		if (2 != res) {
			remove_lists(lists, N);
			ERROR(out, ERROR_NUMB_LINE);
		} else if ( (1 > from || N < from) || (1 > to || N < to) ) {
			remove_lists(lists, N);
			ERROR(out, ERROR_VERT);
		}
		if (NULL == (lists[from])->next && (lists[from])->index < 0) {
			(lists[from])->index = to;
			continue;
		}
		tails[from] = (NULL == tails[from]) ? add_to_list(lists[from], to) : add_to_list(tails[from], to);
	}
	return(tails);
}

int main(void) {
	int N = -1, M = -1;
	FILE * in, * out;
	struct node ** lists = NULL;
	struct node ** tmp = NULL;

	in = fopen(INPUT_FILE, "r");
	out = fopen(OUTPUT_FILE, "w");
	readFirstValues(in, &N, &M, out);
	allocMemForLists(&lists, N);
	tmp = getValues(N, M, lists, in, out);
	if (topsort(lists, N, out)) {
		remove_lists(lists, N);
		free(tmp);
		free(lists);
		ERROR(out, ERROR_CYCLE);
	}
	remove_lists(lists, N);
	free(tmp);
	free(lists);
	fclose(in);
	fclose(out);

	return(0);
}
