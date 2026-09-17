#include <stdio.h>

int main(int argc, char *argv[]){
	for(int i = 0; i < argc; i++){
		char *word = argv[i];	
		printf("%s\n", word);
	}
	return 0;
}
