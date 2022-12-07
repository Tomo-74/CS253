#include "chrcats.h"
#include <string.h>	// strdup()

static int numCats=0;	// The number of character categories; the length of the list


extern List addCat(ChrCats this, char* name, char* targetChars) {
	numCats++;
	return cons(newCat(name, targetChars), this);	// Construct and return a new node
}


extern void ccc(ChrCats this, char* input, ssize_t inputLen) {	
	for(List c=this; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat curCat = car(c);
		int numTargetChars = getArrayLength(curCat->targetChars);
		curCat->count = countOccurences(input, inputLen, curCat->targetChars, numTargetChars);	// Count the number of char occurences for that category and update the count variable
  	}
}

/*
extern char* catsToString(ChrCats this, int i) {
        char* ts;
	List c=this;

        if(i==numCats) { ts=""; return ts; }        // Base case: recursion reaches the end of the categories array
        else {
		ChrCat curCat=car(c);
		asprintf(&ts, "<%s %d> %s", curCat[i].name, curCat[i].count, catsToString(cdr(c), i+1));
		return ts;
        }
}
*/

/**
 * Returns a string representation of the character category search results
 * @param i an integer to base the recursion off of. Must be 0 in the toString call
 */
static char* toString(ChrCats this, int i) {
	if(i == numCats) return strdup("");	// Base case: recursion reaches the end of the categories array
	
	char* s;
	List c=this;
	char* ts = toString(cdr(c), i+1);
	ChrCat curCat=car(c);

	asprintf(&s, "<%s %d> %s", curCat[i].name, curCat[i].count, ts);
	free(ts);
	return s;
}


extern char* catsToString(ChrCats this) {
	return toString(this, 0);
}


extern void freeCats(ChrCats this) { freedata(this); }
