#include "../matrix/matrix.h"

/*

This file checks implementation of the following functions : 
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

    matrix a(2,2);
    a(1,0) = 5;
    std::cout<<"Printing a:\n";
    /*
    
    EXPECTED OUTPUT:
    0 0
    5 0

    */
    a.printMatrix();

    matrix b(a);
    b = b+a;
    std::cout<<"Printing b:\n";
    /*
    
    EXPECTED OUTPUT:
    0 0
    10 0

    */
    b.printMatrix();
    
    matrix c(b);
    c = c-eye(2,2);
    std::cout<<"Printing c:\n";
    /*
    
    EXPECTED OUTPUT:
    -1 0
    10 -1
    
    */
    c.printMatrix();
    
    matrix d = ones(2,2);
    d = d*c;
    std::cout<<"Printing d:\n";
    /*
    
    EXPECTED OUTPUT:
    -1 0
    10 -1
    
    */
    d.printMatrix();
    
    matrix e = zeros(2,2);
    e = e + d + c + b;
    a = ones(2,2);
    a(0,0) = 5;
    e = e/a;
    std::cout<<"Printing e:\n";
    /*
    
    EXPECTED OUTPUT:
    -0.4 0
    30 -2

    */
    e.printMatrix();
    
    matrix f = identity(2);
    std::cout<<"Printing f:\n";
    /*
    
    EXPECTED OUTPUT:
    1 0
    0 1

    */
    f.printMatrix();

}