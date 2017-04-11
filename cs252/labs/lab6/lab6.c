#include<stdio.h>

#include<stdlib.h>

#include<pthread.h>



int primeCount = 0;

int upper;

int lower;

pthread_mutex_t lock;



int isPrime(int num) {

  int i = 2;

  int prime = 1; 

  while(prime && i < num) {

    if(num % i == 0) {

      prime = 0; 

    }

    i++;

  }



  return prime;

}



void* primesInRange(int low, int high) {

  int i;

  int localPrimeCount = 0;

  for(i = low; i <= high; i++) {

    if(isPrime(i)) {

      localPrimeCount++;

    }

  }

  printf("non-threaded primes in range = %d\n", localPrimeCount);

}



void* primesInRangeThread(void* p) {

  int i;

  int* pp = (int*)p;

  int range = pp[0];

  int numOfThreads = pp[1];

  int threadNum = pp[2];

  int localPrimeCount = 0;

  

  int low = ((range/numOfThreads*threadNum) + lower);

  int high = ((range/numOfThreads*(threadNum+1)) + lower);



  

  for(i = low; i <= high; i++) {

    if(isPrime(i)) {

      localPrimeCount++;

    }

  }

  

  pthread_mutex_lock(&lock);

  primeCount += localPrimeCount;

  pthread_mutex_unlock(&lock);

  

  printf("threaded localPrimeCount = %d\n", localPrimeCount);

  return NULL;

}



int threadedPrimesInRange(int low, int high) {

  int numOfThreads = 4;

  int range = high - low;

  pthread_t id[numOfThreads];

  int i;

  for(i = 0; i < numOfThreads; i++) {

    int* p = (int*)malloc(3*sizeof(int));

    p[0] = range;

    p[1] = numOfThreads;

    p[2] = i;

    pthread_create(&(id[i]), NULL, primesInRangeThread, (void*)p);

    

  }

  

  for(i = 0; i <numOfThreads; i++) {

    pthread_join(id[i], NULL);

  }

  

  printf("final threaded primeCount = %d\n", primeCount);

}



int main() {

  lower = 1000;

  upper = 1000000;

  

  pthread_mutex_init(&lock, NULL);

  

 // primesInRange(lower, upper);

  threadedPrimesInRange(lower,upper);

  

  pthread_mutex_destroy(&lock);

}
