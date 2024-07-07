# Boolean Satisfiability
- It is one of the most important problems we have faced
- Optimising SAT solvers is still being done
- Get started by learning about what SAT is by going through `whatIsSAT.cpp`, compile it with `g++ whatIsSAT.cpp -o whatIsSAt` and run it
- Then, take a look at what a naive SAT solver implementation looks like by going through `naiveSATSolver.cpp`
## Task
- Your task is to implement the `Davis–Putnam–Logemann–Loveland` algorithm, which is the fundamental algorithm behind every SAT solver
- Find out more about the algorithm here : `https://www.cse.iitb.ac.in/~akg/courses/2024-ar/lec-06-cdcl.pdf`
- The essence behind the algorithm is `Unit Propogation`
- You can test out your implementation by running the tests in `dpllTests` (note : not every test will finish, some are just too complicated! They show the need for further optimisations, which is what `CDCL` is made for)
## Unit Propogation
- Find a clause that 
1. Isn't satisfied and
2. Contains exactly one unassigned literal
- For the formula to be satisfied, its clear that the literal must be true, so we assign that literal to true and run again
- If no such clause is found we terminate the algorithm
- If a clause becomes false, we return false
