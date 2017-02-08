#include <assert.h>
#include "calculator.h"

int main()
{
	//addition tests
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
	assert(!strcmp(add("XXXIV", "LXVI"), "C"));
	
	//substraction tests
	//test 1: subtrahend appears to be the same as smaller part of minuend
	assert(!strcmp(sub("II", "I"), "I"));
	assert(!strcmp(sub("VII", "II"), "V"));
	
	//test 2: subtrahend is same to some part of minuend
	assert(!strcmp(sub("LXXV", "XX"), "LV"));
	assert(!strcmp(sub("LXXVII", "XI"), "LXVI"));
	
	//test 3: subtrahend has some letters no letters that are not in minuend
	assert(!strcmp(sub("V", "II"), "III"));
	assert(!strcmp(sub("XII", "VII"), "V"));
	
	//test 4: there are some situations that a lesser numeral put before a bigger numeral
	assert(!strcmp(sub("IV", "II"), "II"));
	assert(!strcmp(sub("XC", "X"), "LXXX"));
	assert(!strcmp(sub("XVIII", "IX"), "IX"));
	
	//test 5: general tests
	assert(!strcmp(sub("XX", "V"), "XV"));
	assert(!strcmp(sub("XXIX", "XVIII"), "XI"));
	assert(!strcmp(sub("C", "LXVI"), "XXXIV"));
	assert(!strcmp(sub("LIV", "X"), "XLIV"));
	assert(!strcmp(sub("XLIV", "XXIV"), "XX"));
	assert(!strcmp(sub("M", "I"), "CMXCIX"));
	
	return 0;
}