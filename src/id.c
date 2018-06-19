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

  	/* Check if pw is not null */
  	if (pw != NULL) {
        	/* Fetch pw_uid, pw_name and gid from struct of pw */
		printf("uid=%d(%s), gid=%d(%s)\n", pw->pw_uid, pw->pw_name, pw->pw_gid, pw->pw_name);
  	}
  
  	/* Success return code */
  	return 0;
}
