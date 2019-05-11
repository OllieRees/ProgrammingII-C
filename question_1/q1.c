#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int analyse(double *prod, double *sum, double d1, double d2);

int analyse(double *prod, double *sum, double d1, double d2) {
	printf("initial first number : %f\ninitial second number : %f\n", d1, d2);
	int d1trunc = floor(d1);
	int d2trunc = floor(d2);
	printf("truncuated first number : %d\ntruncuated second number : %d\n", d1trunc, d2trunc);
	*(prod) = d1trunc * d2trunc;
	*(sum) = d1trunc + d2trunc;
	
	//if product isn't 0 then d1 and d2 arne't 0	
	if (*(prod) > 0) {
		return 1;
	}
	if(*(prod) < 0) {
		return -1;
	}

	//if both are 0 then they both have the same sign
	if(d1 == 0 && d2 == 0) {
		return 1;
	}
	else {
		return -1;
	}	
}

int main(int argc, char * argv[]) {
	if (argc == 3) {
		double * prod = malloc(sizeof(double));
		double * sum = malloc(sizeof(double));
		double d1 = (double) atof(argv[1]);
		double d2 = (double) atof(argv[2]);
		printf("%d\n", analyse(prod, sum, d1, d2));
		printf("product : %f\tsum : %f\n", *prod, *sum);
		return 1;
	}
	printf("Failed to provide 2 doubles in the command line : program can't run!\n");
	return 0;
}
