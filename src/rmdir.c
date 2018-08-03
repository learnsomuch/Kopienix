/* header files
   stdio.h - for output
   unistd.h - for rmdir()
   sys/types.h, sys/stat.h - for struct stat	 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: rmdir [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t<directory> \t\t specify directory you want to delete\n");
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
	struct stat info;

	/* Validation */
	if((argv[1] == NULL) || ((strcmp("-h", argv[1]) == 0) || (strcmp("--help", argv[1]) == 0))) {
		
		return help();
	}
	
	/* Looping over arguments and removing them by unlink() 
	   Starting i from 1. Since 0 is program name */
	for(i=1; i<argc; i++) {

		/* Check if directory exists */
		if(stat(argv[i], &info) != 0) {
			printf( "access denied for %s\n", argv[i] );
		} else if(info.st_mode & S_IFDIR) {
			
			/* remove directory */
			rmdir(argv[i]); 
    			printf( "%s directory removed\n", argv[i] );
		} else {
			
			/* validation for directory */
    			printf( "%s is not a directory or not empty\n", argv[i] );
		}

	}

	/* Success return code */
  	return 0;
}

