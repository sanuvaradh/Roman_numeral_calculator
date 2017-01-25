#include "conversion.h"


int main (int argc, char* argv[])
{
	
	char* result;
	if(argc<4 || (strlen(argv[2])!=1))
	{
		printf("\nPlease provide input in following format: executable program name <roman numeral 1> <+/-> <roman numeral 2>  Eg: V + X \n");
		return FALSE;
	}
	
        switch((argv[2][0]))
	{
		case '+': result=roman_add(argv[1],argv[3]);
			  break;
		case '-': result=roman_subtract(argv[1],argv[3]);
			  break;
		default:  printf("\nPlease provide input in following format: <roman numeral 1> <+/-> <roman numeral 2>  Eg: V + X \n");
			  break;
	}

	if(result !=NULL)
	{		
		printf("\n%s %s %s = %s\n",argv[1],argv[2],argv[3],result);
		free(result);
			
	}
	else
	{
		printf("Calculation failed !\n");
	}

	return 0;	
	

}
