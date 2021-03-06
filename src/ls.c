/* Header files
   stdio.h - for output
   dirent.h - for directory related topics
   unistd.h - for access() 
   sys/stat.h - for size of file 
   pwd.h - for structure of type passwd
   grp.h - for group struct */
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: ls [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t-a, --all \t\t Print all list of files\n");
	printf("\t-c, --count \t\t Print number of files in directory\n");
	printf("\t-h, --help \t\t Print help information\n");
	printf("If no arguments are passed, default OPTION is -a\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* Last modified data in a file or directory */
char *mdate(char *string, time_t value)
{
        strftime(string, 36, "%b %d %H:%M", localtime(&value));
        return string;
}

/* Main Function */
int main(int argc, char *argv[]) {

	/* Variables */ 
	struct dirent *d = NULL;
	struct stat s;
	struct passwd *pw;
	struct group *gr;	

	int count = NULL;

	int days, hours, mins;
	char date[36];

	/* Opens directory in current location */	
	DIR *di = opendir(".");

	/* if directory is not null */
	while((d = readdir(di)) != NULL) {
		
		/* Check if the directory has . or .. then do nothing else print details */
		if((strcmp(d->d_name, ".") == 0) || (strcmp(d->d_name, "..") == 0)) {
			// Do nothing	
		} else {

			if((argv[1] == NULL) || ((strcmp("-a", argv[1]) == 0) || (strcmp("--all", argv[1]) == 0))) {
				
				/* Permission */
				/* - for file, d for directory, l for link */

				if(d->d_type == DT_REG) {
					printf("-");
				} else if(d->d_type == DT_DIR) {
					printf("d");
				} else if(d->d_type == DT_LNK) {
					printf("l");
				}
				
				/* read r, write w, execute x */
				if(access(d->d_name, R_OK) != -1) {
					printf("r");
				} else {
					printf("-");
				}
 
				if(access(d->d_name, W_OK) != -1) {
					printf("w");
				} else {
					printf("-");
				}

				if(access(d->d_name, X_OK) != -1) {
					printf("x");
				} else {
					printf("-");
				}

				/* PENDING: read r, write w, execute x for members of group owning file;
                                     read r, write w, execute x for other users; */

				/* Size of file using stat struct */
				stat(d->d_name, &s);
				/* get user and group data via struct's */
				pw = getpwuid(s.st_uid);
				gr = getgrgid(s.st_gid);

				printf(" %zu ", s.st_nlink);
				/* Print username and group name of the file */
				printf(" %s ", pw->pw_name);
				printf(" %s ", gr->gr_name);
			
				char str[10];
				memset(str, ' ', sizeof(str));	
				int i;
				//for(i = 0; i <= sizeof(s.st_size); i++) { 
				/* Print size of the file */
				printf(" %*s%zu ", 1, "", s.st_size);
				//}
				
				printf(" %s ", mdate(date, s.st_mtime));

				/* Print the actual file name */
				if(d->d_type == DT_DIR) {
					printf("   %s/\n", d->d_name);
				} else {
					printf("   %s\n", d->d_name);
				}
			}
			count++;
		}	
	}
	
	if((argv[1] == NULL) || ((strcmp("-a", argv[1]) == 0) || (strcmp("--all", argv[1]) == 0))) {
	
		//Do nothing
	
	} else if((strcmp("-c", argv[1]) == 0) || (strcmp("--count", argv[1]) == 0)) {

		/* Print the number of files */
		printf("Number of files in the directory: %u\n", count);

	} else if((strcmp("-h", argv[1]) == 0) || (strcmp("--help", argv[1]) == 0)) {

		/* For all other cases, return help */
                return help();
	} else {

		return help();
	}

	/* close the opened directory */
	closedir(di);

	/* Success return code */
  	return 0;
}
