#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

//creation of tree node

typedef struct tnode{

  double weight;
  int c;
  struct tnode* left;
  struct tnode* right;
  struct tnode* parent;

}tnode;


tnode* treeCreate();

void treeDisplay(tnode* tree);


void treeAdd(tnode** tree, int value);


void list_add_in_order(tnode** tree, int value);


#endif
