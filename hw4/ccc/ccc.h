#ifndef CCC_H
#define CCC_H

#include <stdio.h>
#include <stdlib.h>	// For free() function
#include "error.h"

/* NewCat, a struct type to hold the information for a user-defined character category before it
   is added to the categories array in ccc.c. A struct is used here because this makes it
   much simpler to pass char arrays between functions and avoid passing pointers. */
typedef struct {
	char* name;
	char* targetChars;
} NewCat;


extern int verbose;

/**
 * Takes in a struct whose members contain the information of a user-defined
 * character category. Adds this user-defined category to the categories array
 * in ccc.c
 *
 * @param newCat a NewCat struct containing information for a new, user-defined character category
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
