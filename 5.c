/*
 * dec2base.c
 *
 *  Created on: Nov 14, 2018
 *      Author: Kevin
 */
#include <stdio.h>
#include <stdlib.h>


void dec2base(int input, int base, char* str);
void revStr(char *str, int length);


int main(void){
	int number;
	int base;
	int quotient = number;
	int n = 0;
	char array[n+1];


	printf("dec2base ");
	scanf("%d %d", &number,&base);


	if (number < 0 || number > 2147483647){
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
		dec2base(number, base, *array);
		printf("%d\n", number);
		printf("%d\n",base);
	}
}


void dec2base(int input, int base, char* str){
	int remainder;
	int i = 0;


	while (input != 0){
		remainder = input % base;
		
		if (remainder < 10){
			remainder = '0' + remainder;
		}
		
		if (remainder >= 10){
			remainder = 'A' + (remainder - 10);
		}


		//add to array
		str[i] = remainder;


		input = input / base;
		i++;
	}
	revStr(str,i);
	}
}

void revStr(char *str, int length){
	char* str = (char*)malloc(sizeof(char)*length);
	int i;
	for(i = 0; i < length; i++){
		str[i] = str[length - i - 1];
	}
	for(i=0; i < length; i ++){
		printf("%c",str[i]);
	}
}
