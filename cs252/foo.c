#include <stdio.h>

int xyz() {
 
 printf("in func\n");

}


int main(){

  xyz();

  int x;
  int y;

  y=12;
  x=5; 

  int r = x * 5;
	
  char a = 'p';

  double z=5.8;
	
  printf("My numbers are %d,%d,and %lf ... %c \n",x,y,z,a);
  
  printf("%d \n",r);

  if (x) {
   printf("hi\n");
  } 
  else {
   printf("bye\n");
  } 

  return 0;

}
