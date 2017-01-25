## Process this file with automake to produce Makefile.in

TESTS = check_roman_calc
check_PROGRAMS = check_roman_calc
check_roman_calc_SOURCES = check_roman_calc.c check_roman_addition.c check_roman_subtraction.c check_roman_to_int.c check_int_to_roman.c check_roman.h $(top_builddir)/src/conversion.h
check_roman_calc_CFLAGS = @CHECK_CFLAGS@
check_roman_calc_LDADD = $(top_builddir)/src/libromancalc.la @CHECK_LIBS@
