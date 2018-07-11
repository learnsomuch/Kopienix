/* Header Files 
   stdio.h - For output 
   sys/sysinfo.h - For system information such as load
   time.h - for time and ctime */
#include <stdio.h>
#include <sys/sysinfo.h>
#include <time.h>

/* Main Function */
int main() {

	/* Variables
	   Reference: http://man7.org/linux/man-pages/man2/sysinfo.2.html */
	struct sysinfo sinfo;
	int days, hours, mins;
	time_t t = time(NULL);

        /* Return struct. In this case, &t is datatype of time_t. Reference to localtime and struct tm: http://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html */
        struct tm *string_time = localtime(&t);

	if(sysinfo(&sinfo) == 0) {
	
		/* Converstions to readable format */
		days = sinfo.uptime / 86400;
  		hours = (sinfo.uptime / 3600) - (days * 24);
  		mins = (sinfo.uptime / 60) - (days * 1440) - (hours * 60);

		/* Print details to screen */
		printf("%02d:%02d:%02d up %u days, %dh:%dm:%lds\n",string_time->tm_hour, string_time->tm_min, string_time->tm_sec, days, hours, mins, sinfo.uptime % 60);

		/* Success return code */
		return 0;	

	} else {
	
		/* Fault return code */	
		return 1;
	}
}
