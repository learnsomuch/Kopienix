/* Header files
   stdio.h - for input and outputi, rename */
#include <stdio.h>
#include <unistd.h>
/* Define constants */
#define EXIT_SUCESS 0;

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: mv <source file> <target>\n");
	printf("Possible supported OPTION:\n");
	printf("\t<source file> \t\t Provide the file you want to move\n");
	printf("\t<target> \t\t Provide target location for the file to be moved\n");
	printf("\t-h, --help \t\t Print help information\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}


/* Main Function */
int main(int argc, char *argv[]) {
	
	/* Variables - initializing buf as char with size of FILENAME_MAX. FILENAME_MAX is defined in stdio.h */
   	char buf[FILENAME_MAX];
	
	/* Check count of arguments to match 3 */
	if( argc == 3 ) {
		
		/* Using getcwd inbuildi where it takes buffer and its size - refer: http://pubs.opengroup.org/onlinepubs/9699919799/functions/getcwd.html */
   		if (getcwd(buf, sizeof(buf)) != NULL) {
   
			if (strcmp(".", argv[2]) == 0) {
				printf("Source: %s\n", argv[1]);
				printf("Target: %s/%s\n", buf, argv[1]);
			}
		}

		/* Check if rename (move) file to different location or different name success or failed */
		if (rename(argv[1], argv[2]) == -1) {
			
			printf("Failed to move file");
		}
	} else if ((argc != 3) || ((strcmp("-h", argv[1]) == 0) || (strcmp("--help", argv[1]) == 0))) {
		
		/* Print help function */
		return help();
	} else {

		/* Print help function */
                return help();
	}

	/* Success return code */
	return EXIT_SUCESS;
}
