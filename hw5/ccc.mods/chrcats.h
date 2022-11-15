#ifndef CHRCATS_H
#define CHRCATS_H

#include "chrcat.h"


/**
 * Constructs a new node that contains a user-defined character category
 * and adds it to a singly-linked list of all the categories.
 *
 * @param name an array of characters representing the name of a category
 * @param targetChars an array of characters representing the characters that will be searched for in the user's input
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
 * @return pointer to a char array containing a string description of the character counts
 */
extern char* categoriesToString();


/**
 * Calls free() on the categories array, clearing the
 * memory allocated by calls to realloc during runtime.
 */
extern void freeCats();

#endif
