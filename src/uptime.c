/* Header Files 
   stdio.h - For output 
   sys/sysinfo.h - For system information such as load */
#include <stdio.h>
#include <sys/sysinfo.h>

/* Main Function */
int main() {

	/* Variables
	   Reference: http://man7.org/linux/man-pages/man2/sysinfo.2.html */
	struct sysinfo sinfo;
	int days, hours, mins;

	
	if(sysinfo(&sinfo) == 0) {
	
		/* Converstions to readable format */
		days = sinfo.uptime / 86400;
  		hours = (sinfo.uptime / 3600) - (days * 24);
  		mins = (sinfo.uptime / 60) - (days * 1440) - (hours * 60);

		/* Print details to screen */
		printf("Uptime: %u days, %dhours, %dminutes, %ldseconds\n", days, hours, mins, sinfo.uptime % 60);

		/* Success return code */
		return 0;	

	} else {
	
		/* Fault return code */	
		return 1;
	}
}
