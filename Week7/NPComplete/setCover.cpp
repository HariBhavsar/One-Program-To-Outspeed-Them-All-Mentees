#include "../SATSolver/SATsolver.h"
#include <iostream>
using namespace std;

/*

Given a set V, a list of subsets S and a number k find out if there exists {i_1,i_2,...i_k} where each i_j is distinct 
and |i_j|<|S| and S[i_1] U S[i_2] U S[i_3] ... S[i_k] = V where U represents set union
It is guaranteed all entries of V are unique (i.e. V is not a multiset)
(I think) this problem is NP-Complete
Either solve this in polynomial time OR use the SAT solver

*/

int main () {
    int lengthOfSet;
    cout<<"Enter length of set : \n";
    cin>>lengthOfSet;
    vector<int> V;
    cout<<"Enter set : \n";
    for (int i=0; i<lengthOfSet; i++) {
        int a;
        cin>>a;
        V.push_back(a);
    }
    int numSubSets;
    cout<<"Enter number of subsets : \n";
    cin>>numSubSets;
    vector<vector<int>> S;
    for (int i=0; i<numSubSets; i++) {
        int lengthOfSubset;
        cout<<"Enter length of subset "<<i<<" : \n";
        cin>>lengthOfSubset;
        cout<<"Enter subset "<<i<<" : \n";
        vector<int> t;
        for (int j=0; j<lengthOfSubset; j++) {
            int x;
            cin>>x;
            t.push_back(x);
        }
        S.push_back(t);
    }

    cout<<"Enter k : \n";
    int k;
    cin>>k;

}