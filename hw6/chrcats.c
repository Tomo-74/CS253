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
	/*
		// printf("%s %d\n", curCat->name, curCat->count);	// Print results to console

		char* name=curCat->name;
		int count=curCat->count;
		
		sprintf(result.buf, "%s %d\n", name, count);	// Write results to buffer
	*/
  	}
}


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


extern void freeCats(ChrCats this) { freedata(this); }