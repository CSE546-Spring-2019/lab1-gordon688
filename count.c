/**
 * Kyle Gordon
 * Lab 1
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_file(char* searchstring, FILE *fr, FILE *fw);

int main(int argc, char* argv[]) {
	FILE *fr, *fw;
	int close;
	
	// Verify there are the correct number of arguments
	if(argc != 4) {
		printf("Not the correct number of arguments:\n");
		printf("count <input-filename> <search-string> <output-filename>\n");
	} else {
		// Open input file
		if((fr = fopen(argv[1], "rb")) == NULL) {
			printf("Error opening the input file %s\n", argv[1]);
			exit(1);
		}
		// Open output file
		if((fw = fopen(argv[3], "wb")) == NULL) {
			printf("Error opening the output file %s\n", argv[3]);
			exit(1);	
		}
		
		// Search the input file for the given search string and print to output file
		search_file(argv[2], fr, fw);
		
		// Close input file
		close = fclose(fr);
		if(close < 0) {
			perror("close");
		}	
		
		// Close output file
		close = fclose(fw);
		if(close < 0) {
			perror("close");
		}	
	}

	return 0;
}

void search_file(char* searchstring, FILE *fr, FILE *fw) {
	unsigned char buffer[1];		// Buffer contatininf byte from file
	char firstchar = searchstring[0];	// First char of the search string
	int ret = 0;				// Return to positon for rescanning
	int fsize = 0;				// Size of file in bytes
	int sub = 0;				// Current position in searchstring	
	int count = 0;				// Number of strings found in fle
	
	// Find the size of the file in bytes
	fseek(fr, 0, SEEK_END);
	fsize = ftell(fr);
	rewind(fr);
	
	// Loop to read through the file and find string matches		
	while(fread(buffer, sizeof(buffer), 1, fr) == 1) {
		
		// Checks if char from input is in search string
		if(buffer[0] == (searchstring[sub] & 0xff)) {
			
			// Checks if whole search string has been matched
			if(sub == strlen(searchstring)-1) {
				count++;
				sub = 0;
				
				// Check if there is a postition to return and sets file pointer if yes
				if(ret != 0) {
					fseek(fr, ret, SEEK_SET);
					ret = 0;
				}

			// Move to next positon in search string
			} else {
				sub++;
			}
			
			// Checks if the current position in the input file 
			// matches the first char of the search string
			if(sub != 0 && ret == 0 && firstchar == (searchstring[sub] & 0xff)) {
				ret = ftell(fr);
			}
		// Reset the search string to the beginning}
		} else {
			sub = 0;
		}
	}	
	
	// Print file size in bytes and number of matches to screen
	printf("Size of file is %i\n", fsize);
	printf("Number of matches = %i\n", count);

	fwrite(&fsize, sizeof(fsize), 1, fw);
	fwrite(&count, sizeof(count), 1, fw);
}
