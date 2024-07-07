#include <bits/stdc++.h>
using namespace std;

/*

Now that we know what Boolean Satisfiability is, lets go a bit deeper into how modern day SAT problems are expressed and solved
* Today most SAT problems are expressed in terms of .cnf files, they consist of formulae in conjunctive normal form (CNF)
* What is conjunctive normal form?
* Conjunctive Normal Form is a specific way of writing boolean variables
* A formula in CNF is a set of clauses, {C1,C2,...Cn} and the formula is the conjunction of these clauses, that is,
  each and every clause must be true for the formula to be true
* What is a clause?
* A clause is a set of literals {l1,l2,...lm} and the clause is the disjunction of these literals, that is,
  at least one of these literals must be true for the clause to be true
* What is a literal?
* A literal is either a variable or its negation, that is, l_i = x_j or l_i = ~x_j
* What is a variable?
* The fundamental component of SAT, it can either be true or false

This file will go through the implementation of a naive SAT solver that takes as input a .cnf file and outputs
1] If the formula if satisfiable or not
2] If satisfiable, it gives an assignment of variables that make the formula true

Side note : How do you easily prove that a formula is unsatisfiable?

*/

class naiveSATSolver {
    private:
    bool *x = NULL; // an array of variables, x[i] = 1 if the ith variable is true
    int numVariables; // the number of variables, also the size of the boolean array
    int numClauses; // the number of clauses
    bool isFormulaSAT; // true if the formula turns out to be SAT
    vector<vector<int>> clause;

    public:
    void getInput(); // takes a cnf file as input
    void solve(); // solves the formula
    void printResult(); // prints the result
    void cleanUp(); // resets the SAT solver for next formula
    ~naiveSATSolver() { // on deletion, clean up the sat solver
        cleanUp();  
    };  

};

int main() {

    naiveSATSolver s;
    s.getInput(); // get input
    s.solve(); // solve formula
    s.printResult(); // print the result
    s.cleanUp(); // clean up sat solver

}

void naiveSATSolver::getInput() {
/*

    * The format of a CNF file is as follows:
    c <Comments, meant to be ignored>
    c <More comments>
    p cnf <NumVariables> <NumClauses>
    clause_1Var_1 clause_1Var_2 .. clause_1Var_n 0
    clause_2Var_1 clause_2Var_2 .. clause_2Var_m 0
    ..
    clause_nVar_1 clause_nVar_2 .. clause_nVar_k 0 

*/
    char c = cin.get(); // CNF comments
    while (c == 'c') {
        while (c != '\n') {
            c = cin.get();
        }
        c = cin.get();
    }
    string t;
    cin>>t;

    cin>>numVariables;
    cin>>numClauses;

    for (int i=0; i<numClauses; i++) {
        vector<int> a;
        int x;
        cin>>x;
        while (x != 0) {
            a.push_back(x);
            cin>>x;
        }
        clause.push_back(a);
    }

    x = new bool [numVariables];

}

void naiveSATSolver::solve() {

    // first iterate through all possible variable assignments
    for (uint64_t i=0; i < (1 << numVariables) ; i++) {

        for (int j=0; j<numVariables; j++) {
            if ( i & (1 << j)) {
                x[j] = true;
            }
            else {
                x[j] = false;
            }
        }

        bool moveOnToNextAssignment = false;

        for (uint64_t j=0; j<numClauses; j++) {
            bool clauseSAT = false;
            for (uint64_t k=0; k<clause[j].size(); k++) {
                if (clause[j][k] < 0) { // the clause has the negation of this variable
                    if (x[ -clause[j][k] -1 ] == false) { // so if this variable is false, the clause is satisfied
                        clauseSAT = true;
                        break;
                    }
                }   
                else { // the clause has the variable
                    if (x[clause[j][k] - 1] == true) { // so if the variable is true, the clause is satisfied
                        clauseSAT = true;
                        break;
                    }
                }
            }
            if (!clauseSAT) {
                moveOnToNextAssignment = true;
                break;
            }
        }

        if (!moveOnToNextAssignment) {
            // we have found a satisfying assignment!
            isFormulaSAT = true;
            return;
        }

    }
    isFormulaSAT = false;

}

void naiveSATSolver::printResult() {
    if (isFormulaSAT) {
        cout<<"SAT\n";
        for (int i=0; i<numVariables; i++) {
            int t = 1;
            if (!x[i]) {
                t = 0;
            }
            cout<<i+1<<" : "<<t<<"\n";
        }
    }
    else {
        cout<<"UNSAT\n";
    }
}

void naiveSATSolver::cleanUp() {
    if (x != NULL) {
        delete x;
    }
    x = NULL;
}