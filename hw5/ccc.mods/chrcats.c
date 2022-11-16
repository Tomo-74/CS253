#include "chrcats.h"

static int numCats=0;	// The number of character categories; the length of the list


extern List addCat(ChrCats this, char* name, char* targetChars) {
	numCats++;
	return cons(newCat(name, targetChars), this);	// Construct and return a new node
}


extern void ccc(ChrCats this, char* input, ssize_t inputLen) {	
	if(!numCats) ERROR("No character categories supplied");

	for(List c=this; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat curCat = car(c);
		int numTargetChars = getArrayLength(curCat->targetChars);
		curCat->count = countOccurences(input, inputLen, curCat->targetChars, numTargetChars);	// Count the number of char occurences for that category and update the count variable
		printf("%s %d\n", curCat->name, curCat->count);	// Print results to console
  	}
	printf("\n");
}


/**
 * Returns a string representation of the character category search results
 *
 * @param i an integer to base the recursion off of. Must be 0 in the toString call
 */
extern void catsToString(ChrCats this) {
	for(List c=this; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat curCat = car(c);
		printf("<%s %d>\n", curCat->name, curCat->count);
  	}
	printf("\n");
}


extern void freeCats(ChrCats this) { freedata(this); }

