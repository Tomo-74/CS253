Thomas Lonowski
CS 253
HW3


***************************
 Compile/run instructions
***************************
	1. Navigate to the directory where main.c is stored ("~/.../hw3/ccc/")
	2. Compile the program by running the command "make" or specify a maximum number of categories to follow with the command "make MAXCATS=num_here"
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
Without calling the toString method, my code has no memory leaks reported by Valgrind:

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


When the toString method is called, however, there are some memory leaks which I don't believe can be easily avoided:

	[thomaslonowski@onyxnode30 ccc]$ make valgrind
	echo -e "Hello\nworld!" | valgrind --leak-check=full ./ccc 
	==492969== Memcheck, a memory error detector
	==492969== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
	==492969== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
	==492969== Command: ./ccc
	==492969== 
	lower vowels 2
	lower consonants 2
	letters 5
	<lower vowels 2> <lower consonants 2> <letters 5> 

	lower vowels 1
	lower consonants 4
	letters 5
	<lower vowels 1> <lower consonants 4> <letters 5> 

	==492969== 
	==492969== HEAP SUMMARY:
	==492969==     in use at exit: 196 bytes in 6 blocks
	==492969==   total heap usage: 15 allocs, 9 frees, 6,036 bytes allocated
	==492969== 
	==492969== 26 bytes in 2 blocks are definitely lost in loss record 1 of 3
	==492969==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
	==492969==    by 0x4ED6FD7: vasprintf (in /usr/lib64/libc-2.28.so)
	==492969==    by 0x4EB6C87: asprintf (in /usr/lib64/libc-2.28.so)
	==492969==    by 0x400FB9: categoriesToString (ccc.c:143)
	==492969==    by 0x400F66: categoriesToString (ccc.c:143)
	==492969==    by 0x400F66: categoriesToString (ccc.c:143)
	==492969==    by 0x400A5E: main (main.c:37)
	==492969== 
	==492969== 68 bytes in 2 blocks are definitely lost in loss record 2 of 3
	==492969==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
	==492969==    by 0x4ED6FD7: vasprintf (in /usr/lib64/libc-2.28.so)
	==492969==    by 0x4EB6C87: asprintf (in /usr/lib64/libc-2.28.so)
	==492969==    by 0x400FB9: categoriesToString (ccc.c:143)
	==492969==    by 0x400F66: categoriesToString (ccc.c:143)
	==492969==    by 0x400A5E: main (main.c:37)
	==492969== 
	==492969== 102 bytes in 2 blocks are definitely lost in loss record 3 of 3
	==492969==    at 0x4C3C096: realloc (vg_replace_malloc.c:1437)
	==492969==    by 0x4ED6F9A: vasprintf (in /usr/lib64/libc-2.28.so)
	==492969==    by 0x4EB6C87: asprintf (in /usr/lib64/libc-2.28.so)
	==492969==    by 0x400FB9: categoriesToString (ccc.c:143)
	==492969==    by 0x400A5E: main (main.c:37)
	==492969== 
	==492969== LEAK SUMMARY:
	==492969==    definitely lost: 196 bytes in 6 blocks
	==492969==    indirectly lost: 0 bytes in 0 blocks
	==492969==      possibly lost: 0 bytes in 0 blocks
	==492969==    still reachable: 0 bytes in 0 blocks
	==492969==         suppressed: 0 bytes in 0 blocks
	==492969== 
	==492969== For lists of detected and suppressed errors, rerun with: -s
	==492969== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
	[thomaslonowski@onyxnode30 ccc]$ 

