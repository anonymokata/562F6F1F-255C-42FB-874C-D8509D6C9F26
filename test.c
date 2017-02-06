#include <assert.h>
#include "calculator.h"

int main()
{
	//test 1: numerals can be concatenated to form a larger numeral
	assert(!strcmp(add("XIV", "LX"), "LXXIV"));
	assert(!strcmp(add("XX", "II"), "XXII"));
	
	return 0;
}
