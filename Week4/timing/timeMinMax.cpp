#include "../matrix/matrix.h"
#include <chrono>
using namespace std;

/*

This file checks timing of the following functions : 
1]max
2]argmax
3]min
4]argmin

*/

int main () {

    int n;
    cin>>n;
    matrix a = eye(n,n);
    matrix b = ones(n,n);
    matrix c = a*b + a + b;
    auto start = chrono::high_resolution_clock::now();

    for (int iter=0; iter<50; iter++) {
        matrix d(max(c));
        matrix e(max(c,1));
        matrix f(min(c));
        matrix g(min(c,1));
        matrix h(argmax(c));
        matrix i(argmax(c,1));
        matrix j(argmin(c));
        matrix k(argmin(c,1));
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::duration<double>>(end- start);
    cout<<elapsed.count();
    return 0;

}