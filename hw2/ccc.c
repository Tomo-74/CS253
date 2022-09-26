#include <stdio.h>
#include "ccc.h"

//////////////
/// Fields ///
//////////////
typedef struct {
	char* name;
	char* targetChars;
	int count;
} ChrCat;

typedef ChrCat ChrCats[];

static ChrCats categories = {
	{"vowels", "aeiouAEIOU", 0},
/*
	{"consonants", "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", 0}	
	{"letters", "abcdefghijklmnopqrstuvwxyz", 0},
	{"digits", "0123456789", 0},
	{"punctuation", "~`!@#$%^&*()_+-={}[]|\\;:,<.>/?'\"", 0},
	{"ascender", "bdfhklt", 0},
	{"descender", "gjpqy", 0},
	{"upper", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"lower", "abcdefghijklmnopqrstuvwxyz", 0},
	{"curvy", "abcdefghjmnopqrstuy", 0},
	{"sticky", "iklvwxz", 0},
*/
};

const int numCategories = sizeof(categories) / sizeof(categories[0]);



/////////////////
/// Functions ///
/////////////////
static int countOccurences(char input[], ssize_t inputLen, char targetChars[], int numtargetChars) {
	int count = 0;
	for(int i = 0; i < inputLen; i++) {
		for(int j = 0; j < numtargetChars; j++) {
			if(input[i] == targetChars[j]) {
				count++;
				break;
			}
		}
	}
	return count;
}


extern void ccc(char input[], ssize_t inputLen) {	
	for(int i = 0; i < numCategories; i++) {	// For each category in the struct
		int numTargetChars = sizeof(categories[i].targetChars) - 1;	// -1 to account for the later for loop starting at 0
		categories[i].count = countOccurences(input, inputLen, categories[i].targetChars, numTargetChars);	// Count the number of char occurences for that category and update the struct's count variable
		printf("%s %d\n", categories[i].name, categories[i].count);	// Print output to console
		categories[i].count = 0;
	}
}

