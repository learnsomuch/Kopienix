/* Header files
   stdio.h for output
   dirent.h is for directory related topics
   unistd.h - for access() 
   sys/stat.h - for size of file */
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

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

/* Main Function */
int main(int argc, char *argv[]) {

	/* Variables */ 
	struct dirent *d = NULL;
	struct stat s;
	
	int count = NULL;
	
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
				printf(" %zu ", s.st_size);
	
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
