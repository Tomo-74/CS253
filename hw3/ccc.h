#ifndef CCC_H
#define CCC_H

#include <stdio.h>
#include <stdlib.h>	// For free() function
#include "error.h"

typedef struct {
	char* name;
	char* targetChars;
} NewCat;


/**
 * TODO: function documentation
 */
extern void addCat(NewCat newCat);

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
