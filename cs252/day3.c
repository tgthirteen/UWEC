#include <stdio.h>
#include <string.h>


int main(){
 
  char s1[6];

  s1 [0] = 'h';
  s1 [1] = 'e';
  s1 [2] = 'l';
  s1 [3] = 'l';
  s1 [4] = 'o';
  s1 [5] = '\0'; 

  char* s2 = "hello";
 

  printf("%s\n" , s2);
  printf("%s\n", s1);

  if (strcmp(s1, s2) == 0){
   printf("Equal\n");
  }else{
   printf("Not Equal\n");
  }

  return 0;
}
