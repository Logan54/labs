#ifndef KRUSKAL_
#define KRUSKAL_ 1

#define ERROR_NUMB_VERT "bad number of vertices\n"
#define ERROR_NUMB_EDGE "bad number of edges\n"
#define ERROR_VERT "bad vertex\n"
#define ERROR_LENG "bad length\n"
#define ERROR_NUMB_LINE "bad number of lines\n"
#define ERROR_TREE "no spanning tree\n"

#define ERROR_FILE "File error!\n"
#define ERROR_MEM "Out of memory!\n"

#define MIN_NUMB_VERT 0
#define MAX_NUMB_VERT 5000
#define MIN_NUMB_EDGE 0

#define IN_FILE "in.txt"
#define OUT_FILE "out.txt"

struct edge {
	int from;
	int to;
	int weight;
};

int readFirstValues(FILE * in, int * N, int * M);
int allocArrayOfEdges(struct edge ** edges, int size);
int getEdges(struct edge * edges, int size, const int N, FILE * in);
int searchTree(struct edge ** edges, int M, int N, FILE * out);

#endif
