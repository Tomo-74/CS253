#include <stdio.h>
#include "ccc.h"

static int countOccurences(char input[], ssize_t len, char targetChars[], ssize_t len2) {
	int count = 0;
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len2; j++) {
			if(input[i] == targetChars[j]) count += 1;
		}
	}
	return count;
}

extern void ccc(char input[], ssize_t len, ChrCat categories[], ssize_t numCategories) {
	for(int i = 0; i < numCategories; i++) {	// For each category in the struct
		categories[i].count = countOccurences(input, len, categories[i].validChars, sizeof(categories[i].validChars));	// Count the number of char occurences for that category and update the struct's count variable
		printf("%s %ld\n", categories[i].name, categories[i].count);	// Print output to console
	}
//	vowelCount = 0;
}

