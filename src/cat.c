/* Header Files 
   stdio.h - for output 
   unistd.h - For access() */
#include <stdio.h>
#include <unistd.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: cat [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t<filename>  \t\t Name of the file\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* Main Function */
int main(int argc, char *argv[]) {

	/* Variables */
    		
	FILE *file;
	char line[1048];

	if((argv[1] != NULL) && (access(argv[1], F_OK) != -1)) {

		/* Open file with read permissions */
		file = fopen(argv[1], "r"); 
	
		/* while loop to check file sizeof(line) */
		/* Reference: http://pubs.opengroup.org/onlinepubs/009696699/functions/fgets.html */
		while (fgets(line, sizeof(line), file) != NULL) {
			
			/* Print the content line by line */
			printf("%s", line);
		}
	} else {
		
		/* 404 - File not found */
		return help();
	}

	/* Close the file */
	fclose(file);
	
	/* Success return code */
	return 0;
}
