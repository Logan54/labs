#include <stdio.h>

#ifndef DIJKSTRA_
#define DIJKSTRA_ 1

#define ERROR_NUMB_VERT "bad number of vertices\n"
#define ERROR_NUMB_EDGE "bad number of edges\n"
#define ERROR_VERT "bad vertex\n"
#define ERROR_LENG "bad length\n"
#define ERROR_NUMB_LINE "bad number of lines\n"

#define NO_PATH "no path\n"
#define OVERFLOW "overflow\n"

#define ERROR_FILE "File error!\n"
#define ERROR_MEM "Out of memory!\n"

#define MIN_NUMB_VERT 0
#define MAX_NUMB_VERT 5000
#define MIN_NUMB_EDGE 0
#define INF 3000000000

#define IN_FILE "in.txt"
#define OUT_FILE "out.txt"

int searchAndPrint(const unsigned int ** matrix, int N, int S, int F, FILE * out);
int readFirstValues(FILE * in, int * N, int * S, int * F, int * M);
int allocArrayOfLists(unsigned int *** matrix, int size);
int getEdges(unsigned int ** matrix, int N, int M, FILE * in);
void memoryFree(unsigned int ** matrix, int N);

#endif
