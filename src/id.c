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
	printf("\t<username> \t\t Provide username to get that specific user id details\n");
	printf("\t-a, --all \t\t Print all details\n");
	printf("\t-u, --user \t\t Print user details\n");
	printf("\t-g, --group \t\t Print group details\n");
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
	long buflen = 1024;
  	char buf[buflen];
  	/* Initialize passwd struct where p and *pwr is used for getpwnam_r */
  	struct passwd p, *pw, *pwr;
	/* Initialize group struct */
	struct group *gp;

  	/* uid_t numerical user ID */
  	uid_t uid;
	uid_t gid;	

  	/* Get uid */
  	uid = geteuid();
	
	if(argv[1] != NULL) {

		/* Reference: https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_71/apis/gtpwnamr.htm
		   First argument is a pointer to user profile name, p is a pointer to passwd structure, buf is pointer to buffer, buflen is size of buffer and pwr is the result pointer to a location */
		getpwnam_r(argv[1], &p, buf, buflen, &pwr);
	}

  	/* get passwd uid */
  	pw = getpwuid(uid);

	/* Get group struct based on the pw_gid */
        gp = getgrgid(pw->pw_gid);

	if((argv[1] == NULL) || ((strcmp("-a", argv[1]) == 0) || (strcmp("--all", argv[1]) == 0))) {

		/* Default print - uid with uid number and user, group id with username */
		printf("uid=%d(%s), gid=%d(%s), full-name=%s\n", pw->pw_uid, pw->pw_name, pw->pw_gid, gp->gr_name, pw->pw_gecos);

	} else if((strcmp("-f", argv[1]) == 0) || (strcmp("--full-name", argv[1]) == 0)){
		
		/* Print full name */
		printf("Full Name: %s\n", pw->pw_gecos);
	
	} else if((strcmp("-g", argv[1]) == 0) || (strcmp("--group", argv[1]) == 0)) {
		
		/* Print group details */
		printf("Group id: %d\n", pw->pw_gid);
		printf("Group name: %s\n", gp->gr_name);

	} else if((strcmp("-u", argv[1]) == 0) || (strcmp("--user", argv[1]) == 0)) {
		
		/* Print user details */
		printf("User id: %d\n", pw->pw_uid);
		printf("User name: %s\n", pw->pw_name);

	} else if((strcmp("-l", argv[1]) == 0) || (strcmp("--login-name", argv[1]) == 0)) {
		
		/* Print user login name */
		printf("Login Name: %s\n", pw->pw_name);
	
	} else if((strcmp("-h", argv[1]) == 0) || (strcmp("--help", argv[1]) == 0)) {

                /* For all other cases, return help */
                return help();

	} else if((argv[1] != NULL) && (pwr != NULL)) {
	
		/* To validate first argument for username */
		printf("Username: %s\nUser ID: %u\nGroup ID: %u\nInitial dir: %s\n", pwr->pw_name, pwr->pw_uid, pwr->pw_gid, pwr->pw_dir);
	
	} else {
		
		/* For all other cases, return help */
		return help();

	}

  	/* Success return code */
  	return 0;
}
