
void sift(int *ar, int l, int r) {
	int i, tmp;
	
	while (l * 2 <= r) {
		if ( (l * 2 == r) || (ar[l * 2] > ar[l * 2 + 1]) ) {
			i = l * 2;
		} else {
			i = l * 2 + 1;
		}
		if (ar[l] < ar[i]) {
			tmp = ar[l];
			ar[l] = ar[i];
			ar[i] = tmp;
			l = i;
		} else {
			return;
		}
	}
}