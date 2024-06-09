# What is Memoization?
- Memoization is a technique used to reduce the number of recursive calls or redundant computations.
- We will see how it speeds up processes significantly. 
- This is commonly done in dynamic programming and could be thought as software optimisation. 
### Examples
- Go through the recursive implementation of finding the nth fibonacci number in `Fibonacci_R.cpp`
- Go through the dynamic programming based implemenetation in `Fibonacci_M.cpp`
- Use the Makefile to see the difference in performance between the two implementations
- Go through Cache.cpp and try to understand what cache concious programming is
- Implement the loop reordering that gives highest possible performance
- Compile it using `g++ Cache.cpp -o Cache` and then run using `./Cache`
### Task
- There are two files to be modified : `Coins.cpp` and `Subset_Sum.cpp`
- You have to go through the files and understand the questions there, then implement the solutions
- Go through `Coins.cpp` first where the naive recursive solution is already implemented for you
- You are given two binaries so that you have a guage of what the expected amount of time taken for each testcase is
- Use the Makefile to test your implementation
- Use `make Test_Coins` to test your implementation of `Coins.cpp` and `make Test_Subset` to test `Subset_Sum.cpp`
