#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//This function converts roman numeral to its corresponding decimal number
int convertToInt(char c)
{
	if(c == 'I'){
		return 1;
	} else if(c == 'V'){
		return 5;
	} else if(c == 'X' ){
		return 10;
	} else if(c == 'L'){
		return 50;
	} else if(c == 'C'){
		return 100;
	} else if(c == 'D'){
		return 500;
	} else if(c == 'M'){
		return 1000;
	} else {
		return 0;
	}
}

//This function count continuous repeated characters from tail of the array
int countFromTail(char* input, char c, int *start)
{
	int i, count = 0;
	bool flag = false;
	
	if(c == 'I' && c != input[*start]){
		return count;
	}
	
	for(i = *start; i >=0; i--){
		if(input[i] == c){
			flag = true;
			count++;
		}
		if(input[i] != c && flag){
			*start = i+1;
			flag = false;
			break;
		}
	}
	
	if(flag){
		*start = 0;
	}
	
	return count;
}

//This function checks if there is a situation that a lesser numeral is before a bigger numeral
bool findLessBeforeBig(char* input, int len, int* mark){
	int i;
	for(i = 0; i < (len-1); i++){
		if(convertToInt(input[i]) < convertToInt(input[i+1])){
			*mark = i;
			return true;
		}
	}
	
	return false;
}

//This function rewrite the array if I, X or C happened more than three or V, L or D happened more than one
void RewriteRepeatedNemerals(int length, char* result)
{
	int i;
	//add-test2: if I happened more than three times, replace the repeated letters with its correct roman numerals
	int index = length-1;
	int count;
	while(index > 0){
		count = countFromTail(result, 'I', &index);
		//printf("count: %d, index: %d\n", count, index);
		if(count > 3){
			if(count == 4){
				result[index] = 'I';
				result[index+1] = 'V';
				result[index+2] = '\0';
				length -= 2;
				index -= 2;
			} else if(count == 5){
				result[index] = 'V';
				result[index+1] = '\0';
				length -= 4;
				index -= 4;
			} else if(count == 6){
				result[index] = 'V';
				result[index+1] = 'I';
				result[index+2] = '\0';
				length -= 4;
				index -= 4;
			}
		} else {
			index--;
		}
	}
	
	//add-test 3: if V happened more than once, replace the repeated letters with its correct roman numerals
	index = length-1;
	while(index > 0){
		count = countFromTail(result, 'V', &index);
		if(count > 1){
			if(count == 2){
				result[index] = 'X';
				for(i = index+2; i < (length+1); i++){
					result[i-1] = result[i];
				}
				length -= 1;
				index -= 1;
			}
		} else {
			index--;
		}
	}
	
	//add-test 2: if X happened more than three times, replace the repeated letters with its correct roman numerals
	index = length-1;
	while(index > 0){
		count = countFromTail(result, 'X', &index);
		if(count > 3){
			if(count == 4){
				result[index] = 'X';
				result[index+1] = 'L';
				for(i = index+4; i < (length+1); i++){
					result[i-2] = result[i];
				}
				length -= 2;
				index -= 2;
			} else if(count == 5){
				result[index] = 'L';
				for(i = index+5; i < (length+1); i++){
					result[i-4] = result[i];
				}
				length -= 4;
				index -= 4;
			} else if(count == 6){
				result[index] = 'L';
				result[index+1] = 'X';
				for(i = index+6; i < (length+1); i++){
					result[i-4] = result[i];
				}
				length -= 4;
				index -= 4;
			}
		} else {
			index--;
		}
	}
	
	//add-test 3: if L happened more than once, replace the repeated letters with its correct roman numerals
	index = length-1;
	while(index > 0){
		count = countFromTail(result, 'L', &index);
		if(count > 1){
			if(count == 2){
				result[index] = 'C';
				for(i = index+2; i < (length+1); i++){
					result[i-1] = result[i];
				}
				length -= 1;
				index -= 1;
			}
		} else {
			index--;
		}
	}
	
	//add-test 2: if C happened more than three times, replace the repeated letters with its correct roman numerals
	index = length-1;
	while(index > 0){
		count = countFromTail(result, 'C', &index);
		if(count > 3){
			if(count == 4){
				result[index] = 'C';
				result[index+1] = 'D';
				for(i = index+4; i < (length+1); i++){
					result[i-2] = result[i];
				}
				length -= 2;
				index -= 2;
			} else if(count == 5){
				result[index] = 'D';
				for(i = index+5; i < (length+1); i++){
					result[i-4] = result[i];
				}
				length -= 4;
				index -= 4;
			} else if(count == 6){
				result[index] = 'D';
				result[index+1] = 'C';
				for(i = index+6; i < (length+1); i++){
					result[i-4] = result[i];
				}
				length -= 4;
				index -= 4;
			}
		} else {
			index--;
		}
	}
	
	
	//add-test 3: if D happened more than once, replace the repeated letters with its correct roman numerals
	index = length-1;
	while(index > 0){
		count = countFromTail(result, 'D', &index);
		if(count > 1){
			if(count == 2){
				result[index] = 'M';
				for(i = index+2; i < (length+1); i++){
					result[i-1] = result[i];
				}
				index -= 1;
			}
		} else {
			index--;
		}
	}
}

