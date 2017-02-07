#include <assert.h>
#include "calculator.h"

int main()
{
	//test 1: numerals can be concatenated to form a larger numeral
	assert(!strcmp(add("XIV", "LX"), "LXXIV"));
	assert(!strcmp(add("XX", "II"), "XXII"));
	assert(!strcmp(add("I", "I"), "II"));
	
	//test 2: can not have more than three I, X or C
	assert(!strcmp(add("II", "II"), "IV"));
	assert(!strcmp(add("XXI", "XXI"), "XLII"));
	
	return 0;
}
