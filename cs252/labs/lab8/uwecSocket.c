#include <stdio.h>

#include <stdlib.h>

#include "uwecSocket.h"

#include <string.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>

#include <netdb.h>



int setupServerSocket(int portno) {



  // Get a socket of the right type

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {

    printf("ERROR opening socket");

    exit(1);

  }

  

  // server address structure

  struct sockaddr_in serv_addr;

  

  // Set all the values in the server address to 0

  memset(&serv_addr, '0', sizeof(serv_addr)); 

  

    // Setup the type of socket (internet vs filesystem)

  serv_addr.sin_family = AF_INET;

  

   // Basically the machine we are on...

  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  

  // Setup the port number

  // htons - is host to network byte order

  // network byte order is most sig byte first

  //   which might be host or might not be

  serv_addr.sin_port = htons(portno);

  

  // Bind the socket to the given port

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {

    printf("ERROR on binding\n");

    exit(1);

  }

  

    // set it up to listen

  listen(sockfd,5);

	

	return sockfd;

}



int callServer(char* host, int portno) {



	// Socket pointer

  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {

    fprintf(stderr,"ERROR opening socket\n");

    exit(0);

  }



  // server address structure

  struct sockaddr_in serv_addr;



  // Set all the values in the server address to 0

  memset(&serv_addr, '0', sizeof(serv_addr)); 



  // Setup the type of socket (internet vs filesystem)

  serv_addr.sin_family = AF_INET;



   // Setup the port number

  // htons - is host to network byte order

  // network byte order is most sig byte first

  //   which might be host or might not be

  serv_addr.sin_port = htons(portno);





  // Setup the server host address

  struct hostent *server;

  server = gethostbyname("localhost");

  if (server == NULL) {

    fprintf(stderr,"ERROR, no such host\n");

    exit(0);

  }

  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);  /// dest, src, size

	

	  // Connect to the server

  if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {

    printf("ERROR connecting\n");

    exit(0);

  }

	

	return sockfd;

}



int serverSocketAccept(int serverSocket) {



	int newsockfd;

	struct sockaddr_in cli_addr;

	socklen_t clilen = sizeof(cli_addr);

  

	// Wait for a call

  newsockfd = accept(serverSocket, (struct sockaddr *) &cli_addr, &clilen);

  if (newsockfd < 0) {

    printf("ERROR on accept");

    exit(1);

  }

  

  return newsockfd;



}



void writeInt(int num, int socket){ 

   int n = write(socket, &num, sizeof(num));

   if (n < 0) {

    // printf("  ERROR -- Writing Integer to Socket Failed\n");

     exit(0);

   }

  // printf("Successfully Wrote %d to Socket %d\n", num, socket); 

  }



int readInt(int socket){

   int num = 0;

   int n = read(socket, &num, sizeof(num));

   if (n < 0) {

    // printf("  ERROR -- Reading Integer From Socket Failed\n");

     exit(1);

   }

  // printf("Successfully Read %d from Socket %d\n", num, socket); 

   return num;

 }
