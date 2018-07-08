/* Header files 
   stdio.h - for output
   sys/types.h, sys/socket.h, netdb.h - For getaddrinfo			
   netinet/in.h, arpa/inet.h - For inet_ntoa */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Helper function */
int help() {

	/* Print supported options */
	printf("Usage: nslookup [OPTION]...\n");
	printf("Possible supported OPTION:\n");
	printf("\t<hostname>  \t\t Print IP address\n");
	printf("If wrong arguments are passed, default OPTION is -h\n");
	
	/* Exit with return code 1 */
	return 1;
}

/* Main Function */
int main(int argc, char *argv[]){

	/* Variables */
	struct addrinfo *a;
	char *hostname;
	char *hostaddress;
	struct sockaddr_in *s;
	int result;	

	/* assigning passed argument to hostname variable */
	hostname = argv[1];
	
	/* Get the address info only if the first argument is not NULL */
	if(argv[1] != NULL) {
	
		/* Definition of getaddrinfo: http://man7.org/linux/man-pages/man3/getaddrinfo.3.html */
		result = getaddrinfo(hostname, NULL, NULL, &a);
		if(result != 0) {
			return help();
		}

	} else {
		return help();

	}
	/* sockaddr_in reference: https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html */
	s = (struct sockaddr_in *) a->ai_addr;
  	hostaddress = inet_ntoa(s->sin_addr);

	/* Standard output */
	printf("Name: \t%s\n", hostname);
  	printf("Address: %s\n", hostaddress);

	/* cleaning up structure */
	freeaddrinfo(a);
	
	/* Success return code */
	return 0;
}


