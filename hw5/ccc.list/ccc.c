#include "ccc.h"
#include "list.h"

//////////////
/// Fields ///
//////////////
typedef struct {
	char* name;
	char* targetChars;
	int count;
} *ChrCat;

static List categories = 0;
static int numCats = 0;	// The number of character categories AKA the length of the list


/////////////////
/// Functions ///
/////////////////
/**
 * Calculates and returns the length of a char array.
 *
 * @param array a char array to find the length of
 * @return length the length of the array
 */
static int getArrayLength(char* array) {
	int length = 0;
	for(char* i = array; *i != '\0'; i++) {	// Loop until the end of the array is reached
		length++;
	}
	return length;
}


/**
 * Determines whether a given character is alphabetic or not.
 *
 * @param c a character to check
 * @ return isAlpha whether or not c is alphabetic
*/
static int isAlpha(char c) {
	int isAlpha = 0;
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) isAlpha = 1;
	return isAlpha;
}


/**
 * Takes in a struct whose members contain the information of a user-defined
 * character category. Adds this user-defined category to a categories container,
 * such as a list or an array.
 *
 * @param name an array of characters representing the name of a category
 * @param targetChars an array of characters representing the characters that will be searched for in the user's input
 */
static ChrCat newCat(char* name, char* targetChars) {
	ChrCat newCat = (ChrCat)malloc(sizeof(*newCat));
	if(!newCat) ERROR("malloc() failed");

	newCat->name = name;
	newCat->targetChars = targetChars;
	newCat->count = 0;
	
	return newCat;
}


extern void addCat(char* name, char* targetChars) {
	numCats++;
	categories = cons(newCat(name, targetChars), categories);	// Construct a node
}


/**
 * Calculates and returns the number of occurrences of target characters in a char array 
 *
 * @param input the string to search through
 * @param inputLen the length of the string
 * @param targetChars an array of characters to search the input string for
 * @param numTargetChars the number of elements in the targetChars array
 * @return count the number of occurences
 */
static int countOccurences(char* input, ssize_t inputLen, char* targetChars, int numTargetChars) {
	int count = 0;
	int foundMatch = 0; // Boolean

	for(int i = 0; i < inputLen-1; i++) {	// For each char in the user's input line (-1 to account for the newline char added by getline)
		for(int j = 0; j < numTargetChars; j++) {	// For each targetChar
			/* Case: capitalization folding ^ */
			if(targetChars[0] == '^' && isAlpha(input[i])) {	// If the current targetChar is a carrot and the current input char is alphabetic
				for(int k = 1; k < numTargetChars; k++) {
					if(input[i] == targetChars[k] || input[i] == targetChars[k]-32 || input[i] == targetChars[k]+32) {	// If the input char and the target char are equal regardless of case
						count++;
						foundMatch = 1;
						break;
					}
				}
			}
			
			/* Case: char range - */
			else if(targetChars[j] == '-' && j-1 >= 0 && j+1 <= numTargetChars) {	// Else if the current targetChar is a hyphen that is not located at the front or end of targetChars
				char startChar = targetChars[j-1];
				char endChar = targetChars[j+1];
	
				for(int k = startChar; k < endChar; k++) {
					if(input[i] == k) {
						count++;
						foundMatch = 1;
						break;
					}
				}
			}
			
			/* Default case: no special characters */
			else if(input[i] == targetChars[j]) {
				count++;
				break;
			}
			
			if(foundMatch) { foundMatch = 0; break; }	// Boolean flag used to prevent the j for-loop from continuing to loop after a character match has already been found on line 110
		}
	}
	return count;
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

