#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int * CHECKARR;

CHECKARR checkNEW(int N);
int checkSTORE(CHECKARR as, int N, int row, int col, int val);
int checkFETCH(CHECKARR as, int N, int row, int col);

CHECKARR checkNEW(int N) {
	if (N <= 0) {
		N = 6;
	}

	int * arr = malloc((N * N * sizeof(int))/2);
	int i = 0;
	for(i; i < N; i++) {
		int * ptr = malloc((N * sizeof(int))/2);
		ptr = (arr + ((N * i)/2));
	}
	
	memset(arr, 0, (N * N * sizeof(int))/2);
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
	
	int i = (col + 1 + (N * row))/2;	
	*(as + i) = val;
	return 1;
}

int checkFETCH(CHECKARR as, int N, int row, int col) {
	
	//index out of bounds
	if(row < 0 || col < 0) {
		return -1;
	}

	if(row >= N || col >= N) {
		return -1;
	}
	
	//improper rules
	if(row % 2 != col % 2) {
		return -1;
	}
	
	int i = (col + 1 + (N * row))/2;
	return *(as + i);
}

int main(int argc, char * argv[]) {
	
	int N = 10;
	
	CHECKARR tbl = checkNEW(N);
	printf("%d\n", checkSTORE(tbl, N, 0, 0, 5));
	printf("%d\n", checkFETCH(tbl, N, 0, 0));
	printf("%d\n", checkFETCH(tbl, N, 1, 1));
	printf("%d\n", checkSTORE(tbl, N, 0, 1, 1));
	printf("%d\n", checkFETCH(tbl, N, 0, 1));
	printf("%d\n", checkSTORE(tbl, N, 0, 2, 8));
	printf("%d\n", checkFETCH(tbl, N, 0, 2)); 
}
