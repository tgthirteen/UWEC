#include <stdio.h>

#include <string.h>

#include <math.h>



typedef union intU {

  unsigned int i;

  int theInt;

} intU;



void displayInt(int theInt) { 

  int i;

  intU fee;

  fee.theInt = theInt;

  

  for(i = 31; i >= 0; i--) {

    fee.i = fee.i >> i;

    printf("%d", fee.i & 1);

    fee.theInt = theInt;

    if (i == 31 || i == 23) {

      printf(" ");

    }

  }

  printf("\n");

}



int makeInt(char* f) { 

  intU fee;

  fee.i = 0;

  int i = 0;

  int len = strlen(f);

  int dec = 0;

  

  for(i = 0; i < len; i++) {

    if(f[i] == '1') {

      dec += (int)pow(2, len - i - 1);

    }

  }
  
  if (f[0] == '-'){
    dec = -dec;
  }

  printf("%d\n", dec);

  return dec;

}



int main() {

  intU fee;

  fee.theInt = 5;
  
  displayInt(fee.theInt);

  displayInt(-9);

  fee.theInt = makeInt("+101");

  fee.theInt = makeInt("-1001");

}
