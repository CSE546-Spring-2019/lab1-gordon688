/**
 * Kyle Gordon
 * Lab 1
**/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	FILE *fr;
	
	if((fr = fopen(argv[1], "rb")) == NULL) {
		printf("Error opening the input file %s\n", argv[1]);
		exit(1);
	}
	
	int count;
	int size;
	
	
	fread(&count, sizeof(int), 1, fr);
	fread(&size, sizeof(int), 1, fr);
		
	printf("Size of file is: %i\nNumber of matches = %i\n", size, count);
	
	int close = fclose(fr);
	if(close < 0) {
		perror("close");
	}	
	return 0;
}
