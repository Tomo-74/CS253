#include "chrcats.h"
#include <fcntl.h>	// open()
#include <unistd.h>	// read()
#include <string.h>	// strcmp(), strlen()

char* prog;

/**
 * Prints the usage message for the character category count program and exits with an error signal. * 
 */
static void usage() {
  fprintf(stderr, "Usage: %s <INPUT_FILE> <OUTPUT_FILE> {<CATEGORY_NAME> <CHARACTERS>...}\n", prog);
}


/**
 * Takes user input and passes it to ccc(), which calculates and prints the number of
 * occurrences of character category elements in the input
 */
int main(int argc, char* argv[]) {
	prog = argv[0];

	// Usage message and error handling
	if(argc < 3) {
		usage();
		exit(1);
	} else if((argc - 3) % 2 != 0) {	// Odd number of category/characters pairs
		ERROR("User provided program with an odd number of category/characters pairs");
	}
	
	// Instance variables
	char* inFile = argv[1];
	char* outFile = argv[2];
//	char* hyphen = "-";
	int ifd;
	int ofd;

	// Set file descriptors
	if(!strcmp(inFile, "-")) { ifd = fileno(stdin); }	// Case: user wants to read from stdin
	else {							// Case: user wants to read from provided file
		ifd = open(argv[1], O_RDONLY);
		if(ifd == -1) { usage(); ERROR("Failed to open input file: %s", inFile); }
	}
	
	if(!strcmp(outFile, "-")) { ofd = fileno(stdout); } // Case: user wants to write to stdout
	else {							// Case: user wants to write to provided file
		ofd = open(argv[2], O_WRONLY | O_CREAT, 00200);	// 00200: user write permission
		if(ofd == -1) { usage(); ERROR("Failed to open output file: %s", outFile); }
	}


	// Read from input file
	enum { BUF_SIZE=100 };
	char buf[BUF_SIZE+1];	
	ssize_t bytes=0;
	while(1) {
		bytes = read(ifd, buf, BUF_SIZE);
		if(bytes < 100) break;	// EOF
	}

	buf[BUF_SIZE+1]='\0';
	printf("%s\n", buf);
	
/*
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
*/
	return 0;
}

