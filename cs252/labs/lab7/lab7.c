#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<omp.h>

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



/*

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

*/



int blocking(int lower, int upper) {

	pthread_mutex_lock(&lock);

	primeCount = 0;

	pthread_mutex_unlock(&lock);

	int n = 5;

	int i;

	omp_set_num_threads(n);

	double startTotalTime = omp_get_wtime();

	printf("Blocking\n");

	#pragma omp parallel reduction(+: primeCount)

	{

		double startTime = omp_get_wtime();

		#pragma omp for nowait

			for(i = lower; i <= upper; i++) {

				if(isPrime(i)) {

					primeCount++;

				}

			}

			double endTime = omp_get_wtime();

			printf("time for %d: %f with %d found\n", omp_get_thread_num(), endTime - startTime, primeCount);

	}

	

	double endTotalTime = omp_get_wtime();

		

	printf("overall Time: %f with %d found\n", endTotalTime - startTotalTime, primeCount);

	

/* Test Code

	int n = 4;

	int i;

	omp_set_num_threads(n);

	#pragma omp parallel for

		for(i = lower; i <= upper; i++) {

			printf("%d: %d\n", omp_get_thread_num(), i);

		}

		

	sleep(1);

*/

/*

	omp_set_num_threads(4); //if !1 then gives the wrong answer

	int localPrimeCount = 0;

	int i;

	#pragma omp parallel for

	for(i = lower; i < upper; i++) {

		if(isPrime(i)) {

			localPrimeCount++;

		}

	}

	pthread_mutex_lock(&lock);

	primeCount += localPrimeCount;

	pthread_mutex_unlock(&lock);

	

	printf("\nThere are %d prime numbers in the range: %d - %d\n", primeCount, lower, upper);

	*/

}



int striping(int lower, int upper) {

	pthread_mutex_lock(&lock);

	primeCount = 0;

	pthread_mutex_unlock(&lock);

	int n = 5;

	int i;

	omp_set_num_threads(n);

	double startTotalTime = omp_get_wtime();

	printf("Striping\n");

	#pragma omp parallel reduction(+: primeCount)

	{

		double startTime = omp_get_wtime();

		#pragma omp for schedule(static, 1) nowait

			for(i = lower; i <= upper; i++) {

				if(isPrime(i)) {

					primeCount++;

				}

			}

			double endTime = omp_get_wtime();

			printf("time for %d: %f with %d found\n", omp_get_thread_num(), endTime - startTime, primeCount);

	}

	

	double endTotalTime = omp_get_wtime();

		

	printf("overall Time: %f with %d found\n", endTotalTime - startTotalTime, primeCount);

	

/* Test Code

	int n = 4;

	int i;

	omp_set_num_threads(n);

	#pragma omp parallel for schedule(static, 1)

		for(i = lower; i <= upper; i++) {

			printf("%d: %d\n", omp_get_thread_num(), i);

		}

		

	sleep(1);

*/

}



int main() {

	int nThreads = 1;

	lower = 0;

	upper = 0;

	printf("Lower Bound:\n");

	scanf("%d", &lower);

	

	printf("Upper Bound:\n");

	scanf("%d", &upper);

	

	pthread_mutex_init(&lock, NULL);

	

//	primesInRange(lower, upper);

//	threadedPrimesInRange(lower,upper);

	blocking(lower, upper);

	striping(lower, upper);



	pthread_mutex_unlock(&lock);



	

}
