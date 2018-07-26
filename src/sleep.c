/* Header files
   stdio.h - for input and output 
   unistd.h - For sleep */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* Main Function */
int main(int argc, char *argv[]) {

	char *p;

	/* Check if variable is empty or not */
	if(argv[1] != NULL){
		
		/* Sleep function via stdlib and convert char to number */
		sleep(strtol(argv[1], &p, 10));
	}

	/* Success return code */
	return 0;
}
