
#include "conversion.h"
/* Function:  Int_to_Roman
 * Calculates Roman numeral equivalent for input integer value
 * Inputs: Integer value to be converted
 * Output: Pointer to converted Roman numeral value or NULL ( if input is invalid or if conversion failed)
 */

char* Int_to_Roman(int Integer_num)
{
	/*Proceed only if input integer is valid*/
	if(!IS_VALID_INT(Integer_num))
	{
		return NULL;
	}

	int item=0;
	char *result=(char*)malloc(sizeof(char)*MAX_ROMAN_NUMERAL_LENGTH);
	
	if(result==NULL) 
	{
		fputs("Memory allocation error\n", stderr); 
		return NULL;
	}
	strcpy(result,"");

	for(item=0; item < ROMAN_CHART_SIZE; item++ )
	{
		/*Traverse through the Roman chart until a value less than or equal to the input integer is found*/
		while((Roman_Chart[item].decimal) <= Integer_num)  
		{

			strcat(result,Roman_Chart[item].roman); /*Append roman numeral*/
			Integer_num-=Roman_Chart[item].decimal; /* Decrease input integer by the value of Roman numeral appended*/

		}
				
	}
	strcat(result,"\0");	//Append string terminator	
	return result;
}

