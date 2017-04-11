#include <iostream>
#include <stdio.h>
#include "Rectangle.h"


int main(){

return 0;

}



Rectangle :: Rectangle(const int l, const int r, const int t, const int b)
 : left(l), right(r), top(t), bot(b) 
{}

//setters

void Rectangle :: setLeft(const int l){
  
   left = l;

}
void Rectangle :: setRight(const int r){
  
   right = r;

}
void Rectangle :: setTop(const int t){
  
   top = t;

}
void Rectangle :: setBot(const int b){
  
   bot = b;

}

//getters

int Rectangle :: getLeft(){
  return left;
}
int Rectangle :: getRight(){
  return right;
}
int Rectangle :: getTop(){
  return top;
}
int Rectangle :: getBot(){
  return bot;
}
int Rectangle :: getWidth(int left, int right){
  int width = right - left;
  return width;
}
int Rectangle :: getHeight(int top, int bot){
  int height = top - bot;
  return height;
}


//misc methods


bool Rectangle :: contains(int x, int y){
  bool contains;
  if(x < right && x > left && y < top && y > bot){
     contains = true;
  }
  else{
     contains = false;
  }

  return contains;

}

bool Rectangle :: intersects(const Rectangle()){

}
