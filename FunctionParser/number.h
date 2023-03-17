/**
    @file number.h
    @author Cole Sanders (cgsande2)
    Provides functionality to skip whitespace in the input stream, read in 
    a numberic value, and print out a numberic value.
  */

/** Exit status indicating that the program was given invalid input. */
#define FAIL_INPUT 102
/** ASCII value for the space character. */
#define SPACE 32
/** ASCII value for the tab character. */
#define TAB 9
/** ASCII value for the return character. */
#define RTRN 13
/** ASCII value for the vertical tab character. */
#define VT 11
/** ASCII value for the form feed character. */
#define FF 12
/** ASCII value for the character below zero. */
#define BELOW_ZERO 47
/** ASCII value for the character above nine. */
#define ABOVE_NINE 58
/** ASCII value for the hyphen character. */
#define NEGATIVE 45
/** ASCII value for zero. */
#define ASCII_ZERO 48
/** The base value for the base ten system. */
#define BASE_TEN 10
/** Negative one used for multiplication and negation */
#define NEGATE -1
/** The 11th digit in the base twelve system. */
#define DEC 10
/** The ASCII value for X */
#define DEC_ASCII 88
/** The 12th digit in the base twelve system */
#define EL 11
/** The ASCII value for E */
#define EL_ASCII 69
/** The base value for the base twelve system. */
#define BASE_TWELVE 12
/** The minimum digit in the base ten system. */
#define MIN_DIGIT 0
/** The maximum digit in the base ten system. */
#define MAX_DIGIT 9

/** 
    Empties all whitespace other than linefeed in the input stream up to the next non-whitespace
    character.
    @return the integer value of the next non-whitespace character.
  */
int skip_space();

/** 
    Takes the first numeric value in the input stream and returns its decimal counterpart.
    @return the decimal equivalent of the first value in the input stream.
  */
long parse_value();

/**
    Prints the passed in value out to the console in the correct base.
    @param value the value to be printed.
  */
void print_value( long );
