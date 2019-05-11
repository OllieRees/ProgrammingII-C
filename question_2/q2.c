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

	int * arr = malloc(((1 + (N * N)) * sizeof(int))/2);
	memset(arr, 0, ((1 + (N * N)) * sizeof(int))/2);
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
	return *(as + i);
}

