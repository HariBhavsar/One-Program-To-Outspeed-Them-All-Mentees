#include <bits/stdc++.h>
using namespace std;
/*

The Boolean Satisfiability Problem (SAT) is a fundamental problem in computer science and mathematical logic.
It involves determining whether there exists an assignment of truth values to variables that makes a given Boolean formula true.
In its simplest form, the problem can be represented as a set of logical statements composed of variables and operators such as &&, || and ~
SAT is critically important because it is the first problem proven to be NP-complete
Thus if a polynomial-time algorithm can be found to solve SAT, it could be used to solve all problems in the NP class efficiently.
This has profound implications for fields like cryptography, algorithm design, and artificial intelligence, as many complex problems can be translated into SAT problems.
Consequently, advances in solving SAT can lead to breakthroughs across various domains of computer science and beyond.

In this cpp file, I will guide you through how SAT can be used to prove statements like the Pigeonhole Principle

The Pigeon hold principle is one of the most important theorems in all of mathematics and theoretical computer science, it can be stated as follows
Given Constraints : 
1] There are n pigeons and m holes
2] Each pigeon must occupy exactly one hole
3] Each hole can take at most one pigeon
4] n > m
Then (To Prove or disprove) : 
It is impossible for the above constraints to be satisfied

Lets work on proving this statement (for a particular n,m) with the help of a naive SAT solver
Note : It is also possible to prove for general n,m however that is not very good for providing a learning exercise

*/
int main () {

    int numPigeons;
    cout<<"Enter the number of pigeons (we are using a very naive SAT solver design so enter <= 5): \n";
    cin>>numPigeons;
    int numHoles;
    cout<<"Enter the number of holes: \n";
    cin>>numHoles;
    if (numPigeons <= numHoles) {
        cout<<"The statement is trivially true as the if statement is false!\n";
        return 0;
    }

    if (numPigeons <= 0 || numHoles <= 0) {
        cout<<"Enter positive integers please!\n";
    }

    bool x[numPigeons][numHoles]; // let x[i][j] = 1 if pigeon i is in hole j

/*

    * The Naive SAT solver approach is as follows, we will iterate through all possible values of this matrix
    * In each iteration we check if our constraints are satisfied, if so, we have a counter example
    * Otherwise, the theorem holds for at least this particular (n,m) tuple

*/
    int netPossibilities = 1 << (numPigeons*numHoles); // this is the bitwise shift left operator, netPossibilities = 2^(numPigeons*numHoles)
    for (int i=0; i < netPossibilities; i++) {

        // first generate the matrix
        for (int j=0; j<numPigeons; j++) {
            for (int k=0; k<numHoles; k++) {
                if ((1 << (j*numHoles+k)) & i) { // if the current assignment has x[j][k] as true :)
                    x[j][k] = 1; // then set it as true :)
                }
                else {
                    x[j][k] = 0;
                }
            }
        }

        // now lets check the constraints
        // 1] n pigeons and m holes (satisfied by our inputs)
        // 2] each pigeon must occupy exactly one hole

        bool constraintViolated = false;

        for (int j=0; j<numPigeons; j++) {
            bool u = false;
            for (int k=0; k<numHoles; k++) {
                if ((!u) && x[j][k]) { // if no previous hole had this pigeon but this one does, then our constraint is satisfied
                    u = true; 
                }
                else if (u && x[j][k]) { // some previous hole had this pigeon and this hole also has this pigeon! Constraint violated!
                    u = false;
                    break;
                }
            }
            if (!u) {
                constraintViolated = true;
                break;
            }
        }

        // 3] Each hole must take at most one pigeon
        for (int k=0; k<numHoles; k++) {
            bool holeContainsZeroPigeons = true;
            bool holeContainsOnePigeon = false;
            for (int j=0; j<numPigeons; j++) {
                if (holeContainsZeroPigeons && x[j][k]) { // clearly hole contains one pigeon so far
                    holeContainsOnePigeon = true;
                    holeContainsZeroPigeons = false;
                }
                else if (holeContainsOnePigeon && x[j][k]) { // hole contains 2 pigeons, constraint violated
                    holeContainsOnePigeon = false;
                    break;
                }
            }
            if (!holeContainsOnePigeon && !holeContainsZeroPigeons) {
                constraintViolated = true;
                break;
            }
        }

        if (constraintViolated) {
            continue; // check next possibility
        }
        else {
            cout<<"Constraints not violated! Theorem is false!\n";
            return 1;
        }

    }   

    cout<<"Clearly for every possibility, constraint is violated, thus theorem holds for this particular n,m!\n";
    return 0;
}