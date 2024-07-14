#include "../SATSolver/SATsolver.h"
#include <iostream>
using namespace std;
/*

Given a graph G, determine the minimum number of colors needed to be used to color the graph given the constraint that no two adjacent edges
can have the same color.
Graph:
It consists of two objects
1]int numNodes : The number of vertices in the graph
2]vector<pair<int,int>> adjacencyList : The adjacency list of the graph, adjacencyList[i] = {j,k} implies an edge exists between j and k
Constraints:
1]Each vertex must have exactly one color
2]If there exists an edge between vertex i and vertex j, then color(i) != color(j)
To Find : 
minimum color k that satisfies above constraint
(I think) the above problem is NP-Complete, either find a polynomial algo to solve it OR
Use the SAT solver you built as an oracle to solve it

*/

int main() {
    int numNodes;
    cin>>numNodes;
    vector<pair<int,int>> adjacencyList;
    int numEdges;
    cin>>numEdges;
    for (int i=0; i<numEdges; i++) {
        int a,b;
        cin>>a>>b;
        adjacencyList.push_back(make_pair(a,b));
    }
}