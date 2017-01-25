
#include "conversion.h"
#include <string.h>

/* Function:  Roman_to_Int
 * Returns Integer equivalent value for input roman numeral
 * Inputs: pointer to roman numeral
 * Output: Integer equivalent of the Roman numeral or 0 if the Roman numeral is invalid
 */
int Roman_to_Int( const char* roman_numeral)
{
        
	int Integer_value=0,roman_numeral_length=0,prev_pos_value=0, current_pos_value=0, iter=0, pos=0;
	char* reverted_roman_value;

        roman_numeral_length= (roman_numeral==NULL)? 0:(strlen(roman_numeral));
        /*Do not process if the input numeral is not a valid string*/
        if(roman_numeral_length<=0)
		return INVALID;
	
	for(pos=roman_numeral_length-1; pos>=0; pos--)
	{ 
		/* iterate over the roman numeral starting backwards*/
		prev_pos_value=current_pos_value;

		for(iter=0; iter< ROMAN_CHART_SIZE; iter+=2) 
		{
			if((Roman_Chart[iter].roman[0]==roman_numeral[pos]))
			{
				current_pos_value=Roman_Chart[iter].decimal; 
			}
		}

		if(current_pos_value==0)  /* no match was found in Roman chart for character in current position i.e. nonRoman character detected*/
			return INVALID;

		Integer_value=(prev_pos_value > current_pos_value)? Integer_value-current_pos_value : Integer_value+current_pos_value;
				
	}

	reverted_roman_value=(char*)Int_to_Roman(Integer_value); 

	/*If integer value is out of range or if it does not convert back to the input Roman numeral string, the input is invalid*/
	if((!IS_VALID_INT(Integer_value)) || strcmp(roman_numeral,reverted_roman_value)) 
	{
		
                Integer_value = INVALID; /* set to invalid return value*/
	}
	
	free(reverted_roman_value); //Prevent memory leak
	return Integer_value;


}


