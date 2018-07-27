/* Header files
   stdio.h - for input and output 
   stdlib.h - for strtol
   ctype.h - for isdigit
   unistd.h - For sleep */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: sleep [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t<number if seconds> \t Enter number of seconds you want to sleep\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* Main Function */
int main(int argc, char *argv[]) {
	
	char *p = NULL;

	/* Check if variable is empty or not */
	if(*p != '\0') {

		return help();
	} if(argv[1] == NULL) {

		return help();
	} else {

		/* Sleep function via stdlib and convert char to number */
               	sleep(strtol(argv[1], &p, 10));
	}
	/* Success return code */
	return 0;
}
