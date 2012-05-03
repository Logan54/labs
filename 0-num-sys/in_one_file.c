#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define SIZE_STR 12

void read_numb(char inter[SIZE_STR], char floa[SIZE_STR]) {
	int i;
	char ch;
	
	i = 0;
	inter[0] = '\0';
	floa[0] = '0';
	floa[1] = '\0';
	while (((ch = getchar()) != EOF) && (ch != '.')) {
		if (!(isspace(ch))) {
			inter[i++] = ch;
		}
	}
	inter[i] = '\0';
	if (ch == '.') {
		i = 0;
		while ((ch = getchar()) != EOF) {
			if (!(isspace(ch))) {
				floa[i++] = ch;
			}
		}
		floa[i] = '\0';
	}
}

int is_bad_input (int b1, int b2, char inter[SIZE_STR], char floa[SIZE_STR]) {
	unsigned int i;
	
	if (!((b1 > 1) && (b1 < 17) && (b2 > 1) && (b2 < 17))) {
		return (1);
	}
	if (!((strlen(inter)) && (strlen(floa)))) {
		//fprintf(stderr, "%d %d %s", strlen(floa), strlen(inter), floa);
		return (1);
	}
	for (i = 0; i < strlen(inter); i++) {
		if (!(((isdigit(inter[i])) && ((inter[i] - 48) < b1)) ||
		   ((isupper(inter[i])) && ((inter[i] - 55) < b1)) ||
		   ((islower(inter[i])) && ((inter[i] - 87) < b1)))) {
			return (1);
		}
	}
	for (i = 0; i < strlen(floa); i++) {
		if (!(((isdigit(floa[i])) && ((floa[i] - 48) < b1)) ||
		   ((isupper(floa[i])) && ((floa[i] - 55) < b1)) ||
		   ((islower(floa[i])) && ((floa[i] - 87) < b1)))) {
			return (1);
		}
	}
	return (0);
}

double b_to_dec_floa (int b1, char floa[SIZE_STR]) {
	int i;
	double n;
	
	n = 0;
	for (i = strlen(floa); i >= 0; i--) {
		n += floa[i];
		if (isdigit(floa[i])) {
			n -= 48;
		} else if (islower(floa[i])) {
			n -= 87;
		} else if (isupper(floa[i])) {
			n -= 55;
		}
		n /= b1;
	}
	return (n);
}

unsigned long long int b_to_dec_int (int b1, char inter[SIZE_STR]) {
	unsigned long long int n;
	unsigned int i;
	
	n = inter[0];
	if (isdigit(inter[0])) {
		n -= 48;
	} else if (islower(inter[0])) {
		n -= 87;
	} else if (isupper(inter[0])) {
		n -= 55;
	}
	for (i = 1; i <= (strlen(inter) - 1); i++) {
		n = n * b1 + inter[i];
		if (isdigit(inter[i])) {
			n -= 48;
		} else if (islower(inter[i])) {
			n -= 87;
		} else if (isupper(inter[i])) {
			n -= 55;
		}
	}
	return (n);
}

char* dec_to_b_int (unsigned long long int n, int b2) {
	int i;
	char inter[SIZE_STR * 4];
	char *p;
	
	for (i = 0; n; i++) {
		if ((n % b2) < 10) {
			inter[i] = n % b2 + 48;
		} else {
			inter[i] = n % b2 + 55;
		}
		n /= b2;
	}
	if (i) inter[i] = '\0';
	else {
		inter[i++] = '0';
		inter[i] = '\0';
		i = 0;
	}
	for (i-- ; ((i+1) / 2) && (i != (int)(strlen(inter) - i - 1)); i--) {
		inter[strlen(inter) - i - 1] += inter[i];
		inter[i] = inter[strlen(inter) - i - 1] - inter[i];
		inter[strlen(inter) - i - 1] = inter[strlen(inter) - i - 1] - inter[i];
	}
	p = (char *)malloc(sizeof(inter));
	if (p == NULL) {
		fprintf (stderr, "Error: Невозможно выделить память\n");
		abort();
	}
	strcpy(p, inter);
	return (p);
}

char * dec_to_b_floa(double n, int b2) {
	int i;
	char flo[SIZE_STR];
	double ip;
	char *p;
	
	for (i = 0; i < SIZE_STR; i++) {
		flo[i] = '0';
	}
	flo[0] = '\0';
	for (i = 0; i < SIZE_STR; i++) {
		modf(n * b2, &ip);
		n = n * b2 - ip;
		if ((int)ip < 10) {
			flo[i] = (int)ip + 48;
		} else {
			flo[i] = (int)ip + 55;
		}
	}
	while ((flo[--i] == '0') && (i >= 1)) {
		flo[i] = '\0';
	}
	p = (char *)malloc(sizeof(flo));
	if (p == NULL) {
		fprintf (stderr, "Error: Невозможно выделить память\n");
		abort();
	}
	//printf ("%s\n", flo);
	strcpy(p, flo);
	return (p);
}

char * translate (int b1, int b2, char inter[SIZE_STR], char floa[SIZE_STR]) {
	char str[5 * SIZE_STR + 2];
	char *p, *p1, *p2;
	
	p1 = dec_to_b_int(b_to_dec_int(b1, inter), b2);
	if (strlen(floa) > 0) {
		p2 = dec_to_b_floa(b_to_dec_floa(b1, floa), b2);
		//printf ("%s\n", floa);
		sprintf (str, "%s.%s", p1, p2);
		free (p2);
	} else {
		sprintf (str, "%s", p1);
	}
	free (p1);
	p = (char *)malloc(sizeof(str));
	if (p == NULL) {
		fprintf(stderr, "Error: Невозможно выделить память\n");
		abort();
	}
	strcpy(p, str);
	return (p);
}

int main(void) {
	int b1, b2;
	char inter[SIZE_STR], floa[SIZE_STR];
	char * p;
	
	scanf("%d%d\n", &b1, &b2);
	read_numb(inter, floa);
	if (is_bad_input(b1, b2, inter, floa)) {
		printf("bad input\n");
	} else {
		p = translate(b1, b2, inter, floa);
		printf("%s\n", p);
		free(p);
	}
		
	return (0);
}
