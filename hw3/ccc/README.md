Thomas Lonowski
CS 253
HW2: Static Quo


***************************
 Compile/run instructions
***************************
	1. Navigate to the root directory where main.c is stored ("~/.../hw3")
	2. Compile the program by running the command "make"
	3. The resulting object file is named "hw3" by default (specify a custom name with the -o flag)
	4. Run the object file with the command "hw3", followed by an even number of name/category pairs (see below).
	5. Upon running, the program immediately takes in user input. This process loops indefinitely. To exit the loop and end the program, type Ctrl+d
	
	Compilation and run example:
		[username@onyxnode69 hw3]$ make
		gcc -o main.o -c main.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o ccc.o -c ccc.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o hw3 main.o ccc.o -g -Wl,-Map=hw3.map
		[username@onyxnode69 hw3]$ hw3 digits "1234567890" favorites "abt1"


***********************
 Error documentation
***********************
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
I was struggling to get the capitalization folding functionality (^) working. It always returned an incorrect count of the number of char matches. So, I used the GNU
debugger (specifically gdb -tui) and set a breakpoint at my countOccurrences function (ccc.c:97). This is where the actual counting occurs, so it seemed like
a good place to debug the issue. I also traced through the program on paper. It was a bit tricky, because I have three nested for loops in that function. I
had to print out the variables a lot using gdb's print command. I debugged it using the character category "he^lo" and the input "hello". Eventually, I
realized that the break statements I was using to move the flow of control between my three for loops were causing some unexpected behavior. I tried moving
the break statements around a few times, and added a boolean flag variable to help the flow of control. This boolean ended up being the solution. Now, the
count works as expected for several different inputs that include the ^.


**************************
 Valgrind documentation
**************************
[thomaslonowski@onyxnode30 hw3]$ make valgrind
gcc -o main.o -c main.c -g -Wall -MMD -D_GNU_SOURCE
gcc -o ccc.o -c ccc.c -g -Wall -MMD -D_GNU_SOURCE
gcc -o hw3 main.o ccc.o -g -Wl,-Map=hw3.map
echo -e "Hello\nworld!" | valgrind --leak-check=full --show-leak-kinds=all ./hw3 
==482291== Memcheck, a memory error detector
==482291== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==482291== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==482291== Command: ./hw3
==482291== 
101010lower vowels 2
lower consonants 2
letters 5

lower vowels 1
lower consonants 4
letters 5

==482291== 
==482291== HEAP SUMMARY:
==482291==     in use at exit: 0 bytes in 0 blocks
==482291==   total heap usage: 3 allocs, 3 frees, 5,240 bytes allocated
==482291== 
==482291== All heap blocks were freed -- no leaks are possible
==482291== 
==482291== For lists of detected and suppressed errors, rerun with: -s
==482291== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
