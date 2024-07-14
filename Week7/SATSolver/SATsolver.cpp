#include "SATsolver.h"

int counterVar = 1;
// I have kept cdcl codes here, but you should delete these and instead compile with your custom cdcl (if u want to :P)
void cdcl::initialise() {
    char c;
    string s;
    
    while (true) {
        cin>>c;
        if (c == 'c') {
            getline(cin,s);
        }
        else {
            cin>>s;
            break;
        }
    }

    cin>>numLiterals;
    cin>>numClauses;
    assignedLiteralCount = 0;
    kappaAntecedent = -1;
    pickCounter = 0;
    alreadyUNSAT = false;

    literals.clear();
    literals.resize(numLiterals,-1);
    literalFreq.clear();
    literalFreq.resize(numLiterals,0);
    literalAntecedent.clear();
    literalAntecedent.resize(numLiterals,-1);
    polarity.clear();
    polarity.resize(numLiterals,0);
    literalDecisionLevel.clear();
    literalDecisionLevel.resize(numLiterals,-1);
    clauses.clear();
    clauses.resize(numClauses);

    int literal;
    int literalCountInClause = 0;
    for (int i=0; i<numClauses; i++) {
        literalCountInClause = 0;
        while (true) {

            cin>>literal;
            if (literal > 0) {
                clauses[i].push_back(literal);
                literalFreq[literal - 1]++;
                polarity[literal - 1]++;
                literalCountInClause++;
            }
            else if (literal < 0) {
                clauses[i].push_back(literal);
                literalFreq[-literal-1]++;
                polarity[-literal-1]--;
                literalCountInClause++;
            }
            else {
                if (literalCountInClause == 0) {
                    alreadyUNSAT = true;
                }
                break;
            }

        }
    }
    originalLiteralFreq = literalFreq;
    // cout<<"Initialisation over, input taken, starting solver!\n";

}

bool cdcl::solve() {
    
    int result = getResult();
    if (result == r_satisfied) {
        return true;
    }
    else {
        return false;
    }
    // showResult(result);

}

int cdcl::getResult() {

    int decisionLevel = 0;
    if (alreadyUNSAT) {
        return RetVal::r_unsatisfied;
    }
    int unitRes = unitPropogate(decisionLevel);
    if (unitRes == RetVal::r_unsatisfied) {
        return unitRes;
    }

    while (!allVarsAssigned()) {

        int pickedVar = pickBranchingVar();
        decisionLevel++;
        assignLiteral(pickedVar,decisionLevel,-1);

        while (true) {
    
            unitRes = unitPropogate(decisionLevel);
            if (unitRes == r_unsatisfied) {
                if (decisionLevel == 0) {
                    return RetVal::r_unsatisfied;
                }
                decisionLevel = backtrack(decisionLevel);
            }
            else {
                break;
            }

        }

    }
    return RetVal::r_satisfied;

}

int cdcl::unitPropogate(int decisionLevel) {
    
    bool unitClauseFound = false;
    int falseCount = 0;
    int unsetCount = 0;
    int literalIndex;
    bool satisfiedFlag = false;
    int lastUnsetLiteral = -1;

    do {

        unitClauseFound = false;
        for (int i=0; i<clauses.size() && !unitClauseFound; i++) {

            falseCount = 0;
            unsetCount = 0;
            satisfiedFlag = false;

            for (int j=0; j<clauses[i].size(); j++) {

                literalIndex = literalToVar(clauses[i][j]);
                if (literals[literalIndex] == -1) {

                    unsetCount++;
                    lastUnsetLiteral = j;

                } 
                else if ((literals[literalIndex] == 0 && clauses[i][j] > 0) || (literals[literalIndex] == 1 && clauses[i][j] < 0)) {
                    falseCount++;
                }
                else {
                    satisfiedFlag = true;
                    break;
                }

            }
            
            if (satisfiedFlag) {
                continue;
            }
            if (unsetCount == 1) {
                assignLiteral(clauses[i][lastUnsetLiteral],decisionLevel,i);
                unitClauseFound = true;
                break;
            }
            else if (falseCount == clauses[i].size()) {
                kappaAntecedent = i;
                return RetVal::r_unsatisfied;
            }

        }

    }
    while (unitClauseFound);

    kappaAntecedent = -1;
    return r_normal;

}

int cdcl::literalToVar(int lit) {
    if (lit > 0) {
        return lit-1;
    }
    else {
        return -lit-1;
    }
} 

