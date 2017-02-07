#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

char* add(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char* result = (char *)malloc(len1+len2+1);
	int i = 0, j = 0, k = 0;
	
	//in order to pass test 1, reorder each charater from both inputs according to its corresponding decimal number
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
	
	printf("inter result: %s\n", result);
	
	//test2: if I, X or C happened more than three times, replace the repeated letters with its correct roman numerals
	int index = len1+len2-1;
	int count = countFromTail(result, 'I', &index);
	//printf("count: %d, index: %d\n", count, index);
	if(count > 3){
		if(count == 4){
			result[index] = 'I';
			result[index+1] = 'V';
			result[index+2] = '\0';
		} else if(count == 5){
			result[index] = 'V';
			result[index+1] = '\0';
		} else if(count == 6){
			result[index] = 'V';
			result[index+1] = 'I';
			result[index+2] = '\0';
		}
	}
	
	count = countFromTail(result, 'X', &index);
	if(count > 3){
		if(count == 4){
			result[index] = 'X';
			result[index+1] = 'L';
			for(i = index+4; i < (len1+len2+1); i++){
				result[i-2] = result[i];
			}
		} else if(count == 5){
			result[index] = 'L';
			for(i = index+5; i < (len1+len2+1); i++){
				result[i-4] = result[i];
			}
		} else if(count == 6){
			result[index] = 'L';
			result[index+1] = 'X';
			for(i = index+6; i < (len1+len2+1); i++){
				result[i-4] = result[i];
			}
		}
	}
	
	count = countFromTail(result, 'C', &index);
	if(count > 3){
		if(count == 4){
			result[index] = 'C';
			result[index+1] = 'D';
			for(i = index+4; i < (len1+len2+1); i++){
				result[i-2] = result[i];
			}
		} else if(count == 5){
			result[index] = 'D';
			for(i = index+5; i < (len1+len2+1); i++){
				result[i-4] = result[i];
			}
		} else if(count == 6){
			result[index] = 'D';
			result[index+1] = 'C';
			for(i = index+6; i < (len1+len2+1); i++){
				result[i-4] = result[i];
			}
		}
	}
	
	//test 3: if V, L or D happened more than once, replace the repeated letters with its correct roman numerals
	index = len1+len2-1;
	count = countFromTail(result, 'V', &index);
	if(count > 1){
		if(count == 2){
			result[index] = 'X';
			for(i = index+2; i < (len1+len2+1); i++){
				result[i-1] = result[i];
			}
		}
	}
	
	count = countFromTail(result, 'L', &index);
	if(count > 1){
		if(count == 2){
			result[index] = 'C';
			for(i = index+2; i < (len1+len2+1); i++){
				result[i-1] = result[i];
			}
		}
	}
	
	count = countFromTail(result, 'D', &index);
	if(count > 1){
		if(count == 2){
			result[index] = 'M';
			for(i = index+2; i < (len1+len2+1); i++){
				result[i-1] = result[i];
			}
		}
	}
	
	printf("%s + %s = %s\n", num1, num2, result);
	return result;
}
