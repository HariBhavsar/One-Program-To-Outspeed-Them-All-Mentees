# Didn't we already do this?
- Alright so last week we built powerful algorithms that enabled us to solve arbitary cnf formulas that were given as inputs from files
- The problem is that practically speaking we aren't going to be having perfect cnf formulae everytime
- Sometimes we just have a boolean formula thats not in CNF but we need to check its satisfiability
- We need to convert such formulae into cnf and then run our SAT solvers on these formulae
- We sometimes also need to dynamically (during runtime) add formulae to our SAT solver
- Thus what we really need is an API that allows us to add arbitary formulae and then check whether the formulae got satisfied
- Internally, the machinery should convert those formulae to CNF and run our CNF solvers
## Converting Arbitary Formulae to CNF
- At a glance it doesn't seem like this is an easy thing to do, and its not
- However, a long time ago there was a person named Grigori Tseitin (yes he's russian), who figured out an O(n) method to convert arbitary formulae to CNF
- His method is known as Tseitin Encoding and I highly recommend that you check it out
- Let me give you a demonstration of tseitin encoding:
- Assume that this is our formula : (((a $\land$ b) $\lor$ (b $\iff$ a)) $\lor$ $\lnot$(a $\lor$ b))
- Now we start at the very bottom nodes, define t1 = a $\land$ b, t2 = b $\iff$ a and t3 = a $\lor$ b
- Now we can rewrite our formula as ((t1 $\lor$ t2) $\lor$ t3)
- Again define t4 = t1 $\lor$ t2
- Our formula becomes (t4 $\lor$ t3)
- Finally, define t = t4 $\lor$ t3
- Set t to true and see if the constraints are satisfiable
- There's a problem though : How do you define equality? 
- Each equality is an $\iff$ operator, so a = b is the same as a $\iff$ b
- We can convert this to (a $\lor$ $\lnot$ b) $\land$ ($\lnot$ a $\lor$ b) (This is in CNF!)
- We can do this for all operators and thus obtain an O(size of original formula) CNF!
## Tasks
- Literally just implement tseitin encoding*
- I have also made a couple of quality-of-life changes in our CNF solver, feel free to use or not use them
- Code tseitin encoding inside of SATsolver.cpp's convertFormula function 
- Check your implementation through `test.cpp`
- Compile using `g++ test.cpp SATsolver.cpp -o testing`