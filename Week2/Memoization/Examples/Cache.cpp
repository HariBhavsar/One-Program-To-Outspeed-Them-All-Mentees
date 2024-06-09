#include <iostream>
#include <chrono>
#include <random>
using namespace std;

int width = 1000; // pls dont change, runtime error aayega
int height = 1000; // pls dont change, runtime error aayega

int main () {

/*

We are going to look at cache concious programming
This will not be very exhaustive but should give you a sense of strong performance gains that can be made

*/

// We will see the time difference between traversing a matrix that is allocated continuously and one that is not

int contMatrix[width*height];
int **sparseMatrix;
int *antiCompiler[width]; // to ensure the sparse matrix isnt allocated continuously
sparseMatrix = new int*[width];
for (int i=0; i<width; i++) {
    sparseMatrix[i] = new int[height];
    antiCompiler[i] = new int[64];
}
for (int i=0; i<width; i++) {
    delete antiCompiler[i];
}
for (int i=0; i<width; i++) {
    for (int j=0; j<height; j++) {
        contMatrix[i*width + j] = sparseMatrix[i][j] = i*width + j;
    }
}
double timeForCont = 0;
double timeForSparse = 0;
int tmp;

for (int i=0; i<1000; i++) {
    auto start = chrono::high_resolution_clock::now();
    for (int i=0; i<width; i++) {
        for (int j=0; j<height; j++) {
            tmp = contMatrix[i*width + j];    
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    timeForCont += elapsed.count();
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<width; i++) {
        for (int j=0; j<height; j++) {
            tmp = sparseMatrix[i][j];
        }
    }
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    timeForSparse += elapsed.count();
}
cout<<timeForCont<<" "<<timeForSparse<<"\n";

/*

we can apply a similar technique to optimize matrix multiplication
we will go after the loop order in matrix multiplication
Traditional matrix multiplication of M1(n*m), M2 (m*l) to produce M3(n*l) code looks as follows:
for (int i=0; i<n; i++) {
    for (int j=0; j<l; j++) {
        M3[i][j] = 0;
        for (int k=0; k<m; k++) {
            M3[i][j] += M1[i][k]*M2[k][j];
        }
    }
}
Is it possible to reorder our loops so that every matrix is accessed sequentially? That is for every Matrix[i][j], j changes before i does
If so then we will have sped up matrix multiplication by quite a bit!
Also just for fun, I will implement the worst possible matrix multiplication

*/
int product[width][height];
double timeForNaive = 0;
double timeForCacheOptim = 0;
double worstPossibleTime = 0;

for (int t=0; t<2; t++) {

    //first up, naive
    auto start = chrono::high_resolution_clock::now();
    for (int i=0; i<width; i++) {
        for (int j=0; j<width; j++) {
            product[i][j] = 0;
            for (int k=0; k<width; k++) {
                product[i][j] += contMatrix[i*width+k]*sparseMatrix[k][j];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    timeForNaive += elapsed.count();
    // resetting matrix
    for (int i=0; i<width; i++) {
        for (int j=0; j<height; j++) {
            product[i][j] = 0;
        }
    }
    //loop reorder
    start = chrono::high_resolution_clock::now();
    //STUDENT CODE BEGINS HERE
    cerr<<"STUDENT CODE NOT IMPLEMENTED!\n";
    exit(1);
    //STUDENT CODE ENDS
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    timeForCacheOptim += elapsed.count();
    // resetting matrix
    for (int i=0; i<width; i++) {
        for (int j=0; j<height; j++) {
            product[i][j] = 0;
        }
    }
    //worst possible
    start = chrono::high_resolution_clock::now();
    // IMPLEMENTED FOR YOU - WORST POSSIBLE
    for (int k=0; k<width; k++) {
        for (int j=0; j<width; j++) {
            for (int i=0; i<width; i++) {
                product[i][j] += contMatrix[i*width + k]*sparseMatrix[k][j];
            }
        }
    }
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    worstPossibleTime += elapsed.count();    
}
cout<<timeForNaive<<" "<<timeForCacheOptim<<" "<<worstPossibleTime<<endl;
}