#include <stdlib.h>
#include <check.h>
#include "../src/conversion.h"
#include <check_roman.h>

START_TEST (test_int_to_roman_for_valid_int_input_directly_mapped_output)
{

  ck_assert_str_eq(Int_to_Roman(1), "I");
  ck_assert_str_eq(Int_to_Roman(4), "IV");
  ck_assert_str_eq(Int_to_Roman(5), "V");
  ck_assert_str_eq(Int_to_Roman(9), "IX");
  ck_assert_str_eq(Int_to_Roman(40), "XL");
  ck_assert_str_eq(Int_to_Roman(50), "L");
  ck_assert_str_eq(Int_to_Roman(90), "XC");
  ck_assert_str_eq(Int_to_Roman(100), "C");
  ck_assert_str_eq(Int_to_Roman(400), "CD");
  ck_assert_str_eq(Int_to_Roman(500), "D");
  ck_assert_str_eq(Int_to_Roman(900), "CM");
  ck_assert_str_eq(Int_to_Roman(1000), "M");

}
END_TEST

START_TEST (test_int_to_roman_for_valid_int_input_additively_constructed_output)
{

  ck_assert_str_eq(Int_to_Roman(13), "XIII");
  ck_assert_str_eq(Int_to_Roman(58), "LVIII");
  ck_assert_str_eq(Int_to_Roman(136), "CXXXVI");
  ck_assert_str_eq(Int_to_Roman(555), "DLV");
  ck_assert_str_eq(Int_to_Roman(2222), "MMCCXXII");
  ck_assert_str_eq(Int_to_Roman(4883), "MMMMDCCCLXXXIII");

}
END_TEST

START_TEST (test_int_to_roman_for_valid_int_input_subtractively_constructed_output)
{

  ck_assert_str_eq(Int_to_Roman(14), "XIV");
  ck_assert_str_eq(Int_to_Roman(29), "XXIX");
  ck_assert_str_eq(Int_to_Roman(47), "XLVII");
  ck_assert_str_eq(Int_to_Roman(99), "XCIX");
  ck_assert_str_eq(Int_to_Roman(464), "CDLXIV");
  ck_assert_str_eq(Int_to_Roman(2999), "MMCMXCIX");

}
END_TEST

   

START_TEST (test_int_to_roman_for_invalid_or_overflowing_input)
{

  ck_assert_ptr_eq(Int_to_Roman(0), NULL);
  ck_assert_ptr_eq(Int_to_Roman(-102), NULL);
  ck_assert_ptr_eq(Int_to_Roman(000), NULL);
  ck_assert_ptr_eq(Int_to_Roman(5000), NULL);
  ck_assert_ptr_eq(Int_to_Roman(9999), NULL);
  ck_assert_ptr_eq(Int_to_Roman(29999999), NULL);

}
END_TEST


  TCase* int_to_roman(void)
  {
  TCase* tc_int_to_roman = tcase_create ("test_int_to_roman");

  /* TEST VALID INPUTS */
 
  tcase_add_test(tc_int_to_roman, test_int_to_roman_for_valid_int_input_directly_mapped_output);
  tcase_add_test(tc_int_to_roman, test_int_to_roman_for_valid_int_input_additively_constructed_output);
  tcase_add_test(tc_int_to_roman, test_int_to_roman_for_valid_int_input_subtractively_constructed_output);
  
  /*TEST INVALID INPUTS : invalid/out of range inputs*/
  tcase_add_test(tc_int_to_roman, test_int_to_roman_for_invalid_or_overflowing_input);



  return tc_int_to_roman;
  }
