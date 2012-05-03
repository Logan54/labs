#include <stdio.h>
#include <string.h>
#include "header.h"

int seek_substring_RK (struct pattern * PAT) {
	char sub_tmp[SIZE_TMP];
	
	struct circle_buf BUF = {0, SIZE_TMP - 1, 0, 1, 1, '\0'};
	int j, k = BUF.count;
	
	rewrit (&BUF, sub_tmp);
	sub_tmp[PAT->length] = '\0';
	BUF.hash_str = hash(sub_tmp);
	do {
		j = 0;
		
		//printf ("%d %d \n", PAT->hashpat, BUF.hash_str);
		if ( PAT->hashpat == BUF.hash_str ) {
			do {
				printf ("%d ", k);
				//printf ("'%c' '%c'\n", BUF.buf[(k)%(SIZE_TMP)], PAT->value[j]);
			} while ( (j + 1 < PAT->length) && (BUF.buf[(k++)%(SIZE_TMP)] == PAT->value[j++]) );
			//printf ("\n end_cycle: %d %d\n", BUF.unread_ch, BUF.count);
		}
		k = BUF.count++;
		//printf ("'%c' '%c'\n", BUF.buf[BUF.count%SIZE_TMP - 1], BUF.buf[(BUF.count%SIZE_TMP - 2 + PAT->length)%(SIZE_TMP)]);
		BUF.hash_str = rehash(BUF.hash_str, BUF.buf[BUF.count%SIZE_TMP - 1], BUF.buf[(BUF.count%SIZE_TMP - 2 + PAT->length)%(SIZE_TMP)], PAT->length);
		BUF.unread_ch--;
		BUF.must_read_ch++;
		if (BUF.must_read_ch > 196) {
			rewrit (&BUF, sub_tmp);			
		}
	} while ( /*(BUF.count%SIZE_TMP != BUF.rec) && */(BUF.unread_ch > 0)/* && (PAT->length <= BUF.unread_ch + 1) */);
	//printf ("\nhash_str: %d %c %ld\n", BUF.hash_str, BUF.buf[BUF.count%SIZE_TMP], BUF.count);
	//printf ("%d %d %d %d", BUF.count%SIZE_TMP, BUF.unread_ch, PAT->length, BUF.rec);
	return (0);
}