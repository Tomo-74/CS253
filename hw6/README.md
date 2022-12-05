Thomas Lonowski
CS 253
HW6

*****************************
 Compile & run instructions
*****************************
	1. Navigate to the directory where the program is stored ("~/.../hw6").
	2. Compile the program by running the "make" command. This creates an object file named "ccc" by default. 
	3. Run the object file by typing its name ("ccc" by default) followed by an even number of "name/target characters" pairs (see example below).
	5. Upon running, the program immediately takes in user input. This process loops indefinitely. To end the program, type Ctrl+d.
	
	Compilation and run example:


	Special characters:
		^	a carrot designates capitilization folding (only when a carrot is the first character). Characters following a carrot are case-insensitive (both upper and lower case are counted).
		-	a hyphen designated a character range. "0-9" designates all digits between 0 and 9. "A-Z" designates all capital letters between A and Z.


**************************
 Debugging documentation
**************************
	Got a segmentation fault when running the program. Used gdb with the -tui flag, setting
	breakpoints at main.c:31, 37, and 51 (at the time). The seg fault came at line 52, and I
	discovered it was caused by the strcmp method. I tried a few different things to get its
	arguments to both be pointers, and eventually I got it to work. Previously, I had been
	comparing the name of the file (char*) to the string literal "-", which evaluated to an int.
	

*************************
 Valgrind documentation
*************************

