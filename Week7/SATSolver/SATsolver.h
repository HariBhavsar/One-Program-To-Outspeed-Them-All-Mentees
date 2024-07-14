#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// cdcl shamelessly stolen, ideally you should put your custom cdcl code :D
enum RetVal {
    r_satisfied,
    r_unsatisfied,
    r_normal
};

class cdcl {
    // there's a new function here : setup, which allows you to take clauses as input from a SAT solver rather than through std::in
    // also I made solve boolean for convinience
    private:
        vector<int> literals;
        vector<vector<int>> clauses;
        int numLiterals;
        int numClauses;
        vector<int> literalFreq;
        vector<int> polarity;
        vector<int> originalLiteralFreq;
        int kappaAntecedent;
        vector<int> literalDecisionLevel;
        vector<int> literalAntecedent;
        int assignedLiteralCount;
        bool alreadyUNSAT;
        int pickCounter;

        int unitPropogate(int);
        void assignLiteral(int,int,int);
        void unassignLiteral(int);
        int literalToVar(int);
        int backtrack(int);
        vector<int>&resolve (vector<int>&,int);
        int pickBranchingVar();
        bool allVarsAssigned();
    public:
        void showResult(int);
        void setup(vector<vector<int>> cl, int numLits);
        void initialise();
        int getResult();
        bool solve();
};

// A class to denote a variable, we need this for our APIs
class Variable {
public:
    string name;
    bool isNegated;

    Variable& operator= (const Variable& other) {
        this->name = other.name;
        this->isNegated = other.isNegated;
        return *this;
    }

    bool operator< (const Variable& other) const {
        return name < other.name; 
    }

    // Constructor with a name
    void Name(string t) {
        name = t;
        isNegated = false;
    }

    void Not() {
        isNegated = !isNegated;
    }

    string toString() const {
        return name;
    }
};


enum Type { VARIABLE, AND, OR, IFF, IF, NOT };

class Formula {

public:
    Type type;
    Variable var;
    shared_ptr<Formula> left;
    shared_ptr<Formula> right;
    // Constructor for a single variable formula
    Formula(const Variable &v) : type(VARIABLE), var(v) {}

    // Constructor for AND / OR / IFF / IF formulas
    Formula(Type t, const shared_ptr<Formula> &l, const shared_ptr<Formula> &r) : type(t), left(l), right(r) {}

    // Constructor for NOT formulas
    Formula(Type t, const shared_ptr<Formula> &f) : type(t), left(f) {}

    // Static methods for creating AND / OR / IFF / IF / NOT formulas
    static shared_ptr<Formula> And(const shared_ptr<Formula> &left, const shared_ptr<Formula> &right) {
        return make_shared<Formula>(AND, left, right);
    }

    static shared_ptr<Formula> Or(const shared_ptr<Formula> &left, const shared_ptr<Formula> &right) {
        return make_shared<Formula>(OR, left, right);
    }

    static shared_ptr<Formula> Iff(const shared_ptr<Formula> &left, const shared_ptr<Formula> &right) {
        return make_shared<Formula>(IFF, left, right);
    }

    static shared_ptr<Formula> If(const shared_ptr<Formula> &left, const shared_ptr<Formula> &right) {
        return make_shared<Formula>(IF, left, right);
    }

    static shared_ptr<Formula> Not(const shared_ptr<Formula> &f) {
        return make_shared<Formula>(NOT, f);
    }

    string toString() const {
        switch (type) {
            case VARIABLE:
                return var.toString();
            case AND:
                return "(" + left->toString() + " ∧ " + right->toString() + ")";
            case OR:
                return "(" + left->toString() + " ∨ " + right->toString() + ")";
            case IFF:
                return "(" + left->toString() + " ↔ " + right->toString() + ")";
            case IF:
                return "(" + left->toString() + " → " + right->toString() + ")";
            case NOT:
                return "¬(" + left->toString() + ")";
        }
        return "";
    }
};


class SATSolver {
    private:
    cdcl cnfSolver; // our cnf solver :D
    vector<vector<int>> clauses; // where we store our clauses that we give to the cnfsolver via the setup method
    int numLiterals; // helper for cnf
    int numClauses; // helper for cnf
    void convertToCNF(); // helper function, calls convertFormula on each constraint
    map<Variable,int> variables; // mapping from variables to their int representation used by SAT solver
    map<int,Variable> revVariables; // reverse mapping, unused for now but will be used in case satisfying model is wanted
    vector<shared_ptr<Formula>> constraints; // Each constraint that must be satisfied
    Variable convertFormula(shared_ptr<Formula> F); // To be implemented by you! Converts arbitary formula to cnf

    public:
    void add(Variable var); // adds this variable as a constraint => it must be true for satisfiability
    void add(shared_ptr<Formula> f); // adds a formula as a constraint => that formula must be true
    void solve(); // first convert constraints to cnf then call cnf solver and solve
    void reset(); // reset state of SATsolver
    bool result; // true if solve() found a satisfying model, false otherwise
    void printModel(); // prints satisfying model if found
};