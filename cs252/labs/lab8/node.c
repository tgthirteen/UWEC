#include "uwecSocket.h"

#include "uwecSocket.c"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>

#include <netdb.h>



int findPrime(int num);

int countPrimes(int lower, int upper);



int main() {

	

	int primeCount = 0;

	

	int portno = 7030;

	

	int client = callServer("localhost", portno);

	

	int low = readInt(client);

	int high = readInt(client);

	

	primeCount = countPrimes(low, high);

	

	writeInt(primeCount, client);

	

	close(client);



}



int findPrime(int num) {



	int check = 2;

	while (check < num) {

		if(num % check == 0){

			return 0;

		}

		check++;

	}

	return 1;



}



int countPrimes(int lower, int upper) {

	

	int primeCount = 0;

	int i;



	for(i = lower; i <= upper; i++) {

		if(findPrime(i) == 1){

			primeCount++;

		}

	}

	

	return primeCount;

}
