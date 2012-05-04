#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

struct node {
	long int data;
	long int height;
	struct node * right, * left;
};

struct node * NewNode (long int value);

struct node * RotateL (struct node * node_point);
struct node * RotateR (struct node * node_point);
struct node * RotateLL (struct node * node_point);
struct node * RotateRR (struct node * node_point);

long int height (struct node * node_point);
void insert (struct node ** Thead, long int tmp_data);
void DelTree (struct node * Thead);