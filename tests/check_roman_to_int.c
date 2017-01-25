#include <stdlib.h>
#include <check.h>
#include "../src/conversion.h"
#include <check_roman.h>


START_TEST (test_roman_to_Int_single_character_roman_input)
{

  ck_assert_int_eq(Roman_to_Int("I"), 1);
  ck_assert_int_eq(Roman_to_Int("V"), 5);
  ck_assert_int_eq(Roman_to_Int("X"), 10);
  ck_assert_int_eq(Roman_to_Int("L"), 50);
  ck_assert_int_eq(Roman_to_Int("C"), 100);
  ck_assert_int_eq(Roman_to_Int("D"), 500);
  ck_assert_int_eq(Roman_to_Int("M"), 1000);

}
END_TEST

START_TEST (test_roman_to_Int_for_roman_input_with_additive_notation)
{

  ck_assert_int_eq(Roman_to_Int("II"), 2);
  ck_assert_int_eq(Roman_to_Int("VIII"), 8);
  ck_assert_int_eq(Roman_to_Int("LXXXI"), 81);
  ck_assert_int_eq(Roman_to_Int("CCLVI"), 256);
  ck_assert_int_eq(Roman_to_Int("DCLIII"), 653);
  ck_assert_int_eq(Roman_to_Int("MMMCMLX"), 3960);

}
END_TEST

START_TEST (test_roman_to_Int_for_roman_input_with_subtractive_notation)
{

  ck_assert_int_eq(Roman_to_Int("IV"), 4);
  ck_assert_int_eq(Roman_to_Int("XIX"), 19);
  ck_assert_int_eq(Roman_to_Int("XLIX"), 49);
  ck_assert_int_eq(Roman_to_Int("LIV"), 54);
  ck_assert_int_eq(Roman_to_Int("XCIII"), 93);
  ck_assert_int_eq(Roman_to_Int("CDXLIV"), 444);
  ck_assert_int_eq(Roman_to_Int("MMMCDXCIX"), 3499);

}
END_TEST   

START_TEST (test_roman_to_Int_for_irregular_roman_input)
{

  ck_assert_int_eq(Roman_to_Int("IIV"), 0);
  ck_assert_int_eq(Roman_to_Int("XIIX"), 0);
  ck_assert_int_eq(Roman_to_Int("VVV"), 0);
  ck_assert_int_eq(Roman_to_Int("CCCCCDD"), 0);
  ck_assert_int_eq(Roman_to_Int("MDIVML"), 0);
  ck_assert_int_eq(Roman_to_Int("MMMMMM"), 0);

}
END_TEST

START_TEST (test_roman_to_Int_for_invalid_input)
{

  ck_assert_int_eq(Roman_to_Int("VIQ"), 0);
  ck_assert_int_eq(Roman_to_Int("TWO"), 0);
  ck_assert_int_eq(Roman_to_Int("Vii"), 0);
  ck_assert_int_eq(Roman_to_Int("@#..,?%&*_+"), 0);
  ck_assert_int_eq(Roman_to_Int(" "), 0);
  ck_assert_int_eq(Roman_to_Int(""), 0);
  ck_assert_int_eq(Roman_to_Int(NULL), 0);
  ck_assert_int_eq(Roman_to_Int("\0"), 0);

}
END_TEST

  TCase* roman_to_int(void)
  {
  TCase* tc_roman_to_int = tcase_create ("test_roman_to_int");

  /* TEST VALID INPUTS:    single character,additive notation, subractive notation roman numerals */
  tcase_add_test(tc_roman_to_int, test_roman_to_Int_single_character_roman_input);
  tcase_add_test(tc_roman_to_int, test_roman_to_Int_for_roman_input_with_additive_notation);
  tcase_add_test(tc_roman_to_int, test_roman_to_Int_for_roman_input_with_subtractive_notation);

  /*TEST INVALID INPUTS : Irregular roman numerals, invalid string inputs*/
  tcase_add_test(tc_roman_to_int, test_roman_to_Int_for_irregular_roman_input);
  tcase_add_test(tc_roman_to_int, test_roman_to_Int_for_invalid_input);


  return tc_roman_to_int;
  }
