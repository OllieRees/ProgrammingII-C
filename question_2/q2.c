#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int * CHECKARR;

CHECKARR checkNEW(int N);
int checkSTORE(CHECKARR as, int N, int row, int col, int val);
int checkFETCH(CHECKARR as, int N, int row, int col);

CHECKARR checkNEW(int N) {
	
	if(N <= 0) {
		printf("No board.\n");
		exit(1);
	}

	if(N > 0) {
		int* arr = malloc(((1 + (N * N)) * sizeof(int))/2);
		memset(arr, 0, ((1 + (N * N)) * sizeof(int))/2);
		return arr;
	}
}	

int checkSTORE(CHECKARR as, int N, int row, int col, int val) {
	
	//check for null pointer
	if(as == NULL) {
		printf("Uh oh! Looks like you're using a null pointer.\n");
		return -1;
	}

	//invalid N
	if(N <= 0) {
		printf("Your board doesn't exist.\n");
		return -1;	
	}

	//index out of bounds
	if(row >= N || col >= N) {
		printf("Java.lang.Exception.IndexOutOfBoundsException e {e.printStackTrace()}\n");
		return -1;
	}
	if(row < 0 || col < 0) { 
		printf("Rows and columns are less than 0.\n");
		return -1;
	}

	//improper rules
	if(row % 2 != col % 2) {
		printf("You're playing checkers. You can only move to squares with the same parity.\n");
		return -1;
	}
	
	int i = (col + (N * row))/2;
	*(as + i) = val;
	return 1;
}

int checkFETCH(CHECKARR as, int N, int row, int col) {
	
	//check for null pointer
	if(as == NULL) {
		printf("Uh oh! Looks like you're using a null pointer.\n");
		return -1;
	}

	//invalid N
	if(N <= 0) {
		printf("Your board doesn't exist.\n");
		return -1;
	}

	//index out of bounds
	if(row < 0 || col < 0) { 
		printf("Java.lang.Exception.IndexOutOfBoundsException e {e.printStackTrace()}\n");
		return -1;
	}
	if(row >= N || col >= N) { 
		printf("Rows and columns are less than 0.\n");
		return -1;
	}	
	
	//improper rules
	if(row % 2 != col % 2) {
		printf("You're playing checkers. You can only move to squares with the same parity.\n");
		return -1;
	}
	
	int i = (col + (N * row))/2;
	return *(as + i);
}

int main(char * argv[], int argc) {
	int n = -10;
	int* ptr = checkNEW(n);
	printf("%d\n", checkSTORE(ptr, n, 0, 0, 10));
	printf("%d\n", checkFETCH(ptr, n, 0, 0));
}
