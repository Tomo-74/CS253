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
	{"consonants", "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", 0},	
	{"letters", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"digits", "0123456789", 0},
	{"punctuation", "~`!@#$%^&*()_+-={}[]|\\;:,<.>/?'\"", 0},
	{"ascender", "bdfhklthkltABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"descender", "gjpqy", 0},
	{"upper", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0},
	{"lower", "abcdefghijklmnopqrstuvwxyz", 0},
	{"curvy", "abcdefghjmnopqrstuyBCDGJOPQRSU", 0},
	{"sticky", "iklvwxzAEFHIKLMNTVWXYZ", 0},
*/
};

const int numCategories = sizeof(categories) / sizeof(categories[0]);

static int getLengthOfArray(char* array) {
	int length = 0;
	for(char* i = array; *i != '\0'; i++) {
		length++;
	}
	return length;
}

/////////////////
/// Functions ///
/////////////////
static int countOccurences(char input[], ssize_t inputLen, char targetChars[], int numtargetChars) {
	int count = 0;
	for(int i = 0; i < inputLen; i++) {
		for(int j = 0; j < numtargetChars - 2; j++) {	// -2 to account for starting at 0 and the null terminator in categories[i].targetChars
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
		int numTargetChars = getLengthOfArray(categories[i].targetChars);
		categories[i].count = countOccurences(input, inputLen, categories[i].targetChars, numTargetChars);	// Count the number of char occurences for that category and update the struct's count variable
		printf("%s %d\n", categories[i].name, categories[i].count);	// Print output to console
		categories[i].count = 0;
	}
}

