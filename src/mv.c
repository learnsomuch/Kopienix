/* Header files
   stdio.h - for input and outputi, rename */
#include <stdio.h>
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
	
	/* Check count of arguments to match 3 */
	if( argc == 3 ) {

		/* Check if rename (move) file to different location or different name success or failed */
		if(rename(argv[1], argv[2]) == -1) {
			
			printf("Failed to move file");
		}
	} else {
		
		/* Print help function */
		return help();
	}

	/* Success return code */
	return EXIT_SUCESS;
}