void cdcl::assignLiteral(int variable, int decisionLevel, int antecedent) {

    int lit = literalToVar(variable);
    if (variable > 0) {
        literals[lit] = 1;
    }
    else {
        literals[lit] = 0;
    }
    literalAntecedent[lit] = antecedent;
    literalDecisionLevel[lit] = decisionLevel;
    literalFreq[lit] = -1;
    assignedLiteralCount++;

}

int cdcl::pickBranchingVar() {
    
    int mostFreq = 0;
    for (int i=1; i<literalFreq.size(); i++) {
        if (literalFreq[i] > literalFreq[mostFreq]) {
            mostFreq = i;
        }
    }
    if (polarity[mostFreq] >= 0) {
        return mostFreq+1;
    }
    else {
        return -mostFreq-1;
    }

}

int cdcl::backtrack(int decisionLevel) {

    vector<int> learntClauses = clauses[kappaAntecedent];
    int conflictDecisionLevel = decisionLevel;
    int thisLevelCount = 0;              
    int resolverLiteral; 
    int literal;         

    while (true) {

        thisLevelCount = 0;
        for (int i=0; i<learntClauses.size(); i++) {
            literal = literalToVar(learntClauses[i]);
            if (literalDecisionLevel[literal] == decisionLevel) {
                thisLevelCount++;
            }
            if (literalDecisionLevel[literal] == decisionLevel && literalAntecedent[literal] != -1) {
                resolverLiteral = literal;
            }
        }
        if (thisLevelCount == 1) {
            break;
        }
        else {
            learntClauses = resolve(learntClauses,resolverLiteral);
        }

    }
    clauses.push_back(learntClauses);

    for (int i=0; i<learntClauses.size(); i++) {
        int lit = literalToVar(learntClauses[i]);
        if (learntClauses[i] > 0) {
            polarity[lit]++;
        }
        else {
            polarity[lit]--;
        }
        if (literalFreq[lit] != -1) {
            literalFreq[lit]++;
        }
        originalLiteralFreq[lit]++;
    }
    numClauses++;
    int backtrackedDL = 0;

    for (int i=0; i<learntClauses.size(); i++) {
        int lit = literalToVar(learntClauses[i]);
        int litDL = literalDecisionLevel[lit];
        if (litDL != conflictDecisionLevel && litDL > backtrackedDL) {
            backtrackedDL = litDL;
        }
    }

    for (int i=0; i<literals.size(); i++) {
        if (literalDecisionLevel[i] > backtrackedDL) {
            unassignLiteral(i);
        }
    }

    return backtrackedDL;

}

void cdcl::unassignLiteral(int lit) {
    literals[lit] = -1;
    literalDecisionLevel[lit] = -1;
    literalFreq[lit] = originalLiteralFreq[lit];
    literalAntecedent[lit] = -1;
    assignedLiteralCount--;
}

bool cdcl::allVarsAssigned () {
    return (numLiterals == assignedLiteralCount); 
}

vector<int>& cdcl::resolve(vector<int>& clause, int resolutionLiteral) {

    vector<int> otherClause = clauses[literalAntecedent[resolutionLiteral]];
    clause.insert(clause.end(),otherClause.begin(),otherClause.end());
    for (int i=0; i<clause.size(); i++) {
        if (clause[i] == resolutionLiteral + 1 || clause[i] == -resolutionLiteral-1) {
            clause.erase(clause.begin() + i);
            i--;
        }
    }
    sort(clause.begin(), clause.end());
    clause.erase(unique(clause.begin(),clause.end()),clause.end());
    return clause;

}

void cdcl::showResult(int res) {
    if (res == RetVal::r_satisfied) {
        cout<<"SAT"<<" | ";
        for (int i=0; i<literals.size(); i++) {
            if (literals[i] != -1) {
                if (literals[i] > 0) {
                    cout<<(i+1)<<" ";
                }
                else {
                    cout<<"-"<<(i+1)<<" ";
                }
            }
            else {
                cout<<(i+1)<<" ";
            }
        }
        cout<<" 0"<<endl;
    }
    else {
        cout<<"UNSAT"<<endl;
    }

} 

void SATSolver::add(Variable var) {
    auto f = make_shared<Formula>(var);
    constraints.push_back(f);
}

