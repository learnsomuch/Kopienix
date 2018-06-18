/* Header files
   stdio.h - For output of whoami command
   pwd.h - For passwd structure with uid_t and for struct passwd */
#include <stdio.h>
#include <pwd.h>

/* Main Function */
int main(int argc, char *argv[])
{
  /* Variables */
  /* initialize passwd struct */
  struct passwd *password;
  /* uid_t numerical user ID */
  uid_t uid;

  /* Get uid */
  uid = geteuid();

  /* get passwd uid */
  password = getpwuid(uid);

  /* Check if password is not null */
  if (password != NULL) {
        /* Fetch pw_name from struct of password */
	printf("%s", password->pw_name);
  }
  
  /* Success return code */
  return 0;
}
