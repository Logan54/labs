#define SIZE_STR 13

int read_numb (char inter[SIZE_STR], char floa[SIZE_STR]);
int is_bad_input (int b1, int b2, char inter[SIZE_STR], char floa[SIZE_STR], int dot);
double b_to_dec_floa (int b1, char floa[SIZE_STR]);
unsigned long long int b_to_dec_int (int b1, char inter[SIZE_STR]);
char* dec_to_b_int (unsigned long long int n, int b2);
char* dec_to_b_floa (double n, int b2);
char* translate (int b1, int b2, char inte[SIZE_STR], char floa[SIZE_STR]);
