#include "ccc.h"

#define MAXCATS	12	// Default max number of character categories. Can be changed by the user with the -D flag from command line

//////////////
/// Fields ///
//////////////
typedef struct {
	char* name;
	char* targetChars;
	int count;
} ChrCat;

typedef ChrCat ChrCats[MAXCATS];	// An array of ChrCat structs, whose size is set to MAXCATS at compile time

static ChrCats categories = {{0}};	// {0} populates all the structs' members with 0

/*
Common character categories:
	{"vowels", "aeiouAEIOU", 0},
	{"consonants", "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", 0},	
	{"letters", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"digits", "0123456789", 0},
	{"punctuation", "~`!@#$%^&*()_+-={}[]|\\;:,<.>/?'\"", 0},
	{"ascender", "bdfhklthkltABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"descender", "gjpqy", 0},
	{"upper", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"lower", "abcdefghijklmnopqrstuvwxyz", 0},
	{"curvy", "abcdefghjmnopqrstuyBCDGJOPQRSU", 0},
	{"sticky", "iklvwxzAEFHIKLMNTVWXYZ", 0}
*/

static int numCats = 0;	// The number of character categories AKA the length of the categories array



/////////////////
/// Functions ///
/////////////////

/**
 * Calculates and returns the length of a char array
 *
 * @param array a char array to find the length of
 * @return length the length of the array
 */
static int getLengthOfArray(char* array) {
	int length = 0;
	for(char* i = array; *i != '\0'; i++) {	// Loop until the end of the array is reached
		length++;
	}
	return length;
}

// Private utility method. Takes in a character and returns whether it is alphabetic or not
// TODO: document this method
static int isAlpha(char c) {
	int isAlpha = 0;
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) isAlpha = 1;
	return isAlpha;
}


extern void addCat(NewCat newCat) {
	numCats++;	

	// Check if there is space in the category array	
	if(numCats > MAXCATS) {
		ERROR("Maximum category capacity exceeded. Increase category capacity with the -D flag. Terminating program.");
	}

/*	
	char* targetChars = newCat.targetChars;
	for(int i = 1; i <= sizeof(targetChars); i++) {	// Loop for each of the target characters in the user-specified category
		if(targetChars[i-1] == "^") {
			char* caseWrappedChars[numTargetChars-i-1];	// define an array that will hold every char after the ^
			
	}
*/

	// Add category:
	categories[numCats-1].name = newCat.name;
	categories[numCats-1].targetChars = newCat.targetChars;
	categories[numCats-1].count = 0;
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
static int countOccurences(char input[], ssize_t inputLen, char targetChars[], int numTargetChars) {
	int count = 0;
	int foundMatch = 0;
	for(int i = 0; i < inputLen - 1; i++) {	// For each char in the user's input line (-1 to account for the \0 added to the end of the input by getline)
		for(int j = 0; j < numTargetChars; j++) {	// For each char in targetChars (-1 to account for the \0 in categories[i].targetChars)
			if(targetChars[j] == '^' && isAlpha(input[i])) {
				for(int k = j+1; k < numTargetChars; k++) {
					if(input[i] == targetChars[k] || input[i] == targetChars[k]-32 || input[i] == targetChars[k]+32) {	// If the input char and the target char are equal regardless of case
						count++;
						foundMatch = 1;
						break;
					}
				}
			} else if(input[i] == targetChars[j]) {
				count++;
				break;
			}
			if(foundMatch) { foundMatch = 0; break; }
		}
	}
	return count;
}


extern void ccc(char input[], ssize_t inputLen) {	
	for(int i = 0; i < numCats; i++) {	// For each category in the struct
		int numTargetChars = getLengthOfArray(categories[i].targetChars);
		categories[i].count = countOccurences(input, inputLen, categories[i].targetChars, numTargetChars);	// Count the number of char occurences for that category and update the struct's count variable
		printf("%s %d\n", categories[i].name, categories[i].count);	// Print output to console
	}
}


extern char* categoriesToString(int i) {
	char* ts;
	
	if(i == numCats) { ts = ""; return ts; }	// Base case: recursion reaches the end of the categories array
	else {
		asprintf(&ts, "<%s %d> %s", categories[i].name, categories[i].count, categoriesToString(i+1));
		return ts;
	}
}


