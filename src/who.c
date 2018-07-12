/* Header files 
   stdio.h - for output
   utmp.h - to read current session */
#include <stdio.h>
#include<utmp.h>
#include<sys/utsname.h>

int main(void) {

	/* Variables */
	struct utmp *utmp_details;
	
	/* Set utmp file position to begining - Reference: https://linux.die.net/man/3/setutent */
	setutent();
	/* Read line from current position of utmp file */
	utmp_details = getutent();

	while(utmp_details) {
		
		/* Check if ut_type from the utmp_details matches to USER_PROCESS or LOGIN_PROCESS */
		if(utmp_details->ut_type == USER_PROCESS) {
	
			/* Print details to screen */
			printf("%s %s (%s)\n", utmp_details->ut_user, utmp_details->ut_line, utmp_details->ut_host);
		} 

		/* For Adjustment - to next position of utmp file */
		utmp_details = getutent();
	}

	/* Success return code */
	return 0;
}