void SATSolver::add(shared_ptr<Formula> f) { // adds the current formula as a constraint, the SAT solver will try to make this formula true
    constraints.push_back(f);
}
// enum Type { VARIABLE, AND, OR, IFF, IF, NOT };
Variable SATSolver::convertFormula(shared_ptr<Formula> F) {
/*
TODO:
Tseitin encoding!
Converts an arbitary formula into CNF in O(n).
Learn more here : Page 29 of https://www.cse.iitb.ac.in/~supratik/courses/cs208/spr24/Lectures_1_to_38.pdf OR https://people.cs.umass.edu/~marius/class/h250/lec2.pdf

Given a formula F, converts it into CNF and returns the variable corresponding to that formula (tsietin)
5 Cases : 
1] F = F1 ^ F2 ; Define Variable t1 = convertFormula(F1), t2 = convertFormula(F2), define variable t, add clause t <-> t1 ^ t2 to constraints, return t
2] F = F1 OR F2 ; Define Variable t2 = convertFormula(F1), t2 = convertFormula(F2), define variable t, add clause t <-> t1 or t2 to constraints, return t
3] F = Not(F1) ; Define Variable t1 = convertFormula(F1), define variable t, add clause t <-> -t1 to constraints, return t
4] F = IF(F1,F2) ; Define Variable t1 = convertFormula(F1), t2 = convertFormula(F2), define variable t, add clause t <-> (t1->t2) to constraints, return t
5] F = IFF(F1,F2) ; Define Variable t1 = convertFormula(F1), t2 = convertFormula(F2), define variable t, add clause t <-> (t1<->t2) to constraints, return t
t <-> t1 ^ t2 = (-t OR (t1 and t2)), (t or -(t1 and t2)) = (-t or t1), (-t or t2), (t or -t1 or -t2)
t <-> t1 OR t2 = (-t OR (t1 OR t2)), (t OR -(t1 or t2)) = (-t or t1 or t2), (t or (-t1 and -t2)) = (-t or t1 or t2),(t or -t1), (t or -t2)
t <-> -t1 = (t OR t1),(-t OR -t1)
t <-> (t1 -> t2) = (-t or (t1->t2)),(t or -(t1->t2)) = (-t or -t1 or t2),(t or -(-t1 or t2)) = (-t or -t1 or t2),(t or (t1 and -t2)) = (-t or -t1 or t2), (t or t1), (t or -t2)
t <-> (t1 <-> t2) = (-t or -t1 or t2),(-t or t1 or -t2),(t or t1 or t2),(t or -t1 or -t2)

*/
Variable t; // delete this lol
return t; // delete this lol
}

void cdcl::setup(vector<vector<int>> cl, int numLits) {
    // in case you're using custom cdcl, add this extra function and make it compatible
    numLiterals = numLits-1;
    numClauses = cl.size();
    assignedLiteralCount = 0;
    kappaAntecedent = -1;
    pickCounter = 0;
    alreadyUNSAT = false;

    literals.clear();
    literals.resize(numLiterals,-1);
    literalFreq.clear();
    literalFreq.resize(numLiterals,0);
    literalAntecedent.clear();
    literalAntecedent.resize(numLiterals,-1);
    polarity.clear();
    polarity.resize(numLiterals,0);
    literalDecisionLevel.clear();
    literalDecisionLevel.resize(numLiterals,-1);
    clauses.clear();
    clauses.resize(numClauses);
    int literal;
    int literalCountInClause = 0;
    for (int i=0; i<numClauses; i++) {
        literalCountInClause = 0;
        for (int j=0; j<cl[i].size(); j++) {
            literal = cl[i][j];
            if (literal > 0) {
                clauses[i].push_back(literal);
                literalFreq[literal - 1]++;
                polarity[literal - 1]++;
                literalCountInClause++;
            }
            else if (literal < 0) {
                clauses[i].push_back(literal);
                literalFreq[-literal-1]++;
                polarity[-literal-1]--;
                literalCountInClause++;
            }
            else {
                if (literalCountInClause == 0) {
                    alreadyUNSAT = true;
                }
                break;
            }         
        }
    }
    originalLiteralFreq = literalFreq;
}

void SATSolver::solve() { // converts formula to cnf and sets the result variable to true if formula is SAT and false otherwise
    convertToCNF();
    numLiterals = counterVar;
    cnfSolver.setup(clauses,counterVar);
    result = cnfSolver.solve();

}

void SATSolver::convertToCNF(){  // make each constraint true
    for (int i=0; i<constraints.size(); i++) {
        int x = variables[convertFormula(constraints[i])];
        vector<int> v;
        v.push_back(x);
        clauses.push_back(v);
    }
}

void SATSolver::reset() {
    clauses.clear();
    variables.clear();
    revVariables.clear();
    constraints.clear();
    result = false;
    counterVar = 1;
}

void SATSolver::printModel() {
    if (!result) {
        return;
    }
    cout<<"Printing mapping : \n";
    for (auto m : variables) {
        cout<<m.first.toString()<<" : "<<m.second<<"\n";
    }
    cnfSolver.showResult(RetVal::r_satisfied);
}