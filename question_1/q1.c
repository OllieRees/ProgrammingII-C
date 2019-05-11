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
