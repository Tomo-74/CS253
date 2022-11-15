#include "chrcats.h"

static List categories=0;
static int numCats=0;	// The number of character categories; the length of the list


extern void addCat(char* name, char* targetChars) {
	numCats++;
	categories = cons(newCat(name, targetChars), categories);	// Construct a node
}


extern void ccc(char* input, ssize_t inputLen) {	
	if(!numCats) ERROR("No character categories supplied");

	for (List c=categories; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat currentCat = car(c);
		int numTargetChars = getArrayLength(currentCat->targetChars);
		currentCat->count = countOccurences(input, inputLen, currentCat->targetChars, numTargetChars);	// Count the number of char occurences for that category and update the count variable
		printf("%s %d\n", currentCat->name, currentCat->count);	// Print results to console
  	}
}


/*

 * Returns a string representation of the character category search results
 *
 * @param i an integer to base the recursion off of. Must be 0 in the toString call
 
static char* toString(int i) {
	// array version
	if(i==numCats) return strdup("");	// Base case: recursion reaches the end of the categories array
	
	char* s;
	char* ts = toString(i+1);

	asprintf(&s, "<%s %d> %s", categories[i]->name, categories[i].count, ts);
	free(ts);
	return s;
	
	// list version
	for(List c=categories; c; c=cdr(c)) {	// For each character category in the list, call the countOccurences function, which searches for matches between the input letters and targetChars
		ChrCat currentCat = car(c);

  	}
}


extern char* categoriesToString() {
	return toString(0);
}
*/


extern void freeCats() { freedata(categories); }
