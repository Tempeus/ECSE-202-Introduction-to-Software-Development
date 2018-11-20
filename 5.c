/*
 * dec2base.c
 *
 *  Created on: Nov 14, 2018
 *      Author: Kevin
 */
#include <stdio.h>
#include <stdlib.h>

void dec2base(int input, int base, char* str);
char num2letter(int *remainder);

int main(void){
	int number;
	int base;
	int quotient = number;
	int n = 0;
	char array[n+1];

	printf("dec2base ");
	scanf("%d %d", &number,&base);

	if (number < 0 || base > 2147483647){
		printf("\nError: Number must be of range [0, 2147483647].");
	}

	if (base <= 1 || base > 36){
		printf("\nError: Base must be of the range [2, 36].");
	}

	else {
		// determine how many times it is divisible
		while (quotient != 0){
			quotient = quotient / base;
			n ++;
		}
		dec2base(number, base, &array);
		printf("%d\n", number);
		printf("%d\n",base);
	}
}

void dec2base(int input, int base, char* str){
	int remainder;
	int i = 0;

	while (input != 0){
		remainder = input % base;
		if (remainder >= 10){
			remainder = num2letter(remainder);
		}

		//add to array
		*str[i] = remainder;

		input = input / base;
		i++;
	}

	for (i  = 0; i < sizeof(*str); i +=1){
		printf("%d\n", *str[i]);
	}
}

char num2letter(int *remainder){
	char letter;

	if (*remainder == 10){
		letter = 'A';
	}

	if (remainder == 11){
		letter = 'B';
	}

	if (remainder == 12){
		letter = 'C';
	}

	if (remainder == 13){
		letter = 'D';
	}

	if (remainder == 14){
		letter = 'E';
	}

	if (remainder == 15){
		letter = 'F';
	}

	if (remainder == 16){
		letter = 'G';
	}

	if (remainder == 17){
		letter = 'H';
	}

	if (remainder == 18){
		letter = 'I';
	}

	if (remainder == 19){
		letter = 'J';
	}

	if (remainder == 20){
		letter = 'K';
	}

	if (remainder == 21){
		letter = 'L';
	}

	if (remainder == 22){
		letter = 'M';
	}

	if (remainder == 23){
		letter = 'N';
	}

	if (remainder == 24){
		letter = 'O';
	}

	if (remainder == 25){
		letter = 'P';
	}

	if (remainder == 26){
		letter = 'Q';
	}

	if (remainder == 27){
		letter = 'R';
	}

	if (remainder == 28){
		letter = 'S';
	}

	if (remainder == 29){
		letter = 'T';
	}

	if (remainder == 30){
		letter = 'U';
	}

	if (remainder == 31){
		letter = 'V';
	}

	if (remainder == 32){
		letter = 'W';
	}

	if (remainder == 33){
		letter = 'X';
	}

	if (remainder == 34){
		letter = 'Y';
	}

	if (remainder == 35){
		letter = 'Z';
	}
	return letter;
}
