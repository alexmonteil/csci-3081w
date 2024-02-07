# 3081 Lab03 - C++ Memory and Debugging
_(Due: Thursday, February. 8, 2024 @ 11:59pm)_

This week's lab revisits certain CSCI 2021 concepts that I'm sure you're all excited to delve into again. Don't worry; it's intended as a light refresher, but if you happen to learn something new, that's fantastic! The concepts and tools covered in this lab will prove highly beneficial for certain aspects of the homework.

GDB (GNU Debugger) is an incredibly powerful tool, though it may seem like overkill in certain situations. While there's nothing simpler than debugging with a good old-fashioned print statement, print statements start to fall short with larger and more complex projects.  When simple print statement debugging stops working, GDB is the way to go. Some parts of this lab might be easily debugged with print statements, but before you can run, you must walk -- and that's precisely what this lab aims to do. So, let me _walk_ you through some basic tools in GDB after a quick review of memory sizes.

## Frequently Asked Questions
If you encounter external issues beyond the laboratory assignments, such as difficulties accessing a lab machine, exceeding disk quota, or forgetting how to retrieve a commit ID with git, please refer to the [FAQ page](https://github.umn.edu/umn-csci-3081-s24/faq) for assistance.

## What You Will Learn

1. How memory allocations work, what memory management looks like in C++, and what happens when memory issues crop up in your program
2. How to enter the gdb environment
3. How to use gdb commands to debug your programs
4. How to detect memory inefficiencies using Valgrind

## General Information

### Accessing a Lab Machine

For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)). You can also access a lab machine remotely using [SSH](https://github.umn.edu/umn-csci-3081-s24/FAQ/blob/main/SSH/README.md) or a web-based service called [VOLE](https://github.umn.edu/umn-csci-3081-s24/FAQ/blob/main/VOLE/README.md). You will use your CSE Labs account to login to the lab machines. If you do not already have an account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).


**IMPORTANT: Inside the lab machine, only files saved to your home folder (e.g., `/home/lorim007`) will persist across sessions. If you log out, make sure your progress is pushed to GitHub or saved in the home folder.**

## Retrieve Class Materials

1. Clone your personal repository for the lab. **Replace the x500 with your personal x500.**
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-s24/x500-lab03.git
    ```
### What's in the lab03 folder?

- part_1

  - Makefile:
    - This makefile is provided to allow you an easy start to configure and build the executables.
  - memory.cc:
    - This contains the main function for the Gradescope assignment below.
  - lab_types.cc/h
    - These files contain function declarations and definitions for some custom types that will be used in this portion of the lab.
  
- part_2
  
  - Makefile:
    - This makefile is provided to allow you an easy start to configure and build the executables.
  - drone.cc/.h
  - entity.cc/.h
  - main.cc/.h
  - robot.cc/.h
  - tree.cc/.h

- README.md:
  - You're reading this now.

## Lab Instructions

### Goals
<hr>
The primary goals of this lab are for you to be able to...

 - Understand C++ memory concepts (Part 1)
 - Debug the given code using GDB and check memory leaks (Part 2)
<hr>

### Part 1 - Understanding C++ Memory (Gradescope assignment - 50% of Lab03 Grade)

Part 1 consists of running the `memory_app` program and answering questions on the Gradescope Lab 3 Part 1 assignment.  You can take the assignment multiple times and the highest score will be used.  **Note:** You are welcome to modify `memory.cc` to help answer any questions.

#### Executing Lab Code 

Build the executable using the makefile and run the executable.
```bash
$ <Locate to the repo first>
$ cd part_1
$ make
$ ./memory_app
```

#### Type Sizes

Run the following and study the `type_sizes()` function within `memory.cc`.  This function lists out the sizes for different types and the sizes of variables in memory:

```
$ ./memory_app type_sizes
```

Answer questions 1-5 in the Gradescope assignment.

#### Private Variables

Run the following and study the `private_variables()` function within `memory.cc`.  This function casts a DVec3 to a double array:

```
$ ./memory_app private_variables
```

Answer question 6 in the Gradescope assignment.

#### Byte Arrays

Run the following and study the `byte_arrays()` function within `memory.cc`.  This function converts an integer into a byte array:

```
$ ./memory_app byte_arrays
```

Answer questions 7-8 in the Gradescope assignment.

#### Arrays

Run the following and study the `arrays()` function within `memory.cc`.  This function investigates the buffer overflow problem:

```
$ ./memory_app arrays
```

Answer questions 9-10 in the Gradescope assignment.


### Part 2 - Debugging with GDB (50% of Lab03 Grade)

#### What You Will Learn

1. How to add the debugging flag to your Makefile compilation targets
2. How to enter the gdb environment
3. How to use gdb commands to debug your programs
4. How to detect memory inefficiencies using Valgrind

#### Instructions

**Note: Depending on the system you are using for this lab, not all values or outputs will necessarily match those shown in the blocks below. Please take the time to read and comprehend the content in these blocks, as well as the explanations provided in the lab, to gain a clear understanding of your output.**

1. First, build the example program with _make_.

    ```bash
    $ <Locate to the repo first>
    $ cd part_2
    $ make
    ```
2. Then, run the program:
    ````
    $ ./entity_app
    ````
    See that the program quits in a segmentation fault (also called a segfault). In the following steps, we will try to diagnose the problem.

3. You need to compile the code so that it can be run inside the GDB debugger. This is a flag that can be set in the makefile. For each of the compilation statements in the makefile, we need the `-g` flag.  We can do this by adding -g to CXXFLAGS to tell the compiler to generate debug code. For example:

    ````
    CXXFLAGS = -std=c++14 -g
    ````

    Now, recreate the executable, with the debugging flags used this time.

    ````
	$ make clean
	$ make -j
	````

    _What is the `-j` for?_ In make, `-j` is an argument/flag for make to say "use as many processes as you can to compile this program as quickly as possible." May not save you a ton of time now, but this could save you hours in the long run once we get into the project development.

4. Recall that during step 2, running the executable produced a `Segmentation fault`. Now let's try using the `gdb` tool to debug why the program is giving us this error.

    Start a debugging session on an executable file by typing _gdb <executable>_
    ````
    $ gdb ./entity_app
    ````

5. Once in the debugger session (the prompt will change to (**gdb**)), execute the program with the following format: `run [args]`.
    
    Since our current program doesn't need to take in any arguments, we will just be using `run` command.
6. The program _entity_app_ will run and crash with the following output (your output may look slightly different):
    ````
    (gdb) run
    Starting program: /home/user/repo/part_2/entity_app 

    Program received signal SIGSEGV, Segmentation fault.
    0x000055c43e2c805b in Tree::Tree (this=0x55c43ff72f50, name="Oak", x=50, y=50)
        at tree.h:11
    11	        pos[0] = x;
    ````

7. Attempt to discover where (and why) the fault is occrring in the provided code.
In this case, the line number causing the error is provided. If the location is not in the provided code, use the _gdb bt_ command (bt stands for "backtrace") to determine where the fault occurs. Type `bt` now to see the where the execution stopped in each method:
    ````
    (gdb) bt
    #0  0x0000557bef78e0ab in Tree::Tree (this=0x557bf0c4af50, name="Oak", x=50, 
        y=50) at tree.h:11
    #1  0x0000557bef78d918 in main (argc=1, argv=0x7ffe5db81d18) at main.cc:37
    ````

    The backtrace shows that execution stopped in the method _Tree(name, x, y)_ constructor. This constructor was called from _main()_ on line 37 of _main.cc_.

    The above backtrace indicates that the error happened on line 20 of _tree.h_. Edit the file, and look at line 20. Why is this causing an error?

    Let's fix this error by modifying the code in _tree.h_.  We can use gdb to print out the variables using the debugger.  Try the following:

    ````
    (gdb) print x
    $1 = 50
    (gdb) print y
    $2 = 50
    (gdb) print pos
    $3 = std::vector of length 0, capacity 0
    ````

    On line 20 of Tree.h, it appears we are trying to set values into the _pos_ vector, which is empty and has a length of 0.  The easiest solution is to create the vector with an initialized size.  Instead of...
    ```cpp
    std::vector<double> pos;
    ```
    we can define it as...

    ```cpp
    std::vector<double> pos = std::vector<double>(2);
    ```
    
    which sets our position vector to an initialized double vector of size 2.  **Recompile _entity_app_ with _make_**, and run the program again.

    You can exit gdb by using `q` or `quit` command.

8. Now we will see another error, so let's start the debugger (steps 4-6).  We get the following output when we type _bt_ for viewing the backtrace:

    ````
    (gdb) bt
	#0  __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
    #1  0x00007ffff7a6f859 in __GI_abort () at abort.c:79
    #2  0x00007ffff7ada26e in __libc_message (action=action@entry=do_abort, fmt=fmt@entry=0x7ffff7c04298 "%s\n") at ../sysdeps/posix/libc_fatal.c:155
    #3  0x00007ffff7ae22fc in malloc_printerr (str=str@entry=0x7ffff7c024d9 "free(): invalid size") at malloc.c:5347
    #4  0x00007ffff7ae3b3c in _int_free (av=<optimized out>, p=0x7fffffffdcc0, have_lock=0) at malloc.c:4177
    #5  0x00005555555592bd in Drone::~Drone (this=0x7fffffffdcd0, __in_chrg=<optimized out>) at drone.cc:14
    #6  0x0000555555556dc9 in main (argc=1, argv=0x7fffffffde38) at main.cc:69
    ````

    Fortunately, _gdb_ allows users to navigate the backtrace by typing _up_ and _down_.  When output looks like the above, often it is easiest to look for the highest file in your code.  In this case it is _main.cc:69_.  Let's traverse the backtrace to this location with the _up_ command.  We want to go up 6 levels in the backtrace to #5:

    ````
    (gdb) up 6
    #5  0x000055d95b797de3 in main (argc=1, argv=0x7ffc388ffd58) at main.cc:69
    69	      delete entities[i];
    ````

    Now that we are at this level of the backtrace, we can use `print` to find out more information.  For example, we can print the entities and the specific entity we are trying to delete by printing `i`.  We can also print other information:

    ````
	(gdb) print entities
	$1 = std::vector of length 6, capacity 8 = {0x7fffffffd300, 0x55555556ef90, 
	  0x55555556efe0, 0x55555556f060, 0x55555556eef0, 0x55555556f0e0}
	(gdb) print i
	$2 = 0
	(gdb) print entities[0]
	$3 = (Entity *) 0x7fffffffd300
	(gdb) print entities[0]->GetName()
	$4 = "Entity"
    ````

    Notice how the _up_, _down_, and _print_ commands help us find out more information.  In this case, the problem appears to be trying to delete the first entity in the vector.  Fix the problem, recompile _entity_app_ with _make_, and run the program again.  You may fix the problem however you like.

    There are several causes of segfaults in this program. Use _gdb_ to help to identify and fix each issue until it runs correctly (see step 7). You might find the commands _up_ and _print_ particularly useful.

9. If the program runs smoothly without any errors then you won't be able to use the _bt_ command anymore. So how can we get into certain areas and check out the data? The answer is to use a breakpoint.  With gdb, you can simply set a breakpoint at the lines that you would like to stop and inspect. For example, if you would like to stop and inspect the start of the main function, do the following:
	````
	(gdb) break main
	Breakpoint 1 at 0x5555555565eb: file main.cc, line 10.
	(gdb) run
	Starting program: /home/user/repo/labs/lab03/partB/entity_app
	Breakpoint 1, main (argc=32767, argv=0x7ffff7fb3880) at main.cc:10
	10	int main(int argc, char**argv) {
	````
	This will pause the program at the main function and you can continue to run the program line by line:
	````
	(gdb) n
	13	  int iterations = 3;
	(gdb) n
	14	  double dt = 0.1;
	(gdb) n
	15	  if (argc > 1) {
	````
	Checkout the GDB Quick Guide: [click here](https://condor.depaul.edu/glancast/373class/docs/gdb.html)
	
10. In this program there is a base class called Entity.  MovableEntity and Tree inherit directly from Entity.  Drone and Robot inherit from MoveableEntity.  A robot moves around in a circle of a specified radius and a drone moves in a direction at a specified velocity.  A tree stays in one place (hopefully).  When your program is running correctly, running the executable should exactly produce the following output.

    ````
    Time = 0:
    --------------
    Drone-A, 0, 0, 0
    Oak, 50, 50
    Johnny-Five, 1, 0
    Maple, 100, 100
    Drone-X, 0, 0, 0
    Dave, 4, 0

    Time = 0.1:
    --------------
    Drone-A, 0.0707107, 0.0707107, 0.1
    Oak, 50, 50
    Johnny-Five, 0.995004, 0.0998334
    Maple, 100, 100
    Drone-X, 0.1, 0, 0.1
    Dave, 3.98002, 0.399334

    Time = 0.2:
    --------------
    Drone-A, 0.141421, 0.141421, 0.2
    Oak, 50, 50
    Johnny-Five, 0.980067, 0.198669
    Maple, 100, 100
    Drone-X, 0.2, 0, 0.2
    Dave, 3.92027, 0.794677

    Simulation Complete
    ````

    **If your output does not look like the above, you will need to continue debugging your program to get the correct output.**  There are most likely other bugs in the program besides segfaults.  Consider the following common errors to look for:

     - **Virtual Methods** - Check to see whether methods are polymorphic.  Should some of the methods be declared virtual?
     - **Virtual Destructors** - If a base class does not have a virtual destructor, subclass destructors will not be called.
     - **Referencing Parameters** - It is possible to send in a pointer or reference into a method or constructor and set the memory address.  However, that parameter may go out of scope or get deleted elsewhere in the program.
     - **Unique Pointers** - If you are using dynamic memory, it's often a good idea to use a unique_ptr<type> instead of _new_ and _delete_ if possible.  This way, the pointer will be deleted by the unique_ptr and there will not be a memory leak.
     - **new / delete** - Remember anytime we add an object to the heap with _new_ we must also _delete_ it.  Be sure to use the correct forms of new and delete! For example, if you create an array with _new_ be sure to use _delete[]_ when you delete it.
     - **Casting** - Be sure to use static_cast<>, dynamic_cast<>, and reinterpret_cast<> correctly.
	
     **Note: You may fix these errors however you want.  Perhaps consider adding more polymorphic methods or changing method signitures (return types / parameters).**

11. If you're familiar with Java, you know that the JVM handles recycling the memory dynamically allocated in the heap. However, in C/C++ the memory is not recycled automatically, meaning your program is prone to **memory leakage**.  Memory leakage is an issue that can cause your programs to actually run out of memory.  Both C and C++ require you to do your own memory management; however, the methods to do this are one place where C and C++ are quite distinct.  In C++, the `new` operator is used to dynamically allocate memory. When using the `new` operator you need to use `delete ptrName`. Click [`here`](https://www.geeksforgeeks.org/g-fact-30/) for more information. When dynamically allocating an array using `new [] ` you need to use `delete [] ptrName`. Click [`here`](http://www.cplusplus.com/reference/new/operator%20delete[]/) for more information. **Note: `delete/delete[]` are specific to C++ while `free` works on both C/C++.**  The C programming language, on the other hand, has its own calls for memory management.  All the memory that is allocated dynamically must be recycled using  [`free(void*),`](http://www.cplusplus.com/reference/cstdlib/free/).  `free(void*)` should be used when you're using `malloc` or `calloc`, the memory calls used by the C programming language.  Since we are programming in C++, these **should not** be used in this class.

    With this information, you might be thinking, how can I detect possible memory leaks?  

    This is where using `Valgrind` is helpful in detecting memory leaks. Click [here](https://valgrind.org/docs/manual/quick-start.html) to reference the manual. The Valgrind tool suite provides a number of debugging and profiling tools that help you make your programs faster and more correct. The most popular of these tools is called **Memcheck**. Memcheck helps you by identifying possible memory-related issues in your C/C++ programs.

> ### Note: Step 11 depends on the successful completion of step 10, so please make sure you finish step 10 before continuing to this step. 

### To run Valgrind on your program follow the steps below:

  * Make sure Valgrind is installed on your system (Valgrind is by default installed on CSE machines) by typing `valgrind` in your command prompt. If you're using your own Linux machine, on command prompt run `sudo apt install valgrind`.
  
  * Make sure you compile your code in debugging mode, just like the steps used above in running gdb.
  
  * Then, assuming your program needs two arguments `arg1 arg2`to run on the command prompt (e.g. `./program arg1 arg2`), simply run `valgrind --leak-check=yes ./program arg1 arg2`

    After running valgrind, compare your output to the output below. If the end of your output looks like this, then you've completed the coding part of the lab!

    ````
    $ valgrind --leak-check=yes ./entity_app 

    ==1660== Memcheck, a memory error detector
    ==1660== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==1660== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==1660== Command: ./entity_app
    ==1660== 

    Drone-A, 0.0707107, 0.0707107, 0.1
    Oak, 50, 50
    Johnny-Five, 0.995004, 0.0998334
    Maple, 100, 100
    Drone-X, 0.1, 0, 0.1
    Dave, 3.98002, 0.399334
 
    Time = 0.2:
    --------------
    Drone-A, 0.141421, 0.141421, 0.2
    Oak, 50, 50
    Johnny-Five, 0.980067, 0.198669
    Maple, 100, 100
    Drone-X, 0.2, 0, 0.2
    Dave, 3.92027, 0.794677

    Simulation Complete
    ==1661== 
    ==1661== HEAP SUMMARY:
    ==1661==     in use at exit: 0 bytes in 0 blocks
    ==1661==   total heap usage: 40 allocs, 40 frees, 74,792 bytes allocated
    ==1661== 
    ==1661== All heap blocks were freed -- no leaks are possible
    ==1661==
    ==1661== For lists of detected and suppressed errors, rerun with: -s
    ==1661== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    ````

    If not, don't worry: all you need to do is delete all the dynamically allocated memory using the **appropriate** de-allocation methods. Here's a [link](http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/messages.html) that talks about some common error messages on Valgrind Memcheck.

    When your output looks like the output in step 10 and there are no memory leaks from step 11, you have completed the coding part of the lab!


### Final Submission

Submit your work by completing the two tasks below:

#### Part 1
- Complete the Lab03 Part 1 Gradescope assignment (you may take this multiple times).

#### Part 2
- Push all of your code changes to Github

- Post on the Gradescope assignment "Lab 3 Part 2: Memory and Debugging" your x500 and the commit ID for your submission.

[Click here](https://github.umn.edu/umn-csci-3081-s24/FAQ/blob/main/Commit%20ID/README.md) to see how to obtain commit ID.