//This is the addition function to addtwo roman numbers together
char* add(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char* result = (char *)malloc(len1+len2+1);
	int i = 0, j = 0, k = 0;
	
	//add-in order to pass test 1, reorder each charater from both inputs according to its corresponding decimal number from largest to smallest
	while(i < len1){
		while(j < len2){
			if(convertToInt(num1[i]) > convertToInt(num2[j])){
				result[k] = num1[i];
				k++;
				i++;
			} else {
				result[k] = num2[j];
				k++;
				j++;
			}
		}
		result[k] = num1[i];
		k++;
		i++;
	}
	
	printf("inter result order: %s\n", result);
	
	//add-test 4: reorder the array
	int mark, length = len1+len2;
	if(findLessBeforeBig(result, length, &mark)){
		if(result[mark] == result[mark-1]){
			for(i = mark+1; i < (length+1); i++){
				result[i-2] = result[i];
			}
			length = len1+len2-2;
		} else if(result[mark+1] == result[mark-1]){
			char temp = result[mark];
			result[mark] = result[mark-1];
			result[mark-1] = temp;
		}
	}
	mark = 0;
	if(findLessBeforeBig(result, length, &mark)){
		if(result[mark+1] == result[mark-1]){
			char temp = result[mark];
			result[mark] = result[mark+1];
			result[mark+1] = temp;
		}
	}
	
	printf("inter result after reorder: %s\n", result);
	
	//add-test 2 and test 3, check repeated roman numerals
	RewriteRepeatedNemerals(length, result);
	
	printf("inter result after: %s\n", result);
	
	printf("%s + %s = %s\n", num1, num2, result);
	return result;
}

//This function rewrites the array if a lesser numeral is before a bigger numeral
void rewrite(char * result, char A, char l1, char l2, int *len, int mark)
{
	int i;
	if(A == 'V' || A == 'L' || A == 'D'){
		for(i = *len; i >= (mark+2); i--){
			result[i+2] = result[i];
		}
		for(i = 1; i <= 3; i++){
			result[mark+i] = l1;
		}
		(*len) += 2;
	} 
	if(A == 'X' || A == 'C' || A == 'M'){
		result[mark] = l1;
		for(i = *len; i >= (mark+2); i--){
			result[i+3] = result[i];
		}
		for(i = 1; i <= 4; i++){
			result[mark+i] = l2;
		}
		(*len) += 3;
	}
}

//Inputs: num1, num2
//result = num1 - num2
//This is the subtraction function to subtract a number from another
char* sub(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char* result = (char *)malloc(len1+len2+1);
	char* temp = (char *)malloc(len2+1);
	strcpy(result, num1);
	strcpy(temp, num2);
	
	//sub-test 4: rewrite the array
	int mark;
	if(findLessBeforeBig(num1, len1, &mark)){
		if(num1[mark+1] == 'V'){
			rewrite(result, 'V', 'I', '0', &len1, mark);
		}
		if(num1[mark+1] == 'X'){
			rewrite(result, 'X', 'V', 'I', &len1, mark);
		}
		if(num1[mark+1] == 'L'){
			rewrite(result, 'L', 'X', '0', &len1, mark);
		}
		if(num1[mark+1] == 'C'){
			rewrite(result, 'C', 'L', 'X', &len1, mark);
		}
		if(num1[mark+1] == 'D'){
			rewrite(result, 'D', 'C', '0', &len1, mark);
		}
		if(num1[mark+1] == 'M'){
			rewrite(result, 'M', 'D', 'C', &len1, mark);
		}
	}
	
	if(findLessBeforeBig(num2, len2, &mark)){
		if(num2[mark+1] == 'V'){
			rewrite(temp, 'V', 'I', '0', &len2, mark);
		}
		if(num2[mark+1] == 'X'){
			rewrite(temp, 'X', 'V', 'I', &len2, mark);
		}
		if(num2[mark+1] == 'L'){
			rewrite(temp, 'L', 'X', '0', &len2, mark);
		}
		if(num2[mark+1] == 'C'){
			rewrite(temp, 'C', 'L', 'X', &len2, mark);
		}
		if(num2[mark+1] == 'D'){
			rewrite(temp, 'D', 'C', '0', &len2, mark);
		}
		if(num2[mark+1] == 'M'){
			rewrite(temp, 'M', 'D', 'C', &len2, mark);
		}
	}
	
	printf("inter result after rewrite: %s\n", result);
	printf("inter temp: %s\n", temp);
	
	//sub-test 1 and 2: some subtrahend numerals can be found in minuend
	//delete those letters in common
	int i, j, k;
	while(len2 > 0){
		for(i = 0; i < len1; i++){
			for(j = 0; j < len2; j++){
				if(result[i] == temp[j]){
					for(k = i+1; k < (len1+1); k++){
						result[k-1] = result[k];
					}
					len1--;
					i--;
					for(k = j+1; k < (len2+1); k++){
						temp[k-1] = temp[k];
					}
					len2--;
					break;
				}
			}
		}
		
		printf("inter result after delete: %s\n", result);
		printf("inter temp after delete: %s\n", temp);
		
		//sub-test 3: after delete some letters in common, rewrite the larger symbol in terms of smaller symbol, then cross out all letters in common
		char tempC;
		if(len2 > 0){
			int howMany = convertToInt(result[len1-1]) / convertToInt(temp[0]);
			j = 0;
			while(howMany < 1){
				j++;
				howMany = convertToInt(result[len1-1-j]) / convertToInt(temp[0]);
			}
			printf("howmany: %d\n", howMany);
			if(howMany >= 5 && len2 == 1){
				for(k = len1+1; k > (len1-1-j); k--){
					result[k] = result[k-1];
				}
				result[len1-1-j] = temp[0];
				len1 += 1;
				len2--;
			} else {
				for(i = 0; i < howMany; i++){
					result[len1-1-j+i] = temp[0];
				}
				len1 += howMany - 1;
			}
		}
		printf("inter result after expand: %s\n\n", result);
	}
	
	//lastly, check if there are any repeated numerals
	RewriteRepeatedNemerals(len1, result);
	
	printf("%s - %s = %s\n", num1, num2, result);
	return result;
}