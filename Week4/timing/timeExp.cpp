#include "../matrix/matrix.h"
#include <chrono>
using namespace std;

/*

This file checks timing of the following functions : 
1]tanh
2]fabs
3]exp
4]log
5]sqrt

*/

int main () {

    int n;
    cin>>n;
    matrix a = eye(n,n);
    matrix b = ones(n,n);
    matrix c = a*b + a + b;
    auto start = chrono::high_resolution_clock::now();
    for (int i=0; i<50; i++) {
        c = sqrt(c);
        c = exp(c);
        c = tanh(c);
        c = fabs(c);
        c = exp(c);
        c = log(c,2);
        c = fabs(c);
        c = sqrt(c);
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::duration<double>>(end- start);
    cout<<elapsed.count();
    return 0;

}