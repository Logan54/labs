#define SIZE_PATTERN 17
#define SIZE_ALPH 257
#define SIZE_TMP 256

int seek_substring_BM (unsigned char tmp[SIZE_TMP], unsigned char pattern[SIZE_PATTERN], unsigned int d[SIZE_ALPH]);
void rewrit (unsigned char tmp[SIZE_TMP], long int *tmp_count, unsigned char sub_tmp[SIZE_TMP], long int *ind_rec);