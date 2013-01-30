#include "huffman.h"

void fill_file(FILE * in, FILE * out, struct smb * alph, struct node * tree) {
	unsigned char ch = '\0';
	unsigned int i;
	BARR_ELTYPE * buf;
	unsigned int count;
	unsigned char bool;
	struct node * tmp;
	unsigned int index = BUFFER_SIZE;
	unsigned int indtmp;
	char BUFFER[BUFFER_SIZE] = {0, };
	
	buf = BARR_MALLOC(CHAR_BIT);
	//fprintf(stderr, "BARR_MALLOC fill_file: buf\n");
	check_pointer(buf);
	fseek(in, WIN_NEW_LINE + 1, SEEK_SET);
	rewind(out);
	fwrite(&ch, 1, 1, out);
	BARR_CLEARARRAY(buf, CHAR_BIT);
	count = write_tree(out, tree, buf);
	index = (unsigned int)fread(BUFFER, 1, BUFFER_SIZE, in);
	while (!feof(in)) {
		ch = BUFFER[BUFFER_SIZE - index--];
		for (i = 0; (alph[ch].lengthcode) && (i < alph[ch].lengthcode); i++) {
			bool = BARR_TEST(alph[ch].code, i) ? 1 : 0;
			set_bit(buf, bool, count, out);
			count = (count + 1) % BARR_ELBITS;
		}
		if (0 == index) {
			index = (unsigned int)fread(BUFFER, 1, BUFFER_SIZE, in);
		}
	}
	indtmp = index;
	ch = BUFFER[indtmp - index--];
	while (-1 != index) {
		for (i = 0; (alph[ch].lengthcode) && (i < alph[ch].lengthcode); i++) {
			bool = BARR_TEST(alph[ch].code, i) ? 1 : 0;
			set_bit(buf, bool, count, out);
			count = (count + 1) % BARR_ELBITS;
		}
		ch = BUFFER[indtmp - index--];
	}
	for (i = 8 - count, bool = 0, tmp = tree; i > 0; i--) {
		if ((NULL != tmp->left) && (NULL != tmp->right)) {
			tmp = tmp->right;
		}
		if ((NULL == tmp->left) && (NULL == tmp->right)) {
			bool++;
			tmp = tree;
		}
	}
	while (0 != (count % BARR_ELBITS) ) {
		set_bit(buf, 0, count++, out);
	}
	fseek(out, 0, SEEK_SET);
	fwrite(&bool, 1, 1, out);
	BARR_FREE(buf);
	//fprintf(stderr, "BARR_FREE fill_file: buf\n");

	return;
}
