#include "chrcats.h"
#include <fcntl.h>

char* program;

/**
 * Prints the usage message for the character category count program and exits with an error signal. * 
 */
static void usage() {
  fprintf(stderr, "%s: hw6 <INPUT_FILE> <OUTPUT_FILE> { <CATEGORY_NAME> <CHARACTERS> ... }\n", program);
  exit(1);
}


/**
 * Takes user input and passes it to ccc(), which calculates and prints the number of
 * occurrences of character category elements in the input
 */
int main(int argc, char* argv[]) {
	program = argv[0];

	// Usage message and error handling
	if(argc < 3) {
		usage();
	} else if((argc - 3) % 2 != 0) {	// If the user input an odd number of category/characters pairs
		ERROR("Error: provided program with an odd number of category/characters pairs");
		return 0;
	}
	
	// Instance variables
	char* inFile = argv[1];
	char* outFile = argv[2];
	int inFD;
	int outFD;

	// Setting file descriptors
	if(inFile == "-") inFD = fileno(stdin);
	else inFD = open(argv[1], O_RDONLY);
	if(outFile == "-") outFD = fileno(stdout);
	else outFD = open(argv[2], O_WRONLY);	

	ChrCats ccs1=0;
	ChrCats ccs2=0;

	// Add default categories
	ccs1=addCat(ccs1, "lower vowels", "aeiou");
	ccs1=addCat(ccs1, "lower consonants", "bcdfghjklmnpqrstvwxyz");
	ccs1=addCat(ccs1, "letters", "^abcdefghijklmnopqrstuvwxyz");

	// Add user-defined categories
	for(int i = 1; i <= argc-1; i+=2) ccs2=addCat(ccs2, argv[i], argv[i+1]);

	// User input variables	
	char* input = 0;
	size_t inputSize = 0;	

	// Get user input from command line
	while(1) {
		ssize_t inputLen = getline(&input, &inputSize, stdin);	// getline() adds \0 to the end of the input, so inputLen is +1
		if(inputLen < 0) break;	

		ccc(ccs1, input, inputLen);
		catsToString(ccs1);

		ccc(ccs2, input,inputLen);	
		catsToString(ccs2);
	}
	freeCats(ccs1);
	freeCats(ccs2);
	free(input);
	return 0;
}

