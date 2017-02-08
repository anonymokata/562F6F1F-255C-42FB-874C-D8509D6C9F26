# Roman numeral calculator

This roman numeral calculator can add and subtract roman numerals. It will return you the addition or subtraction result by inputting two roman numerals. 

My test cases are in test.c file
My implementation is in calculator.h

# Assumptions
1. Inputs are valid and in valid range
2. For subtraction, minuend is larger than subtrahend

# Usage
Include my "calculator.h" file
	
Functions:
1. char* add(char* num1, char* num2)
This add function takes two strings as inputs and returns you the addition result.

For example:
char* addresult = add("IV", "II");

2. char* sub(char* num1, char* num2)
This sub function takes two strings as inputs and returns you the 	subtraction result. The first numeral has to be larger than the second one.

For example:
char* subresult = sub("IV", "II");