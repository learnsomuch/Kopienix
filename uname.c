/* Header files
   stdio.h - for standard output 
   utsname.h - for system name structure (reference: http://pubs.opengroup.org/onlinepubs/7908799/xsh/sysutsname.h.html) */
#include <stdio.h>
#include <sys/utsname.h>

/* Main function */
int main(void) {

	/* Initialize structure utsname with info */
	struct utsname info;
	uname(&info);

	/* Supported fields: sysname, release, version, machine, node and domain */
	printf("Name of Operating System: %s\n", info.sysname);
	printf("Linux kernel Release Number: %s\n", info.release);
	printf("Linux Kernel Version Level: %s\n", info.version);
	printf("Hardware Platform Info: %s\n", info.machine);
	
	/* Success return code */
	return 0;
}
