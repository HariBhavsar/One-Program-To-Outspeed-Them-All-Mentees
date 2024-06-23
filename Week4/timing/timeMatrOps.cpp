#include "../matrix/matrix.h"
#include <chrono>
using namespace std;

/*

This file checks timing of the following functions : 
1]matmul
2]matrix inverse
3]matrix transpose
4]matrix determinant

*/

int main () {

    int n;
    cin>>n;
    matrix a = eye(n,n);
    matrix b = ones(n,n);
    matrix c = a*b + a + b;
    auto start = chrono::high_resolution_clock::now();

    double norm = c.determinant();
    c = c/norm;
    c = c + eye(n,n);
    matrix d = zeros(n,n);
    d(0,n-1) = 35;
    c = c + d.transpose();
    matrix e = c.inverse();
    c = matmul(c,e);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::duration<double>>(end- start);
    cout<<elapsed.count();
    return 0;

}