#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct freq {
  char* word;
  int frequency;
}histogram;

char** readWords(int* size);
void displayWords(char** words, int size);
int  calcHistogram(char** words, int* size, histogram** f);
void displayHistogram(histogram* f, int* count);
void sortHistogram(histogram* f, int* count);


int main(){

 int count = 0;
 int size = 0;

 char** words  = readWords(&size);

 histogram* f;
 
 displayWords(words, size);
 count = calcHistogram(words, &size, &f);
 displayHistogram(f,&count);
 sortHistogram(f,&count);
 displayHistogram(f, &count);

 int i;
 for(int i = 0; i < size; i++){
   free(words[i]);
 }

 free(words);
 free(f);
}

char** readWords(int* size){
 
  int scorePointer = 0;
  int i = 0;
  char** words = (char**)malloc(100*sizeof(char*));
  char* tempWord = (char*)malloc(100*sizeof(char*));
  char* tempArray;

  while(scanf("%s",tempWord) != EOF){

  tempArray = (char*)malloc(100*sizeof(char));
  int x;

  for(x=0; x < strlen(tempWord); x++){
    tempArray[x] = tempWord[x];
  }
 
  words[i] = tempArray;
  (*size)++;
  i++;
  }
 
  tempArray = (char*)malloc(100*sizeof(char));
  int x;

  for(x=0; x < strlen(tempWord); x++){
     tempArray[x] = tempArray[x];
  }

  words[i] = tempArray;

  free(tempWord);
  free(tempArray);
  return words;
};


void displayWords(char** words, int size){

  for(int i = 0; i < size; i++){
    printf("Word %d: %s\n",i, words[i]);
  }

}

int calcHistogram(char** words, int* size, histogram** f){


  histogram* heapArray = (histogram*)malloc(100*sizeof(histogram*));
  heapArray[0].word = words[0];
  heapArray[0].frequency = 1;

  int i = 0;
  int k = 0;
  int word = 0;
  int count = 1;
  int contains;

  for (i = 1; i < *size; i++) {

	contains = 0;

     for(k = 0; k < count; k++) {

		if(!strcmp(words[i],heapArray[k].word)) {

		contains = 1;

		(heapArray[k]).frequency++;

	}

     }

  if(!contains) {

	heapArray[count].word = words[i];

	heapArray[count].frequency = 1;

	count++;

  }

}

 *f  = heapArray;

  return count;

}
 


void displayHistogram(histogram* f, int* count){

  // printf("Test: %s\n", (f[1]).word);

   for(int i = 0; i < *count;  i++){
      printf("Word: %s , Frequency: %d\n", ((f[i]).word) ,((f[i]).frequency));
   }

}

void sortHistogram(histogram* f, int* count){
 
  int i;
  int j;
  char* tempW;
  int tempF;
 
  for(int i = 0; i < (*count); i++){
     for( j = i; j < (*count); j++){
       if(((f[j]).frequency) > ((f[i]).frequency)){
          tempF = ((f[j]).frequency);
          ((f[j]).frequency) = ((f[i]).frequency);
          ((f[i]).frequency) = tempF; 
          tempW = ((f[j]).word);
          ((f[j]).word) = ((f[i]).word);
          ((f[i]).word) = tempW;
       }
     }
   }

}
