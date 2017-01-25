#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../src/conversion.h"
#include <check_roman.h>

START_TEST (test_roman_add_valid_inputs_concatentated_output)
{

  ck_assert_str_eq (roman_add ("I","I"), "II");
  ck_assert_str_eq (roman_add ("V","III"), "VIII");
  ck_assert_str_eq (roman_add ("XX","XV"), "XXXV");
  ck_assert_str_eq (roman_add ("L","XIX"), "LXIX");
  ck_assert_str_eq (roman_add ("MMMCDXX","XIX"), "MMMCDXXXIX");

}
END_TEST

START_TEST (test_roman_add_valid_inputs_non_concatentated_output)
{
  ck_assert_str_eq (roman_add ("II","II"), "IV");
  ck_assert_str_eq (roman_add ("XX","XX"), "XL");
  ck_assert_str_eq (roman_add ("CC","CC"), "CD");
  ck_assert_str_eq (roman_add ("D","D"), "M");
  ck_assert_str_eq (roman_add ("IV","VI"), "X");
  ck_assert_str_eq (roman_add ("LX","XL"), "C");
  ck_assert_str_eq (roman_add ("CDXI","XCV"), "DVI");
  ck_assert_str_eq (roman_add ("MMMXLIV","MC"), "MMMMCXLIV");

}
END_TEST

START_TEST (test_roman_add_valid_inputs_out_of_range_output)
{

  ck_assert_ptr_eq (roman_add ("I","MMMMCMXCIX"), NULL);
  ck_assert_ptr_eq (roman_add ("MCD","MMMMM"), NULL);
  ck_assert_ptr_eq (roman_add ("MMD","MMD"), NULL);

}
END_TEST

START_TEST (test_roman_add_irregular_roman_inputs)
{
  
  ck_assert_ptr_eq(roman_add ("IIV","I"),NULL);
  ck_assert_ptr_eq(roman_add ("VV","C"),NULL);
  ck_assert_ptr_eq (roman_add ("DD","LL"),NULL );
  ck_assert_ptr_eq (roman_add ("CCCC","C"),NULL );
  ck_assert_ptr_eq (roman_add ("XIIV","MDMVL"),NULL );

}
END_TEST

START_TEST (test_roman_add_invalid_string_inputs)
{
  
  ck_assert_ptr_eq(roman_add ("VIIABCD","II"),NULL);
  ck_assert_ptr_eq(roman_add ("vii","II"),NULL);
  ck_assert_ptr_eq(roman_add ("XX","@.$%"),NULL);
  ck_assert_ptr_eq (roman_add ("roman-4","FOUR"),NULL );
  ck_assert_ptr_eq (roman_add ("","C"),NULL );
  ck_assert_ptr_eq (roman_add ("",""),NULL );
  ck_assert_ptr_eq (roman_add (" ",NULL),NULL );
  

}
END_TEST

   
  TCase* roman_addition(void)
  {
  TCase* tc_roman_addition = tcase_create ("test_roman_addition");

 
  
  /* TEST VALID INPUTS:    valid output, out of range output */
  tcase_add_test (tc_roman_addition, test_roman_add_valid_inputs_concatentated_output);
  tcase_add_test (tc_roman_addition, test_roman_add_valid_inputs_non_concatentated_output);	
  tcase_add_test (tc_roman_addition, test_roman_add_valid_inputs_out_of_range_output);

  /* TEST INVALID INPUTS : Irregular roman numerals, invalid string inputs*/ 
  tcase_add_test (tc_roman_addition, test_roman_add_irregular_roman_inputs);
  tcase_add_test (tc_roman_addition, test_roman_add_invalid_string_inputs);

  return tc_roman_addition;
  }

