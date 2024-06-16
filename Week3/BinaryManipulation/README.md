# Binary Manipulations
- In this section we will exploit the fact that all numbers consists of bits and each bit conveys information
- There are three `.cpp` files in this folder
### fastExp.cpp
- This is your sample file, you are to get an idea of what binary manipulation is and how it works
- Go through and understand the code thats written and why it gives you a speedup on larger values of b
- Compile using `g++ fastExp.cpp -o fastExp`
### fibonacci.cpp
- This is an assignment, you are given the dynamic programming approach to computing fibonacci numbers that you learnt last week
- You are to apply the principles that you learnt in `fastExp.cpp` to obtain a time complexity of O(logn)
- Compile using `g++ fibonacci.cpp -o fibonacci`
### radixSort.cpp
- You are to implement `Radix Sort` which is a sorting algorithm that uses binary manipulation
- Here is a link to better understand this algorithm (note the link implements decimal radix sort, you are to implement binary radix sort which should be easier) : `https://www.geeksforgeeks.org/radix-sort/`
- Compile using `g++ radixSort.cpp -o radixSort`