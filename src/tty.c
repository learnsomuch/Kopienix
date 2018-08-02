/* Header files
   stdio.h - for output and input
   unistd.h - for isatty */ 
#include <stdio.h>
#include <unistd.h>

/* Main Function */
int main() {

	/* Reference: https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/qnx/ttyname.html */
	if(isatty(0)) {
        	
		printf("%s\n", ttyname(0));
    	}

	/* Success return code */
	return 0;
}
