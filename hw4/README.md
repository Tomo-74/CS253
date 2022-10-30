Thomas Lonowski
CS 253
HW4


***************************
 Compile/run instructions
***************************
	1. Navigate to the directory where main.c is stored ("~/.../hw4/ccc/")
	2. Compile the program by running the command "make"
	3. The resulting object file is named "ccc" by default. Run it with the command "ccc", followed by an even number of name/category pairs (see example below).
	5. Upon running, the program immediately takes in user input. This process loops indefinitely. To exit the loop and end the program, type an excape sequence (Ctrl+d by default)
	
	Compilation and run example:
		[thomaslonowski@onyxnode30 ccc]$ make
		gcc -o main.o -c main.c -g -Wall -MMD -D_GNU_SOURCE -DMAXCATS=10
		gcc -o ccc.o -c ccc.c -g -Wall -MMD -D_GNU_SOURCE -DMAXCATS=10
		gcc -o ccc main.o ccc.o -g -Wl,-Map=ccc.map
		[thomaslonowski@onyxnode30 ccc]$ ccc digits "0-9" vowels "^aeiou" favorites "tj1"

	Additionally, you can increase the default maximum number of categories at compile time:
		[thomaslonowski@onyxnode30 ccc]$ make MAXCATS=50
		...

	Special characters:
		^	a carrot designates capitilization folding. Characters following a carrot are case-insensitive; both upper and lower case are counted.
		-	a hyphen designated a character range. "0-9" designates all digits between 0 and 9. "A-Z" designates all capital letters between A and Z.


*******************************
 Error message documentation
*******************************
To demonstrate this error, I set the MAXCATS preprocessor macro to the value of 4. So, when the program executes, main adds the three default categories.
Main then tries to add the user-defined categories. But in this case, the user defined 2 new categories when the number of categories was capped at 4 by
MAXCATS. Because of this, the ERROR function is called and a message is printed to the user before the program terminates.

Here's my code that prints the error message:
	if(numCats > MAXCATS) {
		ERROR("Maximum category capacity exceeded. Increase category capacity with the -D flag. Terminating program.");
	}

Here's a command-line example of the error being thrown:
	[thomaslonowski@onyxnode69 hw3]$ hw3 digits "12345" uppercaseVowels "AEIOU"
	ccc.c:61: error: Maximum category capacity exceeded. Increase category capacity at compile time.
	[thomaslonowski@onyxnode69 hw3]$


***************************
 Debugging documentation
***************************


**************************
 Valgrind documentation
**************************
