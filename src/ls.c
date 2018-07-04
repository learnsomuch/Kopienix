/* Header files
   stdio.h for output
   dirent.h is for directory related topics */
#include <stdio.h>
#include <dirent.h>

/* Pass empty args with no return code */
void main(){

	/* Variables */ 
	struct dirent *d = NULL;

	/* Opens directory in current location */	
	DIR *di = opendir(".");

	/* if directory is not null */
	while((d = readdir(di)) != NULL) {
		
		/* Check if the directory has . or .. then do nothing else print details */
		if((strcmp(d->d_name, ".") == 0) || (strcmp(d->d_name, "..") == 0)) {
			// Do nothing	
		} else {
			printf("%s\n", d->d_name);
		}
	}

	/* close the opened directory */
	closedir(di);
}
