Thomas Lonowski
CS 253
HW5

*****************************
 Compile & run instructions
*****************************
	1. Navigate to the directory where the program is stored ("~/.../hw5").
	2. Compile the program by running the "make" command. This creates an object file named "ccc" by default. 
	3. Run the object file by typing its name ("ccc" by default) followed by an even number of "name/target characters" pairs (see example below).
	5. Upon running, the program immediately takes in user input. This process loops indefinitely. To end the program, type Ctrl+d.
	
	Compilation and run example:
		[thomaslonowski@onyxnode69 ccc.mods]$ make
		gcc -o chrcats.o -c chrcats.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o chrcat.o -c chrcat.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o list.o -c list.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o main.o -c main.c -g -Wall -MMD -D_GNU_SOURCE
		gcc -o ccc chrcats.o chrcat.o list.o main.o -g -Wl,-Map=ccc.map
		[thomaslonowski@onyxnode69 ccc.mods]$ ccc greeting "^hello" favs "0-9" digits "0-9"
		hello world
		digits 0
		favs 0
		greeting 7
		letters 10
		lower consonants 7
		lower vowels 3
		
		<digits 0>
		<favs 0>
		<greeting 7>
		<letters 10>
		<lower consonants 7>
		<lower vowels 3>


	Special characters:
		^	a carrot designates capitilization folding (only when a carrot is the first character). Characters following a carrot are case-insensitive (both upper and lower case are counted).
		-	a hyphen designated a character range. "0-9" designates all digits between 0 and 9. "A-Z" designates all capital letters between A and Z.


**************************
 Debugging documentation
**************************
I had a couple issues yesterday: adding categories to the list, and then looping through the list once it was constructed.
I used GDB and emailed Buff to solve the first issue. When debugging, I set breakpoints at my addCat function. Buff also
told me to use his list module, so once I took a good look at that the adding process was much easier. For the second
issue, I had been writing a for loop to loop through the list. The for loop had a loop variable c that was initialized to
my list. Since the loop depended on c and it wasn't executing properly, I figured the problem was with the categories list
that it was initialized to. Eventually however, I realized that the problem was because c was of type List, and I was
trying to use it to access the members of a ChrCar struct. I asked Buff about it after class, and he reminded me that I
could use the car and cdr functions to access the data inside of a List. I had totally forgotten about these functions, 
so I returned to the problem and applied his suggestions. However, it still didn't work because car(c) returned a void
pointer whose members I couldn't access. This one stumped me for a while, but Adam reminded me that I could cast a void
pointer to the type ChrCat. Once I did that, I was able to access the struct's members and complete the for loop functionality.


*************************
 Valgrind documentation
*************************
[thomaslonowski@onyxnode69 ccc.list]$ make valgrind
echo -e "Hello\nworld!" | valgrind --leak-check=full ./ccc 
==909021== Memcheck, a memory error detector
==909021== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==909021== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==909021== Command: ./ccc
==909021== 
letters 5
lower consonants 2
lower vowels 2
letters 5
lower consonants 4
lower vowels 1
letters 0
lower consonants 0
lower vowels 0
==909021== 
==909021== HEAP SUMMARY:
==909021==     in use at exit: 0 bytes in 0 blocks
==909021==   total heap usage: 9 allocs, 9 frees, 5,360 bytes allocated
==909021== 
==909021== All heap blocks were freed -- no leaks are possible
==909021== 
==909021== For lists of detected and suppressed errors, rerun with: -s
==909021== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

