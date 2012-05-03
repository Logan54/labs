#include "header.h"
#include <stdio.h>

void rewrit (struct circle_buf * BUF, char sub_tmp[SIZE_TMP]) {
	static int tmp_count;
	int ind;
	
	if ( tmp_count != -1 ) {
		tmp_count = (int)fread(sub_tmp, sizeof(char), BUF->must_read_ch, stdin);
		BUF->unread_ch += tmp_count;
		for (ind = 0; ind <= tmp_count; ind++) {
			BUF->buf[BUF->rec++] = sub_tmp[ind];
			BUF->rec %= SIZE_TMP;
		}
		BUF->must_read_ch = 0;
		if (tmp_count < BUF->must_read_ch) {
			tmp_count = -1;
		}
	}
}