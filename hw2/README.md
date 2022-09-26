Thomas Lonowski
CS 253
HW2: Static Quo

*******************************
 Valid command line arguments
*******************************
	-v count the number of vowels
	-c count the number of consonants
	-l count the number of letters
	-d count the number of digits
	-p count the number of punctuation marks
	-a count the number of "ascender" letters (b, d, f, h, k, l, t)
	-d count the number of "descender" letters (g, j, p, q, y)
	-U count the number of upper case letters
	-L count the number of lower case letters
	-C count the number of curvy letters (a, b, c, d, e, f, g, h, j, m, n, o, p, q, r, s, t, u, y)
	-S count the number of "sticky" letters (i, k, l, v, w, x, z)



***************************
 Compile/run instructions
***************************
	1. Navigate to the root directory where main.c is stored ("~.../hw2")
	2. Compile the program by running the Makefile with the command "make" (if the Makefile isn't present, obtain a copy from JBuffenb/classes/253/pub/)
	3. The resulting compiled program is "vc". Run it by entering the command "vc"

	*Note: Upon running, the program immediately takes in user input and prints out the number of vowels in said input. This process loops indefinitely. To exit the loop and end the program, type Ctrl+d



***************************
 Debugging documentation
***************************
[thomaslonowski@onyxnode63 hw2]$ make valgrind
echo -e "Hello\nworld!" | valgrind --leak-check=full --show-leak-kinds=all ./hw2 
==1123677== Memcheck, a memory error detector
==1123677== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1123677== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1123677== Command: ./hw2
==1123677== 
vowels 2
==1123677== Invalid read of size 1
==1123677==    at 0x400732: countOccurences (ccc.c:8)
==1123677==    by 0x4007B9: ccc (ccc.c:16)
==1123677==    by 0x4006D1: main (main.c:32)
==1123677==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==1123677== 
==1123677== 
==1123677== Process terminating with default action of signal 11 (SIGSEGV)
==1123677==  Access not within mapped region at address 0x0
==1123677==    at 0x400732: countOccurences (ccc.c:8)
==1123677==    by 0x4007B9: ccc (ccc.c:16)
==1123677==    by 0x4006D1: main (main.c:32)
==1123677==  If you believe this happened as a result of a stack
==1123677==  overflow in your program's main thread (unlikely but
==1123677==  possible), you can try to increase the size of the
==1123677==  main thread stack using the --main-stacksize= flag.
==1123677==  The main thread stack size used in this run was 8388608.
==1123677== 
==1123677== HEAP SUMMARY:
==1123677==     in use at exit: 5,240 bytes in 3 blocks
==1123677==   total heap usage: 3 allocs, 0 frees, 5,240 bytes allocated
==1123677== 
==1123677== 120 bytes in 1 blocks are still reachable in loss record 1 of 3
==1123677==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
==1123677==    by 0x4ECF712: getdelim (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4006AC: main (main.c:30)
==1123677== 
==1123677== 1,024 bytes in 1 blocks are still reachable in loss record 2 of 3
==1123677==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
==1123677==    by 0x4ECE15F: _IO_file_doallocate (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EDC00F: _IO_doallocbuf (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EDB277: _IO_file_overflow@@GLIBC_2.2.5 (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EDA41E: _IO_file_xsputn@@GLIBC_2.2.5 (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EAE356: vfprintf (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EB6A59: printf (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x400835: ccc (ccc.c:17)
==1123677==    by 0x4006D1: main (main.c:32)
==1123677== 
==1123677== 4,096 bytes in 1 blocks are still reachable in loss record 3 of 3
==1123677==    at 0x4C37135: malloc (vg_replace_malloc.c:381)
==1123677==    by 0x4ECE15F: _IO_file_doallocate (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EDC00F: _IO_doallocbuf (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4EDB033: _IO_file_underflow@@GLIBC_2.2.5 (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4ECF917: getdelim (in /usr/lib64/libc-2.28.so)
==1123677==    by 0x4006AC: main (main.c:30)
==1123677== 
==1123677== LEAK SUMMARY:
==1123677==    definitely lost: 0 bytes in 0 blocks
==1123677==    indirectly lost: 0 bytes in 0 blocks
==1123677==      possibly lost: 0 bytes in 0 blocks
==1123677==    still reachable: 5,240 bytes in 3 blocks
==1123677==         suppressed: 0 bytes in 0 blocks
==1123677== 
==1123677== For lists of detected and suppressed errors, rerun with: -s
==1123677== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
/bin/sh: line 1: 1123676 Done                    echo -e "Hello\nworld!"
     1123677 Segmentation fault      (core dumped) | valgrind --leak-check=full --show-leak-kinds=all ./hw2
make: *** [GNUmakefile:24: valgrind] Error 139



