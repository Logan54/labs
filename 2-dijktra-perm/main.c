#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
#define SIZE_ALPH 10
 
int is_bad_input (char str[SIZE_ALPH]) {
        int i;
		int ar[10];
        
		for (i = 0; i < 10; i++) ar[i] = 0;
        for (i = 0; (i < (int)strlen(str)); i++) {
			if ((!(isdigit(str[i]))) || (ar[str[i] - '0'] != 0)) {
				//printf ("%d %c\n", str[i] - '0', str[i]);
				return (1);
			}
				ar[str[i] - '0'] = 1;
        }
        return (0);
}
 
int next_perm (char str[SIZE_ALPH]) {
        int i, j, n, min;
        char ch;
        
        n = (int)strlen(str) - 1;
        for (i = n; (str[i] <= str[i - 1]) && (i > -1); i--) ;
        i--;
        if (i == -1) return (0);
		min = i + 1;
		for (j = i + 1; (j <= n); j++) {
			if ((str[min] > str[j]) && (str[j] > str[i])) min = j;
		}
		j = min;
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        for (j = i + 1; j <= n / 2; j++) {
            ch = str[j];
            str[j] = str[n - (j - i) + 1];
            str[n - (j - i) + 1] = ch;
        }
        return (1);
}
 
int gen_perm (char str[SIZE_ALPH], int n) {
        int i, flag = 1;
        
        for (i = 1; (i <= n) && flag; i++) {
                flag = next_perm (str);
                if (flag != 0) printf ("%s\n", str);
        }
        
        return (0);
}
 
int main (void) {
        char str[SIZE_ALPH];
        int n;
        
        scanf ("%s", str);
        scanf ("%d", &n);
        if (is_bad_input(str)) {
                printf ("bad input\n");
        } else {
                gen_perm (str, n);
        }
        
        return (0);
}