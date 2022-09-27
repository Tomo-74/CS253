#include <stdio.h>
#include <stdlib.h>	// for free() function
#include "ccc.h"

// static char* programName;

/**
 * Takes user input and passes it to ccc(), which calculates and prints the number of
 * occurrences of character category elements in the input
 */
int main(int argc, char* argv[]) {
//	programName = argv[0];	
	char* input = 0;
	size_t inputSize = 0;
	
	// Get user input from command line
	while(1) {
		ssize_t inputLen = getline(&input, &inputSize, stdin);	// getline() adds \0 to the end of the input, so inputLen is +1
		if(inputLen < 0) break;	
		ccc(input, inputLen);
//		printf(categoriesToString(0));	// optional toString() call to get more information about the character categories
//		printf("\n");	// optional newline to break up command line output
	}
	free(input);
	return 0;
}
