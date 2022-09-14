#include <stdio.h>
#include <ccc.h>

static char programName[];
const char vowels[] = "aeiou";


/**
 * Takes in a char c and returns if it is upper case
 *
 * @param char c
 * @return int, 0 for upper case and 1 for lower case
 */
static int isUpperCase(char c) {
	int isUpperCase = 0;	// "false"
	if(c >= 'A' && c <= 'Z') {	// Determines if char is upper case
		isUpperCase = 1;	// "true"
	}
	return isUpperCase;
}


/** Runs a loop that: collects user input via getline(), counts the number of vowels in the input, and prints it to stdout
 *  @return void
 */
static void countVowels() {
	char *input = 0;
	size_t size = 0;
	int vowelCount = 0;

	while(1) {
		ssize_t len = getline(&input, &size, stdin);	// Get user input, storing input length in len

		if(len < 0) { break; }	// while loop exit condition

		for(int i = 0; i < len; i++) {
			if(isUpperCase(input[i])) { input[i] += 'a' - 'A'; }	// If an input char is upper case, change it to lower case
		}

		// Compare each input char to the vowels[] array, incrementing vowelCount for each vowel found
		for(int i = 0; i < len; i++) {
			for(size_t k = 0; k < sizeof(vowels); k++) {
				if(input[i] == vowels[k]) { vowelCount++; }
			}
		}

		printf("%d\n", vowelCount);
		vowelCount = 0;
	}
}


int main(int argc, char *argv[]) {
	*programName = argv[0];

	countVowels();
	return 0;
}
