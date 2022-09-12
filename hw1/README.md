Thomas Lonowski
CS 253
HW1: Vowel Count

**************************

Compile/run instructions:

	1. Navigate to the root directory where vc.c is stored (".../VowelCount")
	2. Compile vc.c by running the Makefile with the command "make" (if the Makefile isn't present, manually compile vc.c with the command "gcc -o vc vc.c -g -Wall")
	3. The resulting compiled program is "vc". Run it by entering the command "vc"

	*Note: Upon running, the program immediately takes in user input and prints out the number of vowels in said input. This process loops indefinitely. To exit the loop and end the program, type Ctrl+d

Debugging documentation:

	My program wasn’t correctly counting the number of vowels in user input. It always printed 0. So I debugged the program with GDB, setting breakpoints at lines 67 (the main function), 36 (my countVowels 
	function), and 50 (a for loop). Then I ran the program, passed the first two breakpoints before stopping at the third to print out the value of the user’s input array (p *input@len). I did this to see if 
	the characters were actually being changed to uppercase, like I wanted. I discovered that instead of changing them to uppercase, my program was reassigning them to ascii values in the 200s! So I modified 
	the program to instead change the characters to lowercase, rather than uppercase. This, I realized, was what I should have been aiming for all along, since the vowels[] array is filled with lowercase 
	vowels. After some fine tuning to account for this change, the program worked!

	Right now, my program is at the point where it loops continuously for user input and prints the correct number of vowels that the user entered. I tested my program with many different inputs, including 
	numbers, symbols, uppercase, lowercase, and mixed cases. This is why I am confident that it works.


