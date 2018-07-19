/* Header files
   stdio.h - For output
   sys/sysinfo - for system information */
#include <stdio.h>
#include <sys/sysinfo.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: free [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t-b, --B \t\t Print memory details in bytes\n");
	printf("\t-k, --KB \t\t Print memory details in kilobytes\n");
	printf("\t-m, --MB \t\t Print memory details in megabytes\n");
	printf("\t-m, --GB \t\t Print memory details in gigabytes\n");
	printf("\t    --TB \t\t Print memory details in terabytes\n");
	printf("If no arguments are passed, default OPTION is -b\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* print to screen */
void screen(unsigned long tram, unsigned long fram, unsigned long sram, unsigned long bram, unsigned long tswap, unsigned long fswap) {

	printf("Memory Information\n");
	printf("******************\n");
	printf("total: %zu\n", tram);
	printf("used: %zu\n", tram - fram);
	printf("free: %zu\n", fram);
	printf("shared: %zu\n", sram);
	printf("buffers: %zu\n", bram); 
	printf("******************\n");
	printf("Swap Information\n");
	printf("total swap: %zu\n", tswap);
	printf("used swap: %zu\n", tswap - fswap);
	printf("free swap: %zu\n", fswap);
}

int main(int argc, char *argv[]) {

	/* Variables 
	   Reference: http://man7.org/linux/man-pages/man2/sysinfo.2.html */
	struct sysinfo sinfo;
	
	/* Convert to respective sizes */
	static unsigned long TB = 1024ul * 1024ul * 1024ul * 1024ul;
	static int GB = 1024 * 1024 * 1024;
  	static int MB = 1024 * 1024;
  	static int KB = 1024;

	unsigned long tram, fram, sram, bram, tswap, fswap;
				
	if(sysinfo(&sinfo) == 0) {
	
		/* Get data from sinfo */
		tram = sinfo.totalram;
		fram = sinfo.freeram;	
		sram = sinfo.sharedram;
		bram = sinfo.bufferram;
		tswap = sinfo.totalswap;
		fswap = sinfo.freeswap;	

		if((argv[1] == NULL) || ((strcmp("-b", argv[1]) == 0) || (strcmp("--B", argv[1]) == 0))) {	

			screen(tram, fram, sram, bram, tswap, fswap);	

		} else if((strcmp("-k", argv[1]) == 0) || (strcmp("--KB", argv[1]) == 0)) {
                        
                        tram = tram / KB;
			fram = fram / KB;
			sram = sram / KB;
			bram = bram / KB;
			tswap = tswap / KB;
			fswap = fswap / KB;

			screen(tram, fram, sram, bram, tswap, fswap);

                } else if((strcmp("-m", argv[1]) == 0) || (strcmp("--MB", argv[1]) == 0)) {
		
			tram = tram / MB;
			fram = fram / MB;
			sram = sram / MB;
                        bram = bram / MB;
			tswap = tswap / MB;
                        fswap = fswap / MB;

			screen(tram, fram, sram, bram, tswap, fswap);	

		} else if((strcmp("-g", argv[1]) == 0) || (strcmp("--GB", argv[1]) == 0)) {
                
		        tram = tram / GB;
			fram = fram / GB;
			sram = sram / GB;
                        bram = bram / GB;
			tswap = tswap / GB;
                        fswap = fswap / GB;

			screen(tram, fram, sram, bram, tswap, fswap);

		} else if(strcmp("--TB", argv[1]) == 0) {

                        tram = tram / TB;
			fram = fram / TB;
			sram = sram / TB;
                        bram = bram / TB;
			tswap = tswap / TB;
                        fswap = fswap / TB;

			screen(tram, fram, sram, bram, tswap, fswap);

                } else {

			return help();

		}
		
	}
	
	/* Success return code */
	return 0;
}
