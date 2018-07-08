/* Header files 
   stdio.h - for output
			*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Main Function */
int main(int argc, char *argv[]){

	/* Variables */
	struct addrinfo *a;
	char *hostname;
	char *hostaddress;
	struct sockaddr_in *s;
	
	hostname = argv[1];
	
	/* Get the address info only if the first argument is not NULL */
	if(argv[1] != NULL) {
	
		/* Definition of getaddrinfo: http://man7.org/linux/man-pages/man3/getaddrinfo.3.html */
		getaddrinfo(hostname, NULL, NULL, &a);
	}

	/* sockaddr_in reference: https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html */
	s = (struct sockaddr_in *) a->ai_addr;
  	hostaddress = inet_ntoa(s->sin_addr);

	printf("Name: \t%s\n", hostname);
  	printf("Address: %s\n", hostaddress);

	return 0;
}


