#include "../matrix/matrix.h"

/*

This file checks implementation of the following functions : 
1]tanh
2]fabs
3]exp
4]log
5]sqrt
It assumes basic operators and max,min,argmax,argmin are implemented correctly

*/

int main () {

    matrix a(identity(2));
    std::cout<<"Printing a:\n";
    /*
    
    EXPECTED OUTPUT:
    1 0 
    0 1

    */
    a.printMatrix();
    
    matrix b = exp(a);
    std::cout<<"Printing b:\n";
    /*
    
    EXPECTED OUTPUT:
    e 1 
    1 e

    */
    b.printMatrix();

    matrix c = zeros(2,2) - b;
    c = fabs(c);
    std::cout<<"Printing c:\n";
    /*
    
    EXPECTED OUTPUT:
    e 1 
    1 e

    */
    c.printMatrix();

    matrix d = zeros(2,2) - b;
    d = tanh(d);
    std::cout<<"Printing d:\n";
    /*
    
    EXPECTED OUTPUT:
    -0.99 -0.76 
    -0.76 -0.99

    */
    d.printMatrix();

    matrix e = log(c,exp(1));
    std::cout<<"Printing e:\n";
    /*
    
    EXPECTED OUTPUT:
    1 0 
    0 1

    */
    e.printMatrix();

    matrix f = sqrt(c);
    std::cout<<"Printing f:\n";
    /*
    
    EXPECTED OUTPUT:
    1.65 1 
    1 1.65

    */
    f.printMatrix();

}