#include "header.h"

struct node * RotateL (struct node * node_point) {
	struct node * tmp_point;
	
	tmp_point = node_point->left;
	if (tmp_point == NULL) {
		node_point->left = NULL;
	} else {
		node_point->left = tmp_point->right;
	}
	tmp_point->right = node_point;
	
	node_point->height = max (height(node_point->right), height(node_point->left)) + 1;
	tmp_point->height = max (height(tmp_point->right), height(node_point)) + 1;
	
	return (tmp_point);
}

struct node * RotateR (struct node * node_point) {
	struct node * tmp_point;
	
	tmp_point = node_point->right;
	if (tmp_point == NULL) {
		node_point->right = NULL;
	} else {
		node_point->right = tmp_point->left;
	}
	tmp_point->left = node_point;
	
	node_point->height = max ( height(node_point->left), height(node_point->right)) + 1;
	tmp_point->height = max (height(tmp_point->right), node_point->height) + 1;
	
	return (tmp_point);
}

struct node * RotateLL (struct node * node_point) {
	node_point->left = RotateR (node_point->left);
	
	return (RotateL (node_point));
}

struct node * RotateRR (struct node * node_point) {
	node_point->right = RotateL (node_point->right);
	
	return (RotateR (node_point));
}