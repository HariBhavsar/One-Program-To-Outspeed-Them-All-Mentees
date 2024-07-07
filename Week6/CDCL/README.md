# Conflict-Driven Clause Learning
- This is the algorithm that every modern SAT solver uses
- It is at least 50-100 times faster than DPLL on some cnf inputs and can be even thousands of times faster
- It is DPLL but enhanced with the power of `Machine Learning`
- Learn more about CDCL (and DPLL) here : `https://www.cse.iitb.ac.in/~akg/courses/2024-ar/lec-06-cdcl.pdf`
## What is Conflict Analysis?
- Whenever "conflict" (i.e. a formula becoming UNSAT) occurs, it is due to some assignment of variables that we had done in the past which caused this to occur
- We can thus ask the SAT solver to remember that this particular assignment of variables leads to conflict
- Then we can `backtrack` and make different choices on different variables
## Task
- I have provided a single threaded, kind of unoptimised code of the `Conflict Driven Clause Learning` algorithm
- It is very much possible to optimize this to do better under certain workloads
- Your task is to optimize this and boost performance even more
- I don't think its possible to use a `GPU` here, but multithreading will definitely give you huge boosts
- There are also quite a few software based optimizations you can do, find out more here : `https://www.cse.iitb.ac.in/~akg/courses/2024-ar/lec-07-cdcl-opt-1.pdf` and `https://www.cse.iitb.ac.in/~akg/courses/2024-ar/lec-08-cdcl-opt-2.pdf`
## Todo
- First before changing anything, type `g++ cdcl.cpp -o cdcl && bash run.sh > outUnoptim.txt`
- The shell script simply checks how many tests your code can pass in under 1 second
- If your optimised code is able to pass even one more test that unoptimised code then consider it a huge win