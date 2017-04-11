//Lab4 bitset.c Number System Conversion and Bit Operations

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short bitSet;

bitSet makeBitSet() { 

	bitSet bs = 0;

	return bs;

}

displayBitSet(bitSet bs) { 

	int i;

	bitSet b = 0;

	for(i = sizeof(bitSet)*8 - 1; i >= 0; i--) {

		b = b >> i;

		printf("%d", b & 1);

		b = bs;

	}

	printf("\n");

}

void setBit(bitSet* bs, int index) { 

	*bs |= 1 << (index);

}

void clearBit(bitSet* bs, int index) { 

	*bs &= ~(1 << (index));

}

int bitValue(bitSet bs, int index) { 

	int i;

	bitSet mask = 1<<(sizeof(bitSet)*8-1);

	for(i = 0; i < sizeof(bitSet)*8 - (index + 1); i++) {

		bs = bs << 1;

	}

	return (bs&mask ? 1 : 0);

}



int main() {

	bitSet bs = makeBitSet();

	bs = 52;

	displayBitSet(bs);

	
	setBit(&bs, 3);

	displayBitSet(bs);

	
	clearBit(&bs, 4);

	displayBitSet(bs);


	printf("%d\n", bitValue(bs, 5));

	
	setBit(&bs, 8);

	displayBitSet(bs);

	

	printf("Done\n");

}
