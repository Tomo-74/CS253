#include "ccc.h"

/**
 * Takes user input and passes it to ccc(), which calculates and prints the number of
 * occurrences of character category elements in the input
 */
int main(int argc, char* argv[]) {
	if((argc - 1) % 2 != 0) {	// If the user input an odd number of name/category pairs
		ERROR("Provided program with an odd number of name/category pairs");
		return 0;
	}

	// Add default categories
	NewCat lowerVowels = {"lower vowels", "aeiou"};
	NewCat lowerConsonants = {"lower consonants", "bcdfghjklmnpqrstvwxyz"};
	NewCat letters = {"letters", "^abcdefghijklmnopqrstuvwxyz"};
	addCat(lowerVowels);
	addCat(lowerConsonants);
	addCat(letters);

	// Add user-defined categories
	for(int i = 1; i <= argc-1; i+=2) {
		NewCat newCat = {argv[i], argv[i+1]};
		addCat(newCat);
	}


	// User input variables	
	char* input = 0;
	size_t inputSize = 0;	

	// Get user input from command line
	while(1) {
		ssize_t inputLen = getline(&input, &inputSize, stdin);	// getline() adds \0 to the end of the input, so inputLen is +1
		if(inputLen < 0) break;	
		ccc(input, inputLen);
		printf(categoriesToString(0));	// optional toString() call to get more information about the character categories
		printf("\n\n");	// Newline to break up command line output
	}
	free(input);
	return 0;
}
