#include <stdio.h>	// printf(), scanf()
#include <string.h> // strcpy(), strncpy(), strcat(),
					// strncat(), strcmp(), strlen(),
					// strtok() 

//NOTE: strtok() is for delimiting

void main(int argc, char *argv[]) {
	FILE *infile = NULL;
	char line[100] = "";

	infile = fopen("data.csv", "r"); // fopen requires two args, filename and read/write type

	if (infile != NULL) { // if file exists and is readable
		char *split_data[3], *last_name, *first_name, *major;

		while(fgets(line, 100, infile)) {
			last_name	= strtok(line, ",");
			
			/* You use NULL here because the address of the second item is different. If you used
			*  `line` here, it would just reference string_line's address.*/
			first_name	= strtok(NULL, ","); 
			major		= strtok(NULL, ",");
			
			printf("%s %s, %s", first_name, last_name, major);
		}

	}
}