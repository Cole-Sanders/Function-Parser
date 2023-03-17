/**
    @file operation.c
    @author Cole Sanders (cgsande2)
    Provides functionality to multiply, divide, bring to an power, subtract
    and add. The purpose is to check for overflow on each of these operations.
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "operation.h"
/** The maximum long value */
#define LONG_MAX 9223372036854775807
/** One more than the minimum long value */
#define LONG_MIN -9223372036854775807
/** The exit code for the case of an overflow */
#define OVERFLOW 100
/** The exit code for the case of dividing by zero */
#define DEVIDE_ZERO 101
/** The exit code for the case of a negative exponent */
#define NEGATIVE_EXP 103


long plus( long a, long b )
{
    long c = a + b;
    if ( a < 0 && b < 0 && c >= 0 ) {
        exit(OVERFLOW);
    }
    if ( a > 0 && b > 0 && c <= 0 ) {
        exit(OVERFLOW);
    }
    return c;
}


long minus( long a, long b )
{
    long c = b - a;
    if ( b > 0 && b > a && c <= 0 ) {
        exit(OVERFLOW);
    }
    if ( b < 0 && b < a && c >= 0 ) {
        exit(OVERFLOW);
    }
    if ( a > 0 && a > b && c >= 0 ) {
        exit(OVERFLOW);
    }
    if ( a < 0 && a < b && c <= 0 ) {
        exit(OVERFLOW);
    }
    return c;
}

long times( long a, long b )
{
    long c = a * b;
    if ( a == 0 || b == 0 ) {
        return 0;
    }
    long x;
    long min = LONG_MIN - 1;
    if (( a == -1 && b > min ) || a == 1 || b == 1 || ( b == -1  && a > min )) {
        return b * a;
    }
    if (( a > 0 && b > 0 ) || ( a < 0 && b < 0 )) {
        if ( a < 0 && b < 0 ) {
            a *= -1;
            b *= -1;
        }
        x = LONG_MAX / b;
        if ( a > x ) {
            exit(OVERFLOW);
        }
    } else if ( a > 0 && b < 0 ) {
        x = min / b;
        if ( a > x ) {
            exit(OVERFLOW);
        }
    } else if ( a < 0 && b > 0 ) {
        x = min / a;
        if ( b > x ) {
            exit(OVERFLOW);
        }
    }
    return c;
}


long exponential( long a, long b )
{
    long exp = a;
    if ( b == 0 ) {
        return 1;
    } else if ( b < 0 ) {
        exit(NEGATIVE_EXP);
    }
    for ( int i = 1; i < b; ++i ) {
        exp = times( exp, a );
    }
    return exp;
}


long divide( long a, long b )
{
    if ( b == 0 ) {
        exit(DEVIDE_ZERO);
    }
    if ( a == LONG_MIN && b == -1 ) {
        exit(OVERFLOW);
    }
    return a / b;
}