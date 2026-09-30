#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

void print_state(const double complex*, int);

int main(int argc, char *argv[]){
	int numQubits = 2;
	int dimensions = 1 << numQubits;
	
	double complex *state = calloc(dimensions, sizeof(double complex));

	if(state == NULL){
		fprintf(stderr, "Allcoation Failed\n");
		return 1;
	}
	
	state[0] = 1.0; // all others already |00>
	
	print_state(state, numQubits);	
	
	free(state);
	return 0;
}

void print_state(const double complex *state, int numQubits){
	int dimensions = 1 << numQubits;
	for(int i = 0; i < dimensions; i++){
		double real = creal(state[i]);
		double imaginary = cimag(state[i]);
		printf("|");
		for(int b = numQubits - 1; b >= 0; b--){
			putchar(((i >> b) & 1) ? '1' : '0');
		}
		printf(">: %.4f %c %.4fi\n", real, (imaginary < 0 ? '-' : '+'), fabs(imaginary));
	}	
}
