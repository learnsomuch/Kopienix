/* Header files
   stdio.h - for standard output 
   utsname.h - for system name structure (reference: http://pubs.opengroup.org/onlinepubs/7908799/xsh/sysutsname.h.html) */
#include <stdio.h>
#include <sys/utsname.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: uname [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t-s, --kernel-name \t Print kernel/operating system name\n"); 
	printf("\t-a, --all \t\t Print OS, Kernel release and version, Hardware information\n");
	printf("\t-h, --help \t\t Print help information\n");
	printf("If no arguments are passed, default OPTION is -s\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* Main function */
int main(int argc, char *argv[]) {

	/* Initialize structure utsname with info */
	struct utsname info;
	uname(&info);

	/* To check if number of arguments is less than 2 and if it matches switches  */
	if( ( argc < 2 ) || ( (strcmp("-s", argv[1]) == 0 ) || (strcmp("--kernel-name", argv[1]) == 0 ) ) ){	

		/* For -s or --kernel-name switches in argument 1, print only the name of operating system */
			printf("%s\n", info.sysname);
			
	} else if( (strcmp("-a", argv[1]) == 0 ) || (strcmp("--all", argv[1]) == 0 ) ){

		/* For -a or --all switches in argument 1, return these Supported fields */
		/* Supported fields: sysname, release, version, machine, node and domain */
		printf("Name of Operating System: %s\n", info.sysname);
		printf("Linux kernel Release Number: %s\n", info.release);
		printf("Linux Kernel Version Level: %s\n", info.version);
		printf("Hardware Platform Info: %s\n", info.machine);
	} else if( (strcmp("-h", argv[1]) == 0 ) || (strcmp("--help", argv[1]) == 0 ) ) {
		
		/* For -h or --help switches in argument 1, return help */
		return help();
	} else {
		
		/* For all other cases, return help */
		return help();
	}
	/* Success return code */
	return 0;
}
