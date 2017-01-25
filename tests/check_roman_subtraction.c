#include <stdlib.h>
#include <check.h>
#include "../src/conversion.h"
#include <check_roman.h>


START_TEST (test_roman_subtraction_valid_inputs_with_subtrahend_string_in_minuend)
{

  ck_assert_str_eq (roman_subtract ("II","I"), "I");
  ck_assert_str_eq (roman_subtract ("VIII","III"), "V");
  ck_assert_str_eq (roman_subtract ("LXIV","L"), "XIV");
  ck_assert_str_eq (roman_subtract ("MCDIX","MIX"), "CD");
  ck_assert_str_eq (roman_subtract ("MMMCCLXXV","CX"), "MMMCLXV");
  ck_assert_str_eq (roman_subtract ("CDXX","C"), "CCCXX");

}
END_TEST

START_TEST (test_roman_subtraction_valid_inputs_with_subtrahend_string_not_in_minuend)
{
  ck_assert_str_eq (roman_subtract ("X","I"), "IX");
  ck_assert_str_eq (roman_subtract ("L","VII"), "XLIII");
  ck_assert_str_eq (roman_subtract ("D","L"), "CDL");
  ck_assert_str_eq (roman_subtract ("MMM","DLX"), "MMCDXL");
  ck_assert_str_eq (roman_subtract ("M","VII"), "CMXCIII");

}
END_TEST


START_TEST (test_roman_subtraction_with_irregular_roman_inputs)
{
  
  ck_assert_ptr_eq (roman_subtract ("IIV","I"),NULL);
  ck_assert_ptr_eq (roman_subtract ("VV","C"),NULL);
  ck_assert_ptr_eq (roman_subtract ("DD","LL"),NULL );
  ck_assert_ptr_eq (roman_subtract ("CCCC","C"),NULL );
  ck_assert_ptr_eq (roman_subtract ("XIIV","MDMVL"),NULL );

}
END_TEST

START_TEST (test_roman_subtraction_with_invalid_inputs)
{
  
  ck_assert_ptr_eq (roman_subtract ("VIIwqBCD","II"),NULL);
  ck_assert_ptr_eq (roman_subtract ("XX","@.$%"),NULL);
  ck_assert_ptr_eq (roman_subtract ("roman-4","FOUR"),NULL );
  ck_assert_ptr_eq (roman_subtract ("ix","II"),NULL);
  ck_assert_ptr_eq (roman_subtract ("0","V"),NULL );
  ck_assert_ptr_eq (roman_subtract ("","C"),NULL );
  ck_assert_ptr_eq (roman_subtract ("",""),NULL );
  ck_assert_ptr_eq (roman_subtract (" ",NULL),NULL);

}
END_TEST

START_TEST (test_roman_subtraction_with_minuend_not_greater_than_subtrahend)
{
  
  ck_assert_ptr_eq (roman_subtract ("I","II"),NULL);
  ck_assert_ptr_eq (roman_subtract ("V","LV"),NULL);
  ck_assert_ptr_eq (roman_subtract ("CCC","CD"),NULL );
  ck_assert_ptr_eq (roman_subtract ("M","MMCDXXII"),NULL );
  ck_assert_ptr_eq (roman_subtract ("CCCLXXXVIII","CD"),NULL );

}
END_TEST

   
  TCase* roman_subtraction(void)
  {
  TCase* tc_roman_subtraction = tcase_create ("test_roman_subtraction");

  /* TEST VALID INPUTS */
  tcase_add_test (tc_roman_subtraction, test_roman_subtraction_valid_inputs_with_subtrahend_string_in_minuend);
  tcase_add_test (tc_roman_subtraction, test_roman_subtraction_valid_inputs_with_subtrahend_string_not_in_minuend);

  /* TEST INVALID INPUTS : Irregular roman numerals, invalid string inputs and minuend not greater than subtrahend*/	
  tcase_add_test (tc_roman_subtraction, test_roman_subtraction_with_irregular_roman_inputs);
  tcase_add_test (tc_roman_subtraction, test_roman_subtraction_with_invalid_inputs);
  tcase_add_test (tc_roman_subtraction, test_roman_subtraction_with_minuend_not_greater_than_subtrahend);
 
  return tc_roman_subtraction;
  }

