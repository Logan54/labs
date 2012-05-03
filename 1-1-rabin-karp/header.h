#define SIZE_PATTERN 17
#define SIZE_TMP 257 //Необходима степень двойки

int hash (char sub_str[SIZE_PATTERN]);
rehash (int old_hash, char old_ch, char new_ch, int lenpat);
int seek_substring_RK (struct pattern * PAT);
void rewrit (struct circle_buf * BUF, char sub_tmp[SIZE_TMP]);

struct pattern {
	char value[SIZE_PATTERN];
	int length;
	int hashpat;
};

struct circle_buf {
	int unread_ch;      //количество символов в буфере, не прощедших проверку
	int must_read_ch;
	int hash_str;
	int count;          //счётчик проверяемго символа от начала текста
	int rec;
	char buf[SIZE_TMP]; 
};