/* Header files
   pwd.h - https://www.mkssoftware.com/docs/man5/struct_passwd.5.asp
   stdio.h - For output */
#include <stdio.h>
#include <pwd.h>

/* Main Function */
int main(int argc, char *argv[]) {
	
	/* Variables */
  	/* initialize passwd struct */
  	struct passwd *pw;
  	/* uid_t numerical user ID */
  	uid_t uid;

  	/* Get uid */
  	uid = geteuid();

  	/* get passwd uid */
  	pw = getpwuid(uid);

	if(argv[1] == NULL) {

		/* Default print - uid with uid number and user, group id with username */
		printf("uid=%d(%s), gid=%d(%s)\n", pw->pw_uid, pw->pw_name, pw->pw_gid, pw->pw_name);

	} else if((strcmp("-f", argv[1]) == 0) || (strcmp("--full-name", argv[1]) == 0)){
		
		/* Print full name */
		printf("Full Name: %s\n", pw->pw_gecos);
	
	} else if((strcmp("-g", argv[1]) == 0) || (strcmp("--group-id", argv[1]) == 0)) {
		
		/* Print group id */
		printf("Group id: %d\n", pw->pw_gid);

	} else if((strcmp("-u", argv[1]) == 0) || (strcmp("--user-id", argv[1]) == 0)) {
		
		/* Print user id */
		printf("User id: %d\n", pw->pw_uid);

	}else if((strcmp("-l", argv[1]) == 0) || (strcmp("--login-name", argv[1]) == 0)) {
		
		/* Print user login name */
		printf("Login Name: %s\n", pw->pw_name);
	}
 
  	/* Success return code */
  	return 0;
}
