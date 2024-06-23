#include "../matrix/matrix.h"
#include <chrono>
using namespace std;

/*

This file checks timing of the following functions : 
1]constructor
2]access function
3]addition operator
4]subtraction operator
5]eye function
6]multiplication operator
7]ones function
8]division operator
9]identity function

*/

int main () {

    int n;
    cin>>n;
    auto start = chrono::high_resolution_clock::now();
    matrix a = eye(n,n);
    matrix b = ones(n,n);
    matrix c = a*b + a + b;
    for (int i=0; i<50; i++) {
        c = c*a;
        c = c+b;
        c = c/((ones(n,n)+ones(n,n))*b);
        c = c - a;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::duration<double>>(end- start);
    cout<<elapsed.count();
    return 0;

}