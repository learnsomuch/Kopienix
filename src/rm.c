/* header files
   stdio.h - for output
   unistd.h - for access()	 */
#include <stdio.h>
#include <unistd.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: rm [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t<file-name>, <file-names-with-space> \t\t File name(s) of which you want to delete\n");
	printf("\t-h, --help \t\t\t\t\t Print help information\n");
	printf("If no arguments are passed, default OPTION is -h\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* Main Function */
int main(int argc, char *argv[]) {

	/* Variables */
	int i;
	int flag = 0;

	/* Validation */
	if((argv[1] == NULL) || ((strcmp("-h", argv[1]) == 0) || (strcmp("--help", argv[1]) == 0))) {
		
		return help();
	}
	
	/* Looping over arguments and removing them by unlink() 
	   Starting i from 1. Since 0 is program name */
	for(i=1; i<argc; i++) {
		
		/* Check if file exists with F_OK. R_OK, W_OK, X_OK also exists with access */
		if(access(argv[i], F_OK) != -1) {
 
			/* unlink() - http://man7.org/linux/man-pages/man2/unlink.2.html */	
			if(unlink(argv[i]) == 0) {
				printf("Removed file: %s\n",argv[i]);
			}
		} else {

			printf("File does not exist: %s\n", argv[i]);
			flag = 1;
		}
	}

	/* Flag check to see if any of the passed argument file doesn't exist */
	if(flag != 0) {
		printf("\n");
		return help();
	}

	/* Success return code */
  	return 0;
}

