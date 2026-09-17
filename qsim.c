#include <stdio.h>
#include <complex.h>
#include <math.h>

void print_state(double complex*, int);

int main(int argc, char *argv[]){
	double complex state[2];
	state[0] = 1.0;
	state[1] = 0.0;
	print_state(state, 2);	
}

void print_state(double complex *state, int numQubits){
	int dimensions = 1 << numQubits;
	for(int i = 0; i < dimensions; i++){
		double re = creal(state[i]), im = cimag(state[i]);
		printf("|%d>: %.4f %c %.4fi\n", i, re, (im < 0 ? '-' : '+'), fabs(im));
	}	
}
