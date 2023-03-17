/**
    @file operation.h
    @author Cole Sanders (cgsande2)
    Provides functionality to multiply, divide, bring to an power, subtract
    and add. The purpose is to check for overflow on each of these operations.
  */

/** One more than the minimum long value */
#define LONG_MIN -9223372036854775807

/** 
    Adds the two passed in values. Program exits if overflow occurs.
    @param a first value to add.
    @param b second value to add.
    @return the result.
  */
long plus( long, long );

/** 
    Subtracts the two passed in values. Program exits if overflow occurs.
    @param a first value to subtract.
    @param b second value to subtract.
    @return the result.
  */
long minus( long, long );

/** 
    Multiplies the two passed in values. Program exits if overflow occurs.
    @param a first value to multiply.
    @param b second value to multiply.
    @return the result.
  */
long times( long, long );

/** 
    Raises a value to the power of another value. Program exits if overflow occurs
    or the exponent value is negative.
    @param a the base value.
    @param b exponent value.
    @return the result.
  */
long exponential( long, long);

/** 
    Divides the two passed in values. Program exits if overflow occurs
    or the denominator is zero.
    @param a the numerator value.
    @param b the denominator value.
    @return the result.
  */
long divide( long, long );