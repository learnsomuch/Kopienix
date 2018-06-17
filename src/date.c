
/* Headers
   time.h is included to support time_t datatype 
   stdio.h is included to support output. In this case, time */
#include <time.h>
#include <stdio.h>

/* Main function with integer return code */
int main(void) {
	
	/* Variables with initialized values */
	/* Get the current local time */
	time_t t = time(NULL);

	/* Return string with time as argument. In this case, &t is datatype of time_t */
	char * string_time = ctime(&t);
	
	/* Print results on screen */
	printf("%s",string_time);

	/* Success return code */
	return 0;

}
