#ifndef HUFFMAN
	#define HUFFMAN 1
	
	#include <stdio.h>
	#include "bitarray.h"
	
	#define FILE_NAME_RD "in.txt"
	#define FILE_NAME_WR "out.txt"
	#define MAX_BITS 32
	#define ALPH_SIZE 256
	#define WIN_NEW_LINE 2
	#define BUFFER_SIZE 1024
	
	struct node {
		char ch;
		struct node * left;
		struct node * right;
	};
	
	struct smb {
		unsigned char code[MAX_BITS];
		unsigned int lengthcode;
	};

	short int get_option (FILE * in);
	int * get_probtree (struct node ** tree, FILE * in);
	void check_pointer (void * p);
	void remove_tree (struct node * tree);
	void fill_code(struct node * tree, struct smb * alph, unsigned char tmp_code[], unsigned int deep);
	void fill_file(FILE * in, FILE * out, struct smb * alph, struct node * tree);
	unsigned int write_tree(FILE * out, struct node * tree, BARR_ELTYPE * buf);
	
	void clear_buf(BARR_ELTYPE * buf);
	void set_bit(BARR_ELTYPE * buf, char val, unsigned char count, FILE * in);
	unsigned char get_bit(BARR_ELTYPE * buf, unsigned char count, FILE * in);
	void fill_buf(BARR_ELTYPE * buf, FILE * in);
	char get_byte(BARR_ELTYPE * buf, char count, FILE * in);
	
	unsigned char get_size_from_file(FILE * in);
	void decompres(FILE * in, FILE * out, char size_lost_byte);
	void build_node_tree(BARR_ELTYPE * buf, struct node * tree, unsigned int * count, FILE * in);
	int array_to_zero (struct smb * alph);

	int is_empty_file (FILE * in);
	
	void RLE (FILE * out, unsigned long int count, short int ch);
	void UNRLE (FILE * in, FILE * out);
	int is_RLE (int * alph_val);

#endif
