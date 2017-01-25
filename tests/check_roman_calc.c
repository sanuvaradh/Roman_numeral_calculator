#include <stdlib.h>
#include <check.h>
#include "../src/conversion.h"
#include <check_roman.h>



Suite *
romancalc_suite (void)
{
  Suite *s = suite_create ("Roman_Calculator");
  
  suite_add_tcase (s, roman_addition());
  suite_add_tcase (s, roman_subtraction());
  suite_add_tcase (s, roman_to_int());
  suite_add_tcase (s, int_to_roman());
 

  return s;
}

int main (void)
{
  int number_failed;
  Suite *s = romancalc_suite ();
  SRunner *sr = srunner_create (s);
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);

  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
