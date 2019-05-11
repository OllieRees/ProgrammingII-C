#include <stdlib.h>
#include <stdio.h>

typedef int * CHECKARR;

CHECKARR checkNEW(int N);
int checkSTORE(CHECKARR as, int N, int row, int col, int val);
int checkFETCH(CHECKARR as, int N, int row, int col);

CHECKARR checkNEW(int N) {

	int * arr = malloc((N * N * sizeof(int))/2);
	int i = 0;
	for(i; i < N; i++) {
		int * ptr = malloc((N * sizeof(int))/2);
		ptr = (arr + ((N * i)/2));
	}
	return arr;
}	

int checkSTORE(CHECKARR as, int N, int row, int col, int val) {
	//index out of bounds
	if(row >= N || col >= N) {
		return -1;
	}
	
	//improper rules
	if(row % 2 != col % 2) {
		return -1;
	}
	
	*((as + (row + 1 + (N * col)))/2) = val;
	return 1;
}

int checkFETCH(CHECKARR as, int N, int row, int col) {
	
	//index out of bounds
	if(row >= N || col >= N) {
		return -1;
	}
	
	//improper rules
	if(row % 2 != col % 2) {
		return -1;
	}

	return *((as + (row + 1 + (N * col)))/2);
}

int main() {
	int N = 6;
	CHECKARR tbl = checkNEW(N);
	printf("%d\n", checkSTORE(tbl, N, 5, 5, 10));
	printf("%d\n", checkFETCH(tbl, N, 5, 5));
	printf("%d\n", checkSTORE(tbl, N, 0, 1, 1)); 
}
