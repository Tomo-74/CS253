#include <stdio.h>	// Angle brackets used to include standard libraries
// #include <stdlib.h>
#include "ccc.h"

// static char* programName;

int main(int argc, char* argv[]) {
//	programName = argv[0];	
	char* input = 0;
	size_t inputSize = 0;
	
	// Get user input from command line
	while(1) {
		ssize_t inputLen = getline(&input, &inputSize, stdin);
//		inputLen -= 1;
		if(inputLen < 0) break;	
		ccc(input, inputLen);
	}
	return 0;
}
