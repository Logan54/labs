#ifndef CALC_H

#define CALC_H

#define FILE_NAME_RD "in.txt"
#define FILE_NAME_WR "out.txt"
#define IN_STR_SIZE 1002

struct stack {
	struct stack * next;
	int data;
};

int check_pointer(void * p);
void push(struct stack ** stack, unsigned int value);
int pop(struct stack ** st);
int top(struct stack ** st);
int empty(struct stack ** st);
int priority(unsigned int ch);
int get_numb(char in_str[IN_STR_SIZE], int * index);
void calculation(struct stack ** oper, struct stack ** numbers, unsigned int priority);
int compute(int oper, int first, int second, struct stack ** numbers);
int is_err(unsigned char first, unsigned char second);
int sorter(unsigned char ch, struct stack ** numbers, struct stack ** oper);

#endif
