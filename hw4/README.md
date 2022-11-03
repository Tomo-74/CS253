Thomas Lonowski
CS 253
HW4


*****************************
 Compile & run instructions
*****************************
	1. Navigate to the directory where the program is stored ("~/.../hw4").
	2. Compile the program by running the "make" command. This creates an object file named "hw4" by default. 
	3. Run the object file by typing its name ("hw4" by default) followed by an even number of "name/target characters" pairs (see example below).
	5. Upon running, the program immediately takes in user input. This process loops indefinitely. To end the program, type Ctrl+d.
	
	Compilation and run example:
		[thomaslonowski@onyxnode30 hw4]$ make
		gcc -o main.o -c main.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o ccc.o -c ccc.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o hw4 main.o ccc.o -g -Wl,-Map=hw4.map
		[thomaslonowski@onyxnode30 hw4]$ hw4 greeting "^hello" favorites "abc18" lowerDigits "0-5"

	Special characters:
		^	a carrot designates capitilization folding (only when a carrot is the first character). Characters following a carrot are case-insensitive (both upper and lower case are counted).
		-	a hyphen designated a character range. "0-9" designates all digits between 0 and 9. "A-Z" designates all capital letters between A and Z.


**************************
 Debugging documentation
**************************
	I was getting a seg fault, so I ran the program in gdb (with the -tui flag). I set a breakpoint at the countOccurrences function and ran the program. 
	After entering "hello" as the input, I received a seg fault at ccc.c:30. This told me that the seg fault was occuring in the getArrayLength function,
	before countOccurrences was even being reached. I put a new breakpoint at the getArrayLength function and reran the debugger. This made me realize
	that the categories array was empty, meaning the default categories weren't being added correctly by my addCat function. As a result, the getArrayLength
	function was trying to loop over an uninitialized array, which of course threw an error. So, I set a new breakpoint at the addCat function and reran
	the debugger. I realized that I was overwriting the value stored by the categories variable each time I added a new category. After tinkering around
	trying to find the problem, I realized that I was only adding the new category if one specific condition was met. When I changed it so that the new
	category was added in all cases, the method (and program) ran and worked perfectly.


*************************
 Valgrind documentation
*************************
	[thomaslonowski@onyxnode30 hw4]$ make valgrind
	echo -e "Hello\nworld!" | valgrind --leak-check=full ./hw4 
	==1590882== Memcheck, a memory error detector
	==1590882== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
	==1590882== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
	==1590882== Command: ./hw4
	==1590882== 
	lower vowels 2
	lower consonants 2
	letters 5
	<lower vowels 2> <lower consonants 2> <letters 5> 

	lower vowels 1
	lower consonants 4
	letters 5
	<lower vowels 1> <lower consonants 4> <letters 5> 

	==1590882== 
	==1590882== HEAP SUMMARY:
	==1590882==     in use at exit: 0 bytes in 0 blocks
	==1590882==   total heap usage: 20 allocs, 20 frees, 6,206 bytes allocated
	==1590882== 
	==1590882== All heap blocks were freed -- no leaks are possible
	==1590882== 
	==1590882== For lists of detected and suppressed errors, rerun with: -s
	==1590882== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

