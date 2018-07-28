/* Header files
   stdio.h - for input and output 
   stdlib.h - for strtol
   ctype.h - for isdigit
   unistd.h - For sleep */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

	
	char *p;
	long val;

	if(argv[1] != NULL) {
	
		/* Return 0 if not an integer */
		val = strtol(argv[1], &p, 10);

		/* Sleep function via stdlib */
               	if(val != 0) {
			
			sleep(val);
		} else {

			return help();
		}

	} else if(*p != '\0') {

                return help();
        } else {
		
		return help();
	}

	/* Success return code */
	return 0;
}
