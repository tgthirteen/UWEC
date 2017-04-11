#include <stdio.h>


typedef struct freq {
  int value;
  int frequency;
}histogram;


void readScores(int* scores, int* size);
void displayScores(int* scores, int size);
void calcHistogram(histogram* f, int* count, int* scores, int size);
void displayHistogram(histogram* f, int count);
void sortHistogram(histogram* f, int* count);


int main(){

 int count = 0;
 int size = 0;
 int scores[100];
 histogram f[100];
 readScores(scores, &size);
 displayScores(scores, size);
 calcHistogram(f, &count, scores, size);
 displayHistogram(f, count);
 sortHistogram(f, &count);
 displayHistogram(f, count);
}

void readScores(int* scores, int* size){
 
  int i = 0;


  while(scanf("%d", (scores+i)) != EOF){ 
  (*size)++;
  i++;
  }

};


void displayScores(int* scores, int size){

  for(int i = 0; i < size; i++){
    printf("score %d: %d\n",i, *(scores+i));
  }
}

void calcHistogram(struct freq* f, int* count, int* scores, int size){

  int i = 0;
  int j = 0;
  int score = 0;
  *count = 0;

  for(int i = 0; i < size; i++){

   while(j < (*count) && ((*(f+j)).value) != (*(scores + i))){
      j++;
   }  
   if( j < *count){
     ((*(f+j)).frequency)++;
   }         
   else{
     ((*(f+j)).value) = (*(scores + i));
     ((*(f+j)).frequency) = 1;
     (*count)++;
   }
   j = 0;
  }
}
 


void displayHistogram(histogram* f, int count){

   for(int i = 0; i < count;  i++){
      printf("Score: %d , Frequency: %d\n", ((*(f+i)).value) ,((*(f+i)).frequency));
   }

}

void sortHistogram(histogram* f, int* count){
 
  int i;
  int j;
  int temp = 0;
 
  for(int i = 0; i < (*count); i++){
     for( j = i; j < (*count); j++){
       if(((*(f + j)).frequency) > ((*(f + i)).frequency)){
          temp = ((*(f + j)).frequency);
          ((*(f + j)).frequency) = ((*(f +i)).frequency);
          ((*(f + i)).frequency) = temp; 
          temp = ((*(f + j)).value);
          ((*(f + j)).value) = ((*(f + i)).value);
          ((*(f + i)).value) = temp;
       }
     }
   }

}
