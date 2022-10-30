#ifndef CCC_H
#define CCC_H

#include <stdio.h>
#include <stdlib.h>	// For free() function
#include "error.h"

/**
 * Takes in a struct whose members contain the information of a user-defined
 * character category. Adds this user-defined category to the categories array
 * in ccc.c
 */
extern void addCat(char* name, char* targetChars);


/**
 * Finds the number of times the character categories occur in a string input 
 *
 * @param input the string to search through
 * @param inputLen the length of the string
 */
extern void ccc(char* input, ssize_t len);


/**
 * Returns a string representation of the category names and counts
 * 
 * @param count a counter variable that must be 0 in the initial function call
 */
extern char* categoriesToString(int count);

#endif
