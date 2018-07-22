/* Header files
   stdio.h - to print output */
#include <stdio.h>

/* Main Function */
int main(int argc, char *argv[]) {

	/* Variables */
	int c, lines = 0;
	/* Open file in read mode */
	FILE *f = fopen(argv[1],"r");	

	/* loop file */
	while(!feof(f)) {

  		c = fgetc(f);
  		/* For every \n, count lines */
		if(c == '\n') {
    			lines++;
  		}
	}

	/* Print lines count */
	printf("%d", lines);

	/* Close file */
	fclose(f);

	/* Success return code */
	return 0;
}
