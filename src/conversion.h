
#ifndef CONVERSION_H_
#define CONVERSION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define INVALID 0
#define ROMAN_CHART_SIZE 13
#define MAX_ROMAN_NUMERAL_LENGTH 16

#define IS_VALID_INT(x) (x>0 && x<5000)


typedef enum { FALSE, TRUE } boolean;


extern int   Roman_to_Int( const char* );
extern char* Int_to_Roman(int);
extern char* roman_subtract(const char*,const char*);
extern char* roman_add(const char*,const char*);

struct Roman_Int_Map
{
	const char* roman;
	const int decimal;
};

extern const struct Roman_Int_Map Roman_Chart[];



#endif /* CONVERSION_H_ */
