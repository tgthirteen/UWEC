#include<stdio.h>
#include "hcompress.h"
#include "linkedlist.c"

tnode* GenerateFreqTable(int* size){
 
  int charPointer = 0;
  int i = 0;
  tnode* letters  = (tnode*)malloc(100*sizeof(tnode*));
  tnode tempLetter (tnode)malloc(100*sizeof(tnode));
  tnode* tempArray;

  while(scanf("%c",tempLetter) != EOF){

  tempArray = (tnode*)malloc(100*sizeof(tnode));
  int x;

  for(x=0; x < strlen(tempLetter); x++){
    tempArray[x] = tempLetter[x];
  }
 
  letters[i] = tempArray;
  (*size)++;
  i++;
  }
 
  tempArray = (tnode*)malloc(100*sizeof(tnode));
  int x;

  for(x=0; x < strlen(tempWord); x++){
     tempArray[x] = tempArray[x];
  }

  letters[i] = tempArray;

  free(tempLetter);
  free(tempArray);
  
  //calculate frequencies

  tnode* heapArray = (tnode*)malloc(100*sizeof(tnode*));
  heapArray[0].c =  letters[0];
  heapArray[0].weight = 1;

  int i = 0;
  int k = 0;
  int letter = 0;
  int count = 1;
  int contains;

  for (i = 1; i < *size; i++) {

  contains = 0;

     for(k = 0; k < count; k++) {

    if(!strcmp(letters[i],heapArray[k].c)) {

    contains = 1;

    (heapArray[k]).weight++;

  }

     }

  if(!contains) {

  heapArray[count].c = letters[i];

  heapArray[count].weight = 1;

  count++;

  }

}

 *letters  = heapArray;

  return count;




}

tnode* CreateHuffmanTree(tnode** letters){


//place nodes in order


//create temporary tree
tnode* tempArray = treeCreate();

for(int i = 0; i < &size; i++){

  add_in_order(&tempArray, letters[i]);

}


//repeatedly combine 2 smallest nodes

while(&size > 1){

  for(int i = 0; i < &size; i++){
    tnode newNode = tempArray[i] + tempArray[i+1]
    *size--;
  }

}
return tempArray[0];
}

int EncodeFile(char* filename, tnode* leafNodes){
   
   FILE *fptr;

   fptr = fopen(filename, "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }


 //while
   
    //what is written to the file
   
 
  strncat(filename, ".huf");
  
  fclose(fptr);

   return 0;

}

int DecodeFile(char* filename, tnode* treeRoot){

   FILE *fptr;

   fptr = fopen(filename, "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
    
    //what is written to the file  
   


   strncat(filename, ".txt");

   fclose(fptr);

   return 0;

}




//Main Method For Testing

int main(int argc, char *argv[]) {
 // Check the make sure the input parameters are correct
 if (argc != 3) {
 printf("Error: The correct format is \"hcompress -e filename\" or
\"hcompress -d filename.huf\"\n"); fflush(stdout);
 exit(1);
 }
 // Create the frequency table by reading the generic file
 struct tnode* leafNodes = GenerateFreqTable("decind.txt");
 // Create the huffman tree from the frequency table
 struct tnode* treeRoot = createHuffmanTree(leafNodes);

 // encode
 if (strcmp(argv[1], "-e") == 0) {
 // Pass the leafNodes since it will process bottom up
 encodeFile(argv[2], leafNodes);

 } else { // decode
 // Pass the tree root since it will process top down
 decodeFile(argv[2], treeRoot);
 }
 return 0;
}
