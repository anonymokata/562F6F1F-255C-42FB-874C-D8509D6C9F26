#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertToInt(char c)
{
	int dec = 0;
	if(c == 'I'){
		dec = 1;
	} else if(c == 'V'){
		dec = 5;
	} else if(c == 'X' ){
		dec = 10;
	} else if(c == 'L'){
		dec = 50;
	} else if(c == 'C'){
		dec = 100;
	} else if(c == 'D'){
		dec = 500;
	} else if(c == 'M'){
		dec = 1000;
	}
	
	return dec;
}

char* add(char* num1, char* num2)
{
	char* result = (char *)malloc(strlen(num1)+strlen(num2)+1);
	if(convertToInt(num1[0]) > convertToInt(num2[0])){
		strcpy(result, num1);
		strcat(result, num2);
	} else {
		strcpy(result, num2);
		strcat(result, num1);
	}
	
	printf("%s + %s = %s\n", num1, num2, result);
	return result;
}
