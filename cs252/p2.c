#include <stdio.h>
#include <stdlib.h>

void test1(int* y ) {
  printf("%d\n", y*);

  *y = 3;

  printf("%d\n", *y);
}

int main() {

  int* x = 5;
  
  test1(&x);
 
  printf("%p\n", x);  

}
