#include <stdlib.h>
#include "huffman.h"

struct list {
	struct list * next;
	struct node * node;
	unsigned int value;
};

void check_pointer (void * p) {
	if (NULL == p) {
		fprintf(stderr, "No memory!");
		exit(-1); //only students solution!!!
	}
}

static struct list * create_list (void) { //создание односвязного списка с фиктивной головой
	struct list * root = (struct list *)malloc(sizeof(struct list));

	//fprintf(stderr, "MALLOC create_list: root\n");
	check_pointer(root);
	root->value = 0;
	root->next = NULL;
	root->node = NULL;
	
	return(root);
}

static void add_in_list (struct list * root, struct node * node, unsigned int value) {
	struct list * leaf;
	
	leaf = (struct list *)malloc(sizeof(struct list));
	//fprintf(stderr, "MALLOC add_in_list: leaf\n");
	check_pointer(leaf);
	leaf->value = value;
	leaf->node = node;
	while ((NULL != root->next) && (root->next->value < value)) {
		root = root->next;
	}
	leaf->next = root->next;
	root->next = leaf;
	
	return;
}

static void remove_from_list (struct list * root) { //удаляем первый после фиктивной головы
	struct list * tmp;
	
	tmp = root->next;
	root->next = tmp->next;
	free(tmp);
	//fprintf(stderr, "FREE remove_from_list: tmp\n");
	
	return;
}

static void remove_list (struct list * root) {
	while (NULL != root->next) {
		remove_from_list(root);
	}
	free(root);
	//fprintf(stderr, "FREE remove_list: root\n");
	
	return;
}

int * get_probtree (struct node ** tree, FILE * in) {
	int * alph; //массив частот
	unsigned int ch;
	int i = 0;
	int count = 0;
	int count_smb = 0;
	int smb;
	struct list * root;
	struct node * node;
	
	fseek(in, WIN_NEW_LINE + 1, SEEK_SET);
	alph = (int *)calloc(ALPH_SIZE, sizeof(int));
	//fprintf(stderr, "CALLOC get_probtree: alph_val/val\n");
	check_pointer(alph);
	while ( (ch = getc(in)) != EOF ) { //желательно переписать с буфером
		(alph[ch])++;
		//fprintf(stderr, "%d\n", ch);
		count_smb++;
		smb = ch;
	}
	if (1 == count_smb) {
		return(alph);
	}
	root = create_list();
	for (i = 0; i < ALPH_SIZE; i++) {
		if (alph[i] > 0) {
			node = (struct node *)malloc( sizeof(struct node) );
			//fprintf(stderr, "MALLOC get_probtree: node\n");
			check_pointer(node);
			node->ch = i;
			node->left = NULL;
			node->right = NULL;
			add_in_list(root, node, alph[i]);
			count++;
		}
	}
	//цикл создания узлов в списке. на каждом шаге общее число элементов списка уменьшается на 1.
	while (1 != count) {
		node = (struct node *)malloc( sizeof(struct node) );
		//fprintf(stderr, "MALLOC get_probtree: node\n");
		check_pointer(node);
		node->left = root->next->node;
		node->right = root->next->next->node;
		add_in_list(root, node, root->next->value + root->next->next->value);
		remove_from_list(root);
		remove_from_list(root);
		--count;
	} //построили
	(*tree) = root->next->node;
	remove_list(root);
	
	return(alph);
}

void remove_tree (struct node * tree) {
	if (NULL != tree) {
		if (NULL != tree->right) {
			remove_tree(tree->right);
		}
		if (NULL != tree->left) {
			remove_tree(tree->left);
		}
		free(tree);
		//fprintf(stderr, "FREE remove_tree: tree\n");
	}
	
	return;
}
