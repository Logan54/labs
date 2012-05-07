#include "boyer_moor.h"

void rewrit (unsigned char tmp[SIZE_TMP], long int *tmp_count, unsigned char sub_tmp[SIZE_TMP], long int *ind_rec) {
	int ind;
	for (ind = 0; ind < (*tmp_count); ind++) {
		if (sub_tmp[ind] != '\r') {
			tmp[(*ind_rec)++] = sub_tmp[ind];
			if ((*ind_rec) >= 256) (*ind_rec) %= SIZE_TMP;
		}
	}
}