/* Header Files 
   stdio.h - For output  */
#include <stdio.h>

/* Main Function */
int main(void) {

	/* Variables */
    	char hostname[1024];

    	/* Reference: https://linux.die.net/man/2/gethostname */
    	gethostname(hostname, 1024);
	
	/* Print hostname to the screen */
	printf("%s\n", hostname);

    	/* Success return code */
	return 0;
}
