Thomas Lonowski
CS 253
HW2: Static Quo

***************************
 Compile/run instructions
***************************
	1. Navigate to the root directory where main.c is stored ("~/.../hw2")
	2. Compile the program by running the command "make" (if the Makefile isn't present, obtain a copy from JBuffenb/classes/253/pub/)
	3. The resulting compiled program is "hw2". Run it by entering the command "hw2"

	*Note: Upon running, the program immediately takes in user input. This process loops indefinitely. To exit the loop and end the program, type Ctrl+d


***************************
 Debugging documentation
***************************
The first time I ran Valgrind on my program the terminal cut off the output, so unfortunaley I couldn't copy and paste it.
But here's what happened: valgrind showed me I was getting a seg fault in like 55 of my ccc.c file. This line was where I
made my printf call, so I did some research on why that might be throwing a seg fault. Eventually I realized that I forgot
to add a newline character to the end of one of my char arrays before passing it as a parameter to the printf function.As
a result, printf didn't know when to stop looking through the array, and went off the end into restricted memory.

When I fixed this, I ran valgrind again and got the following output (I made sure to fix the limit on terminal output beforehand):


[thomaslonowski@onyxnode30 hw2]$ make valgrind
make: Warning: File 'main.d' has modification time 105600 s in the future
echo -e "Hello\nworld!" | valgrind --leak-check=full --show-leak-kinds=all ./hw2 
==1569307== Memcheck, a memory error detector
==1569307== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1569307== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1569307== Command: ./hw2
==1569307== 
vowels
 2
(null) 0
==1569307== Invalid read of size 1
==1569307==    at 0x4006C0: countOccurences (ccc.c:42)
==1569307==    by 0x400737: ccc (ccc.c:51)
==1569307==    by 0x40066C: main (main.c:16)
==1569307==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==1569307== 
==1569307== 
==1569307== Process terminating with default action of signal 11 (SIGSEGV)
==1569307==  Access not within mapped region at address 0x0
==1569307==    at 0x4006C0: countOccurences (ccc.c:42)
==1569307==    by 0x400737: ccc (ccc.c:51)
==1569307==    by 0x40066C: main (main.c:16)
==1569307==  If you believe this happened as a result of a stack
==1569307==  overflow in your program's main thread (unlikely but
==1569307==  possible), you can try to increase the size of the
==1569307==  main thread stack using the --main-stacksize= flag.
==1569307==  The main thread stack size used in this run was 8388608.
==1569307== 
==1569307== HEAP SUMMARY:
==1569307==     in use at exit: 5,240 bytes in 3 blocks
==1569307==   total heap usage: 3 allocs, 0 frees, 5,240 bytes allocated
==1569307== 
==1569307== 120 bytes in 1 blocks are still reachable in loss record 1 of 3
==1569307==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
==1569307==    by 0x4ECF712: getdelim (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x40064E: main (main.c:14)
==1569307== 
==1569307== 1,024 bytes in 1 blocks are still reachable in loss record 2 of 3
==1569307==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
==1569307==    by 0x4ECE15F: _IO_file_doallocate (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EDC00F: _IO_doallocbuf (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EDB277: _IO_file_overflow@@GLIBC_2.2.5 (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EDA41E: _IO_file_xsputn@@GLIBC_2.2.5 (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EAE356: vfprintf (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EB6A59: printf (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x40079F: ccc (ccc.c:52)
==1569307==    by 0x40066C: main (main.c:16)
==1569307== 
==1569307== 4,096 bytes in 1 blocks are still reachable in loss record 3 of 3
==1569307==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
==1569307==    by 0x4ECE15F: _IO_file_doallocate (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EDC00F: _IO_doallocbuf (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4EDB033: _IO_file_underflow@@GLIBC_2.2.5 (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x4ECF917: getdelim (in /usr/lib64/libc-2.28.so)
==1569307==    by 0x40064E: main (main.c:14)
==1569307== 
==1569307== LEAK SUMMARY:
==1569307==    definitely lost: 0 bytes in 0 blocks
==1569307==    indirectly lost: 0 bytes in 0 blocks
==1569307==      possibly lost: 0 bytes in 0 blocks
==1569307==    still reachable: 5,240 bytes in 3 blocks
==1569307==         suppressed: 0 bytes in 0 blocks
==1569307== 
==1569307== For lists of detected and suppressed errors, rerun with: -s
==1569307== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
/bin/sh: line 1: 1569306 Done                    echo -e "Hello\nworld!"
     1569307 Segmentation fault      (core dumped) | valgrind --leak-check=full --show-leak-kinds=all ./hw2
make: *** [GNUmakefile:24: valgrind] Error 139



Thankfully, the previous seg fault was gone, but now there was a new one being thrown in the countOccurences function.
So, I went to line 42 in ccc.c like valgrind told me to and checked out what might be causing the seg fault. This
was the problematic line inside a nested for loop: if(input[i] == targetChars[j]) count += 1;
I looked around the code and did some debugging with gdb for a while, and eventually realized that earlier in the code
I was using sizeof() on the array of structs itself, which was giving me some interesting results. After fixing this
so that it actually calculated the correct number of structs in the array, I updated the for loop conditions and
recompiled. This got rid of the sig fault!
