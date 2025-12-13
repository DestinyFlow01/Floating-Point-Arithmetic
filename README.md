# Floating-Point-Arithmetic

## Introduction
This is my first C code shared online, after a few weeks of studying the C family (C, C++, and C#). I’ve been enjoying the journey, and here’s how I currently rank them:

1. **C**  
   I love the control and predictability it offers. As Uncle Ben said: *“With great power comes great responsibility.”* Memory management must be handled carefully to avoid dangling pointers, leaks, or the infamous segmentation fault. The clarity of variable storage — stack, global, const, and heap via `malloc` — makes performance transparent. I finally understand what Linus Torvalds meant about its power.

2. **C++**  
   I appreciate its features (classes, templates) while retaining much of C’s control. Performance is similar, though I/O streams can be a trap due to type safety overhead, reducing its speed especially in `iostream` and `fstream` library. Modern data types like `vector` and `unordered_map` require careful consideration, since their storage (heap vs. stack) isn’t as obvious, and that affects performance.

3. **C#**  
   It is like having a love-hate relationship here. Its syntax feels familiar to C/C++, but features like the garbage collector (GC) introduce overhead, reducing its speed. However, it still should be noted that the presence of GC actually helps prevent memory leak while spoiling developers not to think about memory management — critical in low level work. Explicit casting enforces good practice but limits the freedom I enjoy in C/C++ on safe and unsafe conversion. For low‑level work and exploration, it’s rarely my first choice.

Beyond these syntaxes, what fascinates me most is how these languages handle numerical precision, a critical aspect in my work. Inspired by my study in Computer Organization and Architecture (COA), I decided to analyze the floating-point arithmetic errors, connecting my CFD background (LBM and numerical methods) with computer science. 

## Problem statement, Code Generation and Preprocessing 
I have long known the issue of floating-point arithmetic errors, truncation errors and roundoff errors during my course of numerical methods in undergraduate aerospace engineering. When studying Linda Null’s *Computer Organization and Architecture* (Chapter 2), i decided to revisit those concepts as two classic cases caught my attention:  
- `0.1 + 0.2 != 0.3`  
- `0.5 + 0.1 == 0.6`

The code is made by using C and plotted using python. Since I would like to emphasize C here, the Jupyter notebook is not being uploaded here due to tremendous difference in size. The binary calculations of the fractional numbers are initially calculated by hand. It is done to prevent initial errors due to addition that emerges on the representation of $0.1$ and $0.2$, and to obtain the exact binary form of $0.3$ and $0.6$ that involves infinite repeating binary fraction. This way, I now have zero error on both $0.6$ and $0.3$ and we can move to C code. The exact binary representation of these two numbers in binary are found to be 
- $(0.3)_{10} = (0.01\overline{0011})_2$
- $(0.6)_{10} = (0.1\overline{0011})_2$

The mathematical symbol of overline in Github is definitely wrong here but I do not really care about it. With the exact binary expansions establish, I then move to C code to test how different data types (in this case `double` and `long double`) handle these values in practice. To run and obtain the files to be analyzed yourselves, you can type this in command prompt in case you do not know it <br> <br>
`
gcc binary_check.c -o bincheck && bincheck > output.txt 2> error.txt
` <br> <br>
and it will also give you `output.txt` and `error.txt` in case something goes wrong.

When run, the code will give you only the iteration numbers and their values. Absolute error can not be calculated directly here, as naive subtraction arithmetic operation will yield another error which should not be there. It is initially being done, resulting in complete zero representation of 0.3, outrageous since it is not the case here. Therefore you will later need Python or Matlab for this purpose, where all tools become sketchy from now on, since all tools and functions have limitation, and naive subtraction and log operations definitely do not work. This is where everything becomes completely insane since I do not know which operations and plotting functions that can be trusted and do not introduce further errors.
