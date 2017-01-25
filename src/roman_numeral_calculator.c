
#include "conversion.h"

/* Function:  roman_add
 * Returns the sum of 2 input roman numerals in roman numeral form
 * Inputs: pointers to roman numeral_1 and roman numeral_2
 * Output: pointer to resultant roman numeral(added value of the input numerals)
 */

char* roman_add( const char* numeral_1,const char* numeral_2)
{
	int first_number=0,second_number=0,add_result=0;

	first_number = Roman_to_Int(numeral_1);
	second_number= Roman_to_Int(numeral_2);

	/*add only if the both numerals translate to valid integers*/
	if(IS_VALID_INT(first_number) && IS_VALID_INT(second_number))   
	{
		add_result = first_number+second_number;

		if(IS_VALID_INT(add_result)) 
		{
         		return Int_to_Roman(first_number+second_number);
		}
		else
		{
			fputs("Out of Range error\n", stderr);
		}
	}
	else
	{
		fputs("Invalid Input\n", stderr);
	}

	return NULL;
}



/* Function:  roman_subtract
 * Returns the difference of 2 input roman numerals in roman numeral form
 * Inputs: pointers to roman numeral_1(minuend) and roman numeral_2(subtrahend)
 * Output: pointer to resultant roman numeral(difference of the input numerals)
 */

char* roman_subtract( const char* numeral_1,const char* numeral_2)
{
	int first_number=0,second_number=0;

	first_number = Roman_to_Int(numeral_1);
	second_number= Roman_to_Int(numeral_2);

        /*subtract only if the both numerals translate to valid integers and if minuend is greater than subtrahend*/

	if(IS_VALID_INT(first_number) && IS_VALID_INT(second_number))
	{
		if(first_number>second_number)
		{
         		return Int_to_Roman(first_number-second_number);		
		}
		else
		{
			fputs("Out of range error\n", stderr);

		}
	}
	else
	{
		fputs("Invalid Input\n", stderr);
	}	       	
	return NULL;
}


