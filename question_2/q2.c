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
	
	int i = (col + (N * row))/2;
	if(*(as + i) != 0) {
		printf("ERROR: Memory in use of (%d, %d)\n", row, col);
	}	
	*(as + i) = val;
	printf("%d\n", *(as + i));
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
	
	int i = (col + (N * row))/2;
	printf("%d\n", *(as + i)); //stores it correctly, but doesn't fetch it correctly.
	return *(as + i);
}

int main(int argc, char * argv[]) {
	
	int N;
	printf("Enter the size of the board : ");
	scanf("%d", &N);
	
	CHECKARR tbl = checkNEW(N);
	int row = 0;
	for(row; row < N; row++) {
		int col = 0;
		for(col; col < N; col++) {
			if(row % 2 == col % 2) {
				int val = (row + col) + (row * col);
				printf("val : %d, success : %d\n", val, checkSTORE(tbl, N, row, col, val));
			}
		}
	}

	row = 0;
	for(row; row < N; row++) {
		int col = 0;
		for(col; col < N; col++) {
			if(row % 2 == col % 2) {
				printf("row : %d, col : %d, val : %d\n", row, col, checkFETCH(tbl, N, row, col));
			}
		}
	}
}
