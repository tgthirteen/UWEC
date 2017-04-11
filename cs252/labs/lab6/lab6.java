public class lab6 implements Runnable{

  public static void main(String[] args) {
     
     int threadNum;
     int nThreads = 4;

     Thread[] theThreads = new Thread[nThreads];
    
     for(threadNum = 0; threadNum < nThreads; threadNum++){
        
     }  

     int lower = 10;
     int upper = 100;
     primesInRange(lower, upper);
  }

  public static int isPrime(int num){
  
    int i = 2;
    int prime = 1;

    while((prime == 1) && (i < num)){
    
      if(num % i == 0){
        prime = 0;
      }
  
     i++;
    
    }

    return prime;

  }

  public static void primesInRange(int low, int high){

    int i;
    int localPrimeCount = 0;

    for(i = low; i <= high; i++){
      if(isPrime(i) == 1){
        localPrimeCount++;
      }
    }  
    System.out.println("non-threaded primes in range = " + localPrimeCount);
  }

  public static void threadedPrimesInRange(int low, int high){
    
    int numOfThreads = 4;
    int range = high - low;
    //thread here
    int i;

    for(i = 0; i < numOfThreads; i++){
      int[] p = new int[100];
      p[0] = range;
      p[1] = numOfThreads;
      p[2] = i;
      //create thread
    }

    for(i = 0; i < numOfThreads; i++){
      //thread join
    }



  }
  
}
