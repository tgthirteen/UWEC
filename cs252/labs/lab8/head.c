#include "uwecSocket.h"

#include "uwecSocket.c"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>

#include <netdb.h>

#include <omp.h>



int main() {

	

	omp_set_num_threads(4);

	

	int min = 10;

	int max = 1000000;

	int portno = 7030;

	int i = 0;

	int numOfNodes = 4;

	int primes[numOfNodes];

	int primeCount = 0;

	int clients[numOfNodes];

	

	int server = setupServerSocket(portno);

	

	for(i = 0; i < numOfNodes; i++) {

		int client = serverSocketAccept(server);

		clients[i] = client;

	}

	

	#pragma omp parallel for schedule(static, 1)

	for(i = 0; i < numOfNodes; i++) {

	

		int low = (int)(((max - min)/numOfNodes*i) + min);

		int high = (int)(((max - min)/numOfNodes*(i+1)) + min);

	

		writeInt(low, clients[i]);

		writeInt(high, clients[i]);

	

		primes[i] = readInt(clients[i]);

	

		printf("Node %d counted from %d to %d and got %d primes\n", i, low, high, primes[i]);

	

	}

	

	for(i = 0; i < numOfNodes; i++) {

		primeCount += primes[i];

	}

	

	printf("Total primes: %d\n", primeCount);

	

	close(server);

	

}
