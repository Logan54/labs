#include <stdio.h>
#include <string.h>
#include "boyer_moor.h"

int seek_substring_BM (unsigned char tmp[SIZE_TMP], unsigned char pattern[SIZE_PATTERN], unsigned int d[SIZE_ALPH]) {
	long int j, k, count, ind_rec, unread_ch, met, lenpat;
	unsigned char sub_tmp[SIZE_TMP];
	long int i, tmp_count;
	
	met = 0;
	lenpat = (int)strlen(pattern) - 1; //присвоение номера последнего элемента шаблона (-1, так как массив с нуля)
	ind_rec = 0; //индекс, указывающий на место записи
	i = lenpat; //присвоение номера последнего элемента шаблона (-1, так как массив с нуля) 15
	tmp_count = (int)fread(sub_tmp, sizeof(char), SIZE_TMP, stdin);
	unread_ch = tmp_count;
	rewrit (tmp, &tmp_count, sub_tmp, &ind_rec);
	unread_ch--;
	count = i; //счётчик проверяемго символа от начала текста
	do {
		j = lenpat;
		k = count;
		if (unread_ch > 0) {
			printf ("%d ", k + 1);
		}
		while ( (j > 0) && (pattern[j--] == tmp[(k--) % SIZE_TMP]) ) {
			printf ("%d ", k + 1);
		}
		count += d[(unsigned char)tmp[i]];
		unread_ch -= d[(unsigned char)tmp[i]];
		met += d[(unsigned char)tmp[i]];
		if ((met >= 192) && (tmp_count != 0)) {
			tmp_count = (int)fread(sub_tmp, sizeof(char), met, stdin);
			met -= tmp_count;
			unread_ch += tmp_count;
			rewrit (tmp, &tmp_count, sub_tmp, &ind_rec);
		}
		i = (i + d[(unsigned char)tmp[i]]) & (SIZE_TMP - 1);
	} while ( (i != ind_rec) && (unread_ch > 0) );
	//printf ("\n%d %d %d\n", i, ind_rec, unread_ch);
	return (0);
}