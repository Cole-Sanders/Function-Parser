/**
    @file infix.c
    @author Cole Sanders (cgsande2)
    Calculates the solution to a mathematical expression made up of numbers, addition signs, subtraction signs, division signs,
    multiplication signs and exponent signs using precedence. Invalid inputs or overflow will cause the program to stop without
    printing an output. This program supports both base ten and base twelve. 
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "number.h"
#include "operation.h"

/** The ASCII value for the "+" character. */
#define PLUS 43
/** The ASCII value for the "-" character. */
#define MINUS 45
/** The ASCII value for the "/" character. */
#define DIVIDE 47
/** The ASCII value for the "*" character. */
#define MULT 42
/** The ASCII value for the "^" character. */
#define EXP 94
/** The ASCII value for the line feed character. */
#define LF 10
/** The exit code for invalid input */
#define INVALID_INPUT 102

/** 
    Parses a section of the expression and evaluates all the exponent operations
    in that section returning the solution.
    @return the solution of all evaluated exponents in the parsed section.
  */
static long parse_exp() 
{
    skip_space();
    long value = parse_value();
    bool checkExp = true;
    long ch;
    while ( checkExp ) {
        long nextChar = skip_space();
        if ( nextChar == LF ) {
            return value;
        }
        ch = getchar();
        if ( ch == EXP ) {
            nextChar = skip_space();
            if ( nextChar == MULT || nextChar == DIVIDE || nextChar == EXP || nextChar == PLUS ) {
                exit(INVALID_INPUT);
            }
            value = exponential( value, parse_value() );
        } else {
            checkExp = false;
        }
    }
    ungetc( ch, stdin );
    return value;
}

/** 
    Parses a section of the expression and evaluates all the exponent, multiplication 
    and division operations in that section returning the solution.
    @return the solution of all evaluated exponential, multiplication, and division 
    operations in the parsed section.
  */
static long parse_mul_div()
{
    long value = parse_exp();
    bool checkMD = true;
    long ch;
    while( checkMD ) {
        long nextChar = skip_space();
        if ( nextChar == LF ) {
            return value;
        }
        ch = getchar();
        skip_space();
        if ( ch == MULT ) {
            nextChar = skip_space();
            if ( nextChar == MULT || nextChar == DIVIDE || nextChar == EXP || nextChar == PLUS ) {
                exit(INVALID_INPUT);
            }
            value = times( value, parse_exp() );
        } else if ( ch == DIVIDE ) {
            nextChar = skip_space();
            if ( nextChar == MULT || nextChar == DIVIDE || nextChar == EXP || nextChar == PLUS ) {
                exit(INVALID_INPUT);
            }
            value = divide( value, parse_exp() );
        } else {
            checkMD = false;
        }
    }
    ungetc( ch, stdin );
    return value;
}

/** 
    Evaluates the given algebreic expresion printing the value.
    @return program exit status
  */
int main()
{
    long value = parse_mul_div();
    bool checkPM = true;
    long ch;
    while( checkPM ) {
        long nextChar = skip_space();
        if ( nextChar == LF ) {
            print_value( value );
            printf( "\n" );
            return EXIT_SUCCESS;
        }
        ch = getchar();
        skip_space();
        if ( ch == PLUS ) {
            nextChar = skip_space();
            if ( nextChar == MULT || nextChar == DIVIDE || nextChar == EXP || nextChar == PLUS ) {
                exit(INVALID_INPUT);
            }
            value = plus( value, parse_mul_div() );
        } else if ( ch == MINUS ) {
            nextChar = skip_space();
            if ( nextChar == MULT || nextChar == DIVIDE || nextChar == EXP || nextChar == PLUS ) {
                exit(INVALID_INPUT);
            }
            value = minus( parse_mul_div(), value );
        } else {
            checkPM = false;
        }
    }
    return INVALID_INPUT;
}