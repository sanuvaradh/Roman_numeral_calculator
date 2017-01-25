ABOUT THIS LIBRARY:

This is an implementation of a library which will allow the addition and subtraction of Roman numerals.

The library provides the following functions for addition and subtraction of roman numerals respectively:
roman_add() and roman_subtract(), both of which return pointers to the resultant roman numeral string.



ENVIRONMENT:

The environment used for development and validation is as follows:

- Ubuntu Linux ( 14.04 LTS)
- GNU GCC compiler tool chain (4.8.2)
- GNU Make (3.81)
- Check unit testing framework (0.9.10)
- valgrind (3.10.1)



INVOKING THE CALCULATOR FROM COMMAND LINE:

The program supports command line arguments which can be used to invoke the library functions.
The applictaion can be run with the following command after make is successful:

<executable_name> <roman_numeral_1> < +/-> <roman_numeral_2> Eg: romancalc V + III


ASSUMPTIONS/LIMITATIONS:

1) The library supports input roman numerals in the range of "I" to "MMMMCMXCIX" ( i.e 1 to 4999) only.Inputs outside this range are considered invalid.
2) Input roman numerals have to be in uppercase. Eg: "ii" is not considered a valid roman input.
3) Input Roman numerals will be considered invalid if any of the Roman numeral rules are violated( Eg: "VV", "XXXX","IIIV" etc are invalid)
4) If the input roman numeral contains any values which are not part of the roman numeral set( Eg: spaces, special characters, etc), it will be considered invalid.
	

The resultant roman numeral returned by roman_add() and roman_subtract() will be NULL in the following cases:
1) If the input roman numerals are invalid or out of range
2) If the result of the calculation is out of range( outside "I" to "MMMMCMXCIX")


