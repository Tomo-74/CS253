#ifndef CHRCATS_H
#define CHRCATS_H

#include "chrcat.h"

typedef void* ChrCats;


/**
 * Constructs a new node that contains a user-defined character category
 * and adds it to a singly-linked list of all the categories.
 *
 * @param name an array of characters representing the name of a category
 * @param targetChars an array of characters representing the characters that will be searched for in the user's input
 */
extern List addCat(ChrCats this, char* name, char* targetChars);


/**
 * Finds the number of times the character categories occur in a string input 
 *
 * @param input the string to search through
 * @param inputLen the length of the string
 */
extern void ccc(ChrCats this, char* input, ssize_t len);


/**
 * Prints a string representation of the category names and counts
 */
extern void catsToString(ChrCats this);


/**
 * Calls free() on the categories array, clearing the
 * memory allocated by calls to realloc during runtime.
 */
extern void freeCats(ChrCats this);

#endif
