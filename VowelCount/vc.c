#include <stdio.h>

const char vowels[] = "aeiou";
const int vowelsArrayLength = sizeof(vowels) / sizeof(vowels[0]);	// length of the vowels[] array AKA the number of possible vowels (5 in this case: aeiou

/**
* @brief Takes in a char c and determines if it is lower case or upper case
* @param char c, a standard character
* @return int, 0 for upper case and 1 for lower case
*/
int isLower(char c) {
	int isLower = 0;	// false
	if(c >= 'a' && c <= 'z') {	// if element is lower case
		isLower = 1;	// true		
	}
	return isLower;
}

/**
 * @brief Runs an input loop, counts the number of vowels in each input line, and prints it to the console
 * @return void
 */
void countVowels() {
	char *input = 0;
	size_t size = 0;
	int vowelCount = 0;

	while(1) {
		ssize_t len = getline(&input, &size, stdin);	// Get user input

		if(len < 0) { break; }	// while loop exit condition

		// Change each char to upper case
		for(int i = 0; i < len; i++) {
			if(isLower(input[i])) {
				input[i] -= 'A' - 'a';
			}
		}

		// // Take the user's input line and make every char lower case
		// for(int i = 0; i < len; i++) {	// for every char in the user's input line
		// 	if(line[i] >= 'A' && line[i] <= 'Z') {
		// 		line[i] -= 'A' - 'a';
		// 	}
		// }

		// Compare each char to the vowels[] array, incrementing vowelCount for each vowel match
		for(int i = 0; i < len; i++) {
			for(int k = 0; k < vowelsArrayLength; k++) {
				if(input[i] == vowels[k]) { vowelCount++; }
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