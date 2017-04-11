//lab4 Trevor Griffin Number System Conversion and Bit Operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>	

int binToDec(char* bin);
char* decToBin(int dec);
int baseToDec(int base, char* value);
char* decToBase(int base, int dec);
void displayString(char* str);


int main() {

	int binToDecResults = binToDec("11001");

	printf("%d\n", binToDecResults);


	char* decToBinResults = decToBin(25);

	displayString(decToBinResults);


	int baseToDecResults = baseToDec(2, "11001");

	printf("%d\n", baseToDecResults);


	char* decToBaseResults = decToBase(8, 252);

	displayString(decToBaseResults);

}



void displayString(char* str) {

	int i = 0;

	while(str[i] != 'X') {

		printf("%c", str[i]);

		i++;

	}

	printf("\n");

}



int binToDec(char* bin) {

	

	int i = 0;

	int len = strlen(bin);

	int dec = 0;

	

	for(i = 0; i < len; i++) {

		if(bin[i] == '1') {

			dec += (int)pow(2, len - i - 1);

		}

	}

	

	return dec;

}



char* decToBin(int dec) {

	int i = 0;

	int temp = dec;

	while(temp != 0) {

		temp = temp / 2;

		i++;

	}

	char* bin = (char*)malloc((i+1)*sizeof(char));

	bin[i+1] = 'X';

	while(dec != 0) {

		char value = (dec % 2) + '0';

		bin[i] = value;

		dec = dec / 2;

		i--;

	}

	return bin;

}



int baseToDec(int base, char* value) {

	int i = 0;

	int len = strlen(value);

	int dec = 0;

	for(i = 0; i < len; i++) {

		int temp = value[i] + '0' - 96;

		if(temp < 10) {

			dec += ((temp) * (int) pow(base, (len - i) - 1));

		} else {

			temp -= 7;

			dec += ((temp) * (int) pow(base, (len - i) - 1));

		}

	}

	return dec;

}



char* decToBase(int base, int dec) {

	int i = 0;

	int temp = dec;

	char* bin = (char*)malloc((i+1)*sizeof(char));

	while(temp != 0) {

		temp = temp / base;

		i++;

	}

	bin[i+1] = 'X';

	while(dec != 0) {

		char value;

		if((dec % base) < 10) {

			value = (dec % base) + '0';

		} else {

			value = (dec % base) + 7 + '0';

		}

		bin[i] = value;

		dec = dec / base;

		i--;

	}

	return bin;

}

