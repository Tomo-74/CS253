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


static char* toString(ChrCats this, int i) {	
	List c=this;

	if(!c) return strdup("");	// Base case
	else {
		char* s;
		char* ts = toString(cdr(c), i+1);
		ChrCat curCat=car(c);
		asprintf(&s, "<%s %d> %s\n", curCat->name, curCat->count, ts);
		free(ts);
		return s;
	}
}


extern char* catsToString(ChrCats this) {
	return toString(this, 0);
}

extern void freeCats(ChrCats this) { freedata(this); }
