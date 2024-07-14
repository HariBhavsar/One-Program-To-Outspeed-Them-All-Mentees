# NP Complete Problems
- I am assuming that you guys have successfully implemented tseitin encoding
- However what good is a ferrari that has no oil?
- Let us use our powerful SAT solver to solve problems, specifically two NP Complete Problems
- What does NP-Complete mean? It means that these problems are equivalent to SAT, solving them allows you to solve SAT and vice versa
## Minimum coloring
- Given a graph G, subject to certain constraints, find the minimum number of colors required to color the entire graph
- It has been proven to be NP Complete
- Find detailed instructions inside `minColor.cpp`
- Note some tests just won't terminate, which is fine
- Hint : Define var[i][j] to be true iff $i^{th}$ node has $j^{th}$ color and then code your constraints
## Set Cover
- Given a set $V$, a list of subsets of $V$, $S$ and a number k, find if $\exists$ {$i_{1},i_{2},...i_{k}$} such that $S[i_{1}] U S[i_{2}]...S[i_{k}]$ = $V$  
- It has been proven to be NP Complete
- Find detailed instructions inside `setCover.cpp`
- Hint : Represent subsets as boolean vectors with subset[i] = true $\iff$ set[i] $\in$ subset
- NOTE : YOU ARE FORBIDDEN FROM CODING THE SET UNION OPERATION YOURSELF, YOU MUST FIND A WAY OF REPRESENTING IT IN TERMS OF SAT VARIABLES
- Hint 2 : Try to think of a way of making the formula UNSAT $\iff$ a set cover is found 
## More
- I really wanted to give y'all more since this is the final week, however I genuinely just do not have time
- As an implementation exercise, implement and solve `Sudoku`, it has been proven to be NP-complete 