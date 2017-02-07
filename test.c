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
	
	//test 3: can not have more than one V, L or D
	assert(!strcmp(add("D", "D"), "M"));
	assert(!strcmp(add("V", "VI"), "XI"));
	
	//test 4: a lesser numeral can be put before a bigger numeral, which means subtraction of the lesser from the bigger
	assert(!strcmp(add("IV", "VI"), "X"));
	assert(!strcmp(add("IV", "V"), "IX"));
	assert(!strcmp(add("IV", "I"), "V"));
	
	//test 5: general tests
	assert(!strcmp(add("XLV", "I"), "XLVI"));
	assert(!strcmp(add("IV", "VII"), "XI"));
	assert(!strcmp(add("XIV", "VII"), "XXI"));
	assert(!strcmp(add("XXII", "XXIII"), "XLV"));
	assert(!strcmp(add("XXXIV", "XV"), "XLIX"));
	
	return 0;
}
