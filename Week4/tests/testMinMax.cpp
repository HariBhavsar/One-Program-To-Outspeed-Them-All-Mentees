#include "../matrix/matrix.h"

/*

This file checks implementation and timing of the following functions : 
1]max
2]argmax
3]min
4]argmin
It assumes basic operators are implemented correctly

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
    
    matrix b(a);
    b = b*5;
    std::cout<<"Printing b:\n";
    /*
    
    EXPECTED OUTPUT:
    5 0 
    0 5

    */
    b.printMatrix();
    
    matrix c = max(b);
    std::cout<<"Printing c:\n";
    /*
    
    EXPECTED OUTPUT:
    5 5

    */
    c.printMatrix();
    
    matrix d(b);
    d(0,1) = 8;
    d = max(d,1);
    std::cout<<"Printing d:\n";
    /*
    
    EXPECTED OUTPUT:
    8 
    5

    */
    d.printMatrix();
    
    matrix e = max(d);
    std::cout<<"Printing e:\n";
    /*
    
    EXPECTED OUTPUT:
    8

    */
    e.printMatrix();
    
    matrix f = argmax(b);
    std::cout<<"Printing f:\n";
    /*
    
    EXPECTED OUTPUT:
    0 1

    */
    f.printMatrix();

    matrix c2 = min(b);
    std::cout<<"Printing c2:\n";
    /*
    
    EXPECTED OUTPUT:
    0 0

    */
    c2.printMatrix();
    
    matrix d2(b);
    d2(0,1) = 8;
    d2 = min(d2,1);
    std::cout<<"Printing d2:\n";
    /*
    
    EXPECTED OUTPUT:
    5 
    0 

    */
    d2.printMatrix();
    
    matrix e2 = min(d2);
    std::cout<<"Printing e2:\n";
    /*
    
    EXPECTED OUTPUT: 
    0 

    */
    e2.printMatrix();
    
    matrix f2 = argmin(b);
    std::cout<<"Printing f2:\n";
    /*
    
    EXPECTED OUTPUT:
    1 0 

    */
    f2.printMatrix();

}