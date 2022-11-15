#include "chrcats.h"


/**
 * Takes user input and passes it to ccc(), which calculates and prints the number of
 * occurrences of character category elements in the input
 */
int main(int argc, char* argv[]) {
	if((argc - 1) % 2 != 0) {	// If the user input an odd number of name/category pairs
		ERROR("Error: provided program with an odd number of name/category pairs");
		return 0;
	}

	// Add default categories
	addCat("lower vowels", "aeiou");
	addCat("lower consonants", "bcdfghjklmnpqrstvwxyz");
	addCat("letters", "^abcdefghijklmnopqrstuvwxyz");

	// Add user-defined categories
	for(int i = 1; i <= argc-1; i+=2) addCat(argv[i], argv[i+1]);

	// User input variables	
	char* input = 0;
	size_t inputSize = 0;	

	// Get user input from command line
	while(1) {
		ssize_t inputLen = getline(&input, &inputSize, stdin);	// getline() adds \0 to the end of the input, so inputLen is +1
		if(inputLen < 0) break;	
		ccc(input, inputLen);
		
		catsToString();
		printf("\n");
//		char* ts = categoriesToString(0);
//		printf("%s\n\n", ts);	// optional toString() call to get more information about the character categories
//		free(ts);
	}
	freeCats();
	free(input);
	return 0;
}

