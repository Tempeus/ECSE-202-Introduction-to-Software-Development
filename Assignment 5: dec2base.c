/*
 * dec2base.c
 *
 *  Created on: Nov 14, 2018
 *  Student ID: 260862327
 *      Author: Kevin
 */

#include <stdio.h>
#include <stdlib.h>

//making a prototype of the functions
void dec2base(int input, int base, char *str);
void revStr(char *str, int length);

//initialization of variables to be global
int number;
int base;

//main run function
int main(int argc, char *argv[]){
	//making a copy of the number
	int quotient = number;
	int n = 0;
	
	// first input of the user to sepcify what the base is
	sscanf(argv[1],"%d", &number);
	
	//in case the user doesn't specify what the base is, it will automatically assume the base being 2
	if (argc == 2) {
		base = 2;
	}
	
	//second input of the user to specify what the base is
	else {
		sscanf(argv[2],"%d", &base);
	}
	
	//Error Handling if the number is out of range
	if (number < 0 || number > 2147483647){
		printf("\nError: Number must be of range [0, 2147483647].");
		return(-1);
	}

	// Error Handling if the base is out of range
	if (base <= 1 || base > 36){
		printf("\nError: Base must be of the range [2, 36].");
		return(-1);
	}


	else {
		// determine how many times it is divisible in order to determine the length of array
		while (quotient != 0){
			quotient = quotient / base;
			n ++;
		}
		char array[n+1];		
		dec2base(number, base, array);
	}
}

// Function is used to add remainders into a string while also converting numbers bigger than 10 to letters.
void dec2base(int input, int base, char *str){
	int remainder;
	int i = 0;
	char reChar;

	//while loop is used convert all the numbers into the required base until the input is 0 since it is an int and is rounded down
	while (input != 0){
		remainder = input % base;
		
		// converts the integer remainder into a char
		if (remainder < 10){
			reChar = '0' + remainder;
		}
		
		// converts the number bigger than 10 into a char letter
		if (remainder >= 10){
			reChar = 'A' + (remainder - 10);
		}


		//adding the determined char into the array
		str[i] = reChar;
		
		//Change the input in order to get the other number
		input = input / base;
		i++;
	}
	revStr(str,i);
}

//Function is used to reverse the string
void revStr(char *str, int length){
	//performing memmory allocation for the string
	char* Rstr = (char*)malloc(sizeof(char)*length);
	int i;
	//for loop is used to reverse the string into another new string
	for(i = 0; i < length; i++){
		Rstr[i] = str[length - i - 1];
	}
	printf("The Base-%d form of %d is: ",base, number);
	// printing the entire reversed string.
	for (i = 0; i < length; i++){
		printf("%c",Rstr[i]);
	}
	// Since 0 is defined as null, it will not print, therefore we need to create a sepcial case for when the number is 0.
	// since the number of 0 is 0 for every base, we can just print 0 when the number is 0
	if (number == 0){
		printf("%d",0);
	}
}
