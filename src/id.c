/* Header files
   pwd.h - https://www.mkssoftware.com/docs/man5/struct_passwd.5.asp
   grp.h - http://pubs.opengroup.org/onlinepubs/7908799/xsh/grp.h.html
   stdio.h - For output */
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: id [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t-a, --all \t\t Print all details\n");
	printf("\t-u, --user-id \t\t Print user id\n");
	printf("\t-g, --group-id \t\t Print group id\n");
	printf("\t-l, --login-name \t Print user login name\n");
	printf("\t-f, --full-name \t Print user full name\n");
	printf("\t-h, --help \t\t Print help information\n");
	printf("If no arguments are passed, default OPTION is -a\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}


/* Main Function */
int main(int argc, char *argv[]) {
	
	/* Variables */
  	/* Initialize passwd struct */
  	struct passwd *pw;
	/* Initialize group struct */
	struct group *gp;

  	/* uid_t numerical user ID */
  	uid_t uid;
	uid_t gid;	

  	/* Get uid */
  	uid = geteuid();
	
  	/* get passwd uid */
  	pw = getpwuid(uid);

	/* Get group struct based on the pw_gid */
        gp = getgrgid(pw->pw_gid);

	if((argv[1] == NULL) || ((strcmp("-a", argv[1]) == 0) || (strcmp("--all", argv[1]) == 0))) {

		/* Default print - uid with uid number and user, group id with username */
		printf("uid=%d(%s), gid=%d(%s)\n", pw->pw_uid, pw->pw_name, pw->pw_gid, gp->gr_name);

	} else if((strcmp("-f", argv[1]) == 0) || (strcmp("--full-name", argv[1]) == 0)){
		
		/* Print full name */
		printf("Full Name: %s\n", pw->pw_gecos);
	
	} else if((strcmp("-g", argv[1]) == 0) || (strcmp("--group-id", argv[1]) == 0)) {
		
		/* Print group id */
		printf("Group id: %d\n", pw->pw_gid);

	} else if((strcmp("-u", argv[1]) == 0) || (strcmp("--user-id", argv[1]) == 0)) {
		
		/* Print user id */
		printf("User id: %d\n", pw->pw_uid);

	} else if((strcmp("-l", argv[1]) == 0) || (strcmp("--login-name", argv[1]) == 0)) {
		
		/* Print user login name */
		printf("Login Name: %s\n", pw->pw_name);
	
	} else if((strcmp("-h", argv[1]) == 0) || (strcmp("--help", argv[1]) == 0)) {
 
		/* For all other cases, return help */
		return help();

	} else {

		/* For all other cases, return help */
		return help();

	}

  	/* Success return code */
  	return 0;
}
