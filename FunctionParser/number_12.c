/**
    @file number_12.c
    @author Cole Sanders (cgsande2)
    Provides functionality to skip whitespace in the input stream, read in 
    a base twelve value to decimal, and print out a decimal value in base twelve.
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

    while (( ch > BELOW_ZERO && ch < ABOVE_NINE ) || ch == DEC_ASCII || ch == EL_ASCII || ( ch == NEGATIVE && firstDigit )) {
        firstDigit = false;
        long d;
        
        if ( ch > BELOW_ZERO && ch < ABOVE_NINE ) {
            d = ch - ASCII_ZERO;
        } else if ( ch == DEC_ASCII ) {
            d = DEC;
        } else if ( ch == EL_ASCII ) {
            d = EL;
        }
    
        if ( ch == NEGATIVE ) {
            negative = true;
            ch = getchar();
            continue;
        }
    
        value = times( value, BASE_TWELVE );
        
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

/** 
    Recursive helper method to print_value() that prints out the value 
    in base twelve.
    @param value the value to be printed.
    @param negative boolean that's true if the value is negative.
  */
void recursive_print( long value, bool negative )
{
    if ( value != 0 ) {
        long d = value % BASE_TWELVE;
        long ch;
        if ( negative ) {
            d = times( d, NEGATE );
        }
        if ( d >= MIN_DIGIT && d <= MAX_DIGIT ) {
            ch = d + ASCII_ZERO;
        } else if ( d == EL ) {
            ch = EL_ASCII;
        } else if ( d == DEC ) {
            ch = DEC_ASCII;
        }
        value = divide( value, BASE_TWELVE );
        recursive_print( value, negative );
        putchar( ch );
    }
}

void print_value( long value )
{
    bool negative = false;
    if (value == 0 ) {
        putchar( ASCII_ZERO );
    } else { 
        if ( value < 0 ) {
            putchar( NEGATIVE );
            negative = true;
        }
        recursive_print( value, negative );
    }
}

