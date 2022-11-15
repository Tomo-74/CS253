#include "chrcats.h"

static List categories=0;
static int numCats=0;	// The number of character categories; the length of the list


extern void addCat(char* name, char* targetChars) {
	numCats++;
	categories = cons(newCat(name, targetChars), categories);	// Construct a node
}


extern void ccc(char* input, ssize_t inputLen) {	
	if(!numCats) ERROR("No character categories supplied");

	for(List c=categories; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat currentCat = car(c);
		int numTargetChars = getArrayLength(currentCat->targetChars);
		currentCat->count = countOccurences(input, inputLen, currentCat->targetChars, numTargetChars);	// Count the number of char occurences for that category and update the count variable
		printf("%s %d\n", currentCat->name, currentCat->count);	// Print results to console
  	}
	printf("\n");
}


/**
 * Returns a string representation of the character category search results
 *
 * @param i an integer to base the recursion off of. Must be 0 in the toString call
 */
extern void catsToString() {
	for(List c=categories; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat currentCat = car(c);
		printf("<%s %d>\n", currentCat->name, currentCat->count);
  	}
}


extern void freeCats() { freedata(categories); }

