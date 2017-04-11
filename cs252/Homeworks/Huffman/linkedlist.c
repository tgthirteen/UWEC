#include "linkedlist.h"

tnode* treeCreate() {
  return NULL;
}

void treeDisplay(tnode* tree) {

  tnode* p = tree;
  
  printf("[");

  while(p != NULL) {
   
    printf("%d, ", p->c);
    
    p = (*p).right;
  }

  printf("]\n");
}



void treeAdd(tnode** tree, int value) {
  printf("WAT");
  tnode* newTree = (tnode*)malloc(1 * sizeof(tnode));
  newTree->c = value;
  newTree->right = NULL;

  tnode* p = *tree;

  if (p != NULL) {
      
    while(p->right != NULL) {
      
      p = (*p).right;
    }

    p->right = newTree;

  } else {
    
    *tree = newTree;
  }
}


void add_in_order(tnode** tree, int value){

  tnode* newNode = (tnode*)malloc(1 * sizeof(tnode));
  newNode->c = value;
  tnode* p = *tree;

  
  //add based on weight
  if(p != NULL){ 
  
   tnode* nextNode = p->right;

  while(p->right != NULL){
     p = (*p).right;
  }

  printf("%d", p->c);
  printf("%d", newNode->c);

/*
  if(p->c >= newNode->c){
    
    nextNode = p;
    p->right = nextNode;
    p = nextNode;
    
  }
  */
  if(p->right == NULL){
    p->right = newNode;  
  }
  else{

     if(nextNode == NULL){
        printf("WAT1");
     }
     else{

      printf("WAT2");

      //while(nextNode->c <= value ){
          
       //  printf("WAT");
       //  p = (*p).right;

      // }
     }
  }
  
 }
 
 else {
    
   *tree = newNode;
     
   }

}



int main() {
  tnode* tree = treeCreate();

  treeDisplay(tree);

  printf("add 5\n");
  add_in_order(&tree, 5);
  treeDisplay(tree);


  printf("add 2\n");
  add_in_order(&tree, 2);
  treeDisplay(tree);


  printf("add 8\n");
  add_in_order(&tree, 8);
  treeDisplay(tree);

//  printf("add 6\n");
//  add_in_order(&tree, 6);
//  treeDisplay(tree);

  printf("add 12\n");
  add_in_order(&tree, 12);
  treeDisplay(tree);

  printf("add 40\n");
  add_in_order(&tree, 40);
   treeDisplay(tree);

}
