#include <stdio.h>

#include <string.h>

#include <math.h>



typedef union floatU {

  unsigned int i;

  float f;

} floatU;



void displayFloat(float f) { 

  int i;

  floatU floatNum;

  floatNum.f = f;

  

  for(i = 31; i >= 0; i--) {

    floatNum.i = floatNum.i >> i;

    printf("%d", floatNum.i & 1);

    floatNum.f = f;

    if (i == 31 || i == 23) {

      printf(" ");

    }

  }

  printf("\n");

}



float makeFloat(char* f) { 

  int index = 1;

  floatU floatNum;

  floatNum.i = 0;

  int numsBeforeDec = 0;

  if (f[0] == '-') {

    floatNum.i |= 1 << (31);

  }

  

  unsigned char exponent;

  int i = 2;

  while(f[i] != '.') {

    i++;

    exponent++;

  }

  exponent += 127;

  floatNum.i |= exponent << (23);

  

  int current = 0;

  i = 22;

  while(i>=0) {

    if(current >= strlen(f)) {

      i--;

    } else {

      if(current > 1 && f[current] != '.') {

        if(f[current] == '1') {

          floatNum.i |= 1 << (i);

        }

        i--;

      }

    }

    current++;

  }



  return floatNum.f;

}



int main() {

  floatU floatNum;

  floatNum.f = -5.8125;

  printf("%f\n", floatNum.f);

  displayFloat(floatNum.f);

  floatNum.f = makeFloat("-101.1101");

  printf("%f\n", floatNum.f);

  displayFloat(floatNum.f);

}
