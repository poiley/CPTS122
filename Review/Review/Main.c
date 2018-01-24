#include <stdio.h>	// printf(), scanf()
#include <string.h> // strcpy(), strncpy(), strcat(),
					// strncat(), strcmp(), strlen(),
					// strtok() 

#include "Header.h";

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

	char destination[] = "fuck";
	char source[] = "fiji";
	my_strncat(destination, source, 4);
	puts(destination);

}

char *my_strcpy(char *destination, const char *source) {
	char *pointer;
	
	pointer = destination;
	while (*destination++ = *source++);

	return pointer;
}

char *my_strncat(char *destination, const char *source, int n) {
	char *pointer = destination + strlen(destination);

	while (*source != '\0' && n--) {
		*pointer++ = *source++;
	}

	*pointer = '\0';

	return destination;
}

int my_strcmp(char *s1, char *s2) {
	while (*s1 != NULL && *s2 != NULL && *s1 == *s2) {
		s1 += 1;
		s2 += 1;
	}

	int a = (char) *s1 - (char) *s2;
	
	return  a;
}
