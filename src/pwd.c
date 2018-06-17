/* Header files
   unistd.h - standard symbolic constants and types
   stdio.h - For standard output */
#include <unistd.h>
#include <stdio.h>

/* Main Function */
int main() {

   /* Variables - initializing buf as char with size of FILENAME_MAX. FILENAME_MAX is defined in stdio.h */
   char buf[FILENAME_MAX];
	
   /* Using getcwd inbuildi where it takes buffer and its size - refer: http://pubs.opengroup.org/onlinepubs/9699919799/functions/getcwd.html */
   if (getcwd(buf, sizeof(buf)) != NULL) {
	printf("%s\n", buf);
   }
   return 0;
}
