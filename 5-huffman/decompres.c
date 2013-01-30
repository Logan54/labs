#include "huffman.h"

void build_node_tree(BARR_ELTYPE * buf, struct node * tree, unsigned int * count, FILE * in) {
	
	(*count) %= 8;
	if (1 == get_bit(buf, (*count)++, in)) {
		tree->left = malloc(sizeof(struct node));
		//fprintf(stderr, "MALLOC build_node_tree: tree->leaf\n");
		check_pointer(tree->left);
		tree->left->left = tree->left->right = NULL;
		build_node_tree(buf, tree->left, count, in);
	} else {
		tree->ch = get_byte(buf, *count, in);
		return;
	}
	tree->right = malloc(sizeof(struct node));
	//fprintf(stderr, "MALLOC build_node_tree: tree->right\n");
	check_pointer(tree->right);
	tree->right->left = tree->right->right = NULL;
	if (1 == get_bit(buf, (*count)++, in)) {
		tree->right->left = malloc(sizeof(struct node));
		//fprintf(stderr, "MALLOC build_node_tree: tree->right->left\n");
		check_pointer(tree->right->left);
		tree->right->left->left = tree->right->left->right = NULL;
		tree->right->right = malloc(sizeof(struct node));
		//fprintf(stderr, "MALLOC build_node_tree: tree->right->right\n");
		check_pointer(tree->right->right);
		tree->right->right->left = tree->right->right->right = NULL;
		build_node_tree(buf, tree->right->left, count, in);
		build_node_tree(buf, tree->right->right, count, in);
	} else {
		tree->right->ch = get_byte(buf, *count, in);
	}
	
	return;
}

void trans(BARR_ELTYPE * buf, unsigned int * count, struct node * tree, FILE * in, FILE * out, char size_lost_byte) {
	unsigned char i = (size_lost_byte) % 8;
	unsigned char val;
	struct node * tmp = tree;
	unsigned int index = 0;
	char BUFFER[BUFFER_SIZE] = {0, };
	
	*count %= 8;
	while (!feof(in)) { //пока поступают символы
		val = get_bit(buf, *count, in);
		(*count)++;
		(*count) %= 8;
		if (val && (NULL != tmp->left) && (NULL != tmp->right) ) {
			tmp = tmp->left;
		} else if ((NULL != tmp->left) && (NULL != tmp->right)) {
			tmp = tmp->right;
		}
		if ( (NULL == tmp->left) && (NULL == tmp->right) ) {
			BUFFER[index++] = tmp->ch;
			tmp = tree;
			if (128 == index) {
				fwrite(&BUFFER, 1, index, out);
				index = 0;
			}
		}
	}
	if (index > 0) {
		i = index - size_lost_byte;
		fwrite(&BUFFER, 1, i, out);
	}

	return;
}

void decompres(FILE * in, FILE * out, char size_lost_byte) { //должна быть рекурсивной
	struct node * tree = NULL;
	BARR_ELTYPE * buf;
	unsigned int count = 0; //счётчик битов
	
	buf = BARR_MALLOC(CHAR_BIT);
	check_pointer(buf);
	fill_buf(buf, in);
	tree = malloc(sizeof(struct node));
	//fprintf(stderr, "MALLOC decompres: tree\n");
	check_pointer(tree);
	tree->left = tree->right = NULL;
	build_node_tree(buf, tree, &count, in);
	count %= 8;
	trans(buf, &count, tree, in, out, size_lost_byte);
	remove_tree(tree);
	
	return;
}
