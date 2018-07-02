/* Header files
   stdio.h for output
   dirent.h is for directory related topics */
#include <stdio.h>
#include <dirent.h>

void main(){
	/* Variables */ 
	struct dirent *d = NULL;
	
	DIR *di = opendir(".");

	while(d = readdir(di)) {
		printf("%s\n", d->d_name);
	}
}
