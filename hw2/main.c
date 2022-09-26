#include <stdio.h>	// Angle brackets used to include standard libraries
#include "ccc.h"

static char* programName;

int main(int argc, char* argv[]) {
	programName = argv[0];
	char* input = 0;
	size_t size = 0;

	static ChrCats categories = {
		{"vowels", "aeiou", 0},
/*
		{"consonants", "bcdfghjklmnpqrstvwxyz", 0}	
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
		{0}
	};

	while(1) {
		ssize_t len = getline(&input, &size, stdin);
		if(len < 0) break;	
		ccc(input, len, categories, sizeof(categories));
	}	
	return 0;
}
