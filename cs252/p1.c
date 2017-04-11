#include <stdio.h>

int main() {
  
  int size = 5;
  int a[size];
 
  int b = 1;
  int c = 2;

  a[0]= 5;
  a[1]= 2;
  a[5]= 8;

 // printf("%d %d %d\n", a[0], b, sizeof(c));

  // int d 

 // printf("%p %p %p \n", &c, &b, &a );

  int* d = &c;
 
  *(d+4) = 9;

  *(a+1) = 6;

 printf("%d \n" , a[1]);

 // printf("%p %p \n", b, &a[0]); 

  return 0;
}
