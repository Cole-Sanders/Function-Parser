/**
    @file number_10.c
    @author Cole Sanders (cgsande2)
    Provides functionality to skip whitespace in the input stream, read in decimal 
    values, and print out a decimal values.
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "number.h"
#include "operation.h"

int skip_space()
{
    int c = SPACE;
    while ( c != EOF && ( c == SPACE || c == TAB || c == RTRN || c == VT || c == FF )) {
        c = getchar();
    }
    ungetc( c, stdin );
    return c;
}

long parse_value()
{
    long value = 0;
    long ch = getchar();
    bool firstDigit = true;
    bool negative = false;
    while (( ch > BELOW_ZERO && ch < ABOVE_NINE ) || ( ch == NEGATIVE && firstDigit )) {
        firstDigit = false;
        long d;
        if ( ch > BELOW_ZERO && ch < ABOVE_NINE ) {
            d = ch - ASCII_ZERO;
        }
    
        if ( ch == NEGATIVE ) {
            negative = true;
            ch = getchar();
            continue;
        }
        value = times( value, BASE_TEN );
        if ( negative ) {
            value = minus( d, value );
        } else {
            value = plus( value, d );
        }
        ch = getchar();
    }
    ungetc( ch, stdin );
    return value;
}


void print_value( long val )
{
    printf( "%ld" , val );
}