/**
 * Kyle Gordon
 * Lab 1
**/

#include <stdio.h>
#include <string.h>
FILE *fp;

void file_open(char filename[], int mode) {
	if(mode == 1) {
		fp = fopen(filename, "r");
	} else {
		fp = fopen(filename, "w");
	}
}

int search_file(char* searchstring) {
	int pos = 0;		// Current position in the file
	int ret = 0;		// Return to positon for rescanning
	char buffer[20];	// Buffer with bytes from file
	int fsize = 0;		// Size of file in bytes
	int sub = 0;		// Position in searchstring	
	int count = 0;		// Number of strings found in fle

	// Find the size of the file in bytes
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	rewind(fp);
/*		
	while(fread(buffer, sizeof(buffer), 1, fp) == 1) {
		printf("%c %c \n", buffer[0], searchstring[sub]);
		if(buffer[0] == (searchstring[sub] & 0xff)) {
			if(sub == strlen(searchstring)-1) {
				count++;
				sub = 0;
			} else {
				sub++;
			}
		} else {
			sub = 0;
		}
	}
	
*/

	fread(buffer, sizeof(buffer), 1, fp);
	
	int index;
	for(index = 0; index < sizeof(buffer); index++) {
		if(buffer[index] == (searchstring[sub] & 0xff)) {
			if(sub == strlen(searchstring)-1) {
				count++;
				sub = 0;
			} else {
				sub++;	
			}			
		} else {
			sub = 0;
		}
	}
	printf("%i\n", count);
}

void file_close(void) {
	fclose(fp);
}

int main(int argc, char* argv[]) {
	
	if(argc != 4) {
		printf("Error\n");
	} else {
		file_open(argv[1], 1);
		search_file(argv[2]);
		file_close();
	}

	return 0;
}

