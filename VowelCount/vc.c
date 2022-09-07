// standard int size on this machine is 4 bytes

#include <stdio.h>

const char vowels[] = "aeiou";
const int arrLength = sizeof(vowels) / sizeof(vowels[0]);	// length of the vowels[] array AKA the number of possible vowels (5 in this case: aeiou)
int globalLen;

/**
 * Take the user's input and make every char lower case
 *
 * @param *array a pointer to the first element of a char array
 * @return void
 */
char* toLower(char array[], int length) {
	for(int i = 0; i < globalLen; i++) {
		if(array[i] >= 'a' && array[i] <= 'z') {	// if element is lower case
			array[i] -= 'a' - 'A';	// change to upper case
		}
	}
	return array;
}

void countVowels() {
	char *line = 0;
	size_t size = 0;
	int vowelCount = 0;

	while(1) {
		ssize_t len = getline(&line, &size, stdin);	// len is the length (# of chars) of the user's input line
		globalLen = len;

		if(len < 0) { break; }	// loop exit condition

		line = toLower(line, len);	// populate an array with the user's input changed to lower case

//		// Take the user's input line and make every char lower case
//		for(int i = 0; i < len; i++) {	// for every char in the user's input line
//			if(line[i] >= 'A' && line[i] <= 'Z') {
//				line[i] -= 'A' - 'a';
//			}
//		}

		// Compare every char to the vowels[] array and increment vowelCount for every vowel found
		for(int i = 0; i < len; i++) {
			for(int k = 0; k < arrLength; k++) {
				if(line[i] == vowels[k]) { vowelCount++; }
			}
		}

		printf("%d", vowelCount);
		vowelCount = 0;
	}
}

int main() {
	countVowels();
	return 0;
}
