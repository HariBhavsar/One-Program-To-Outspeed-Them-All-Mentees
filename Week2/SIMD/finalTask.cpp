#include <iostream>
#include <immintrin.h>
#include <iomanip>
#include <chrono>
using namespace std;
/*

COMPUTE DOT PRODUCT OF TWO VECTORS
INPUTS :n => dimension of vectors
        vec1 => the first vector
        vec2 => the second vector

OUTPUT:dotProduct = vec1.vec2

dotProduct of two vectors is defined as summation_{i=0}^{i=n} [vec1[i]*vec2[i]];

*/
int main () {

    int n;
    cin>>n;
    float vec1[n];
    float vec2[n];
    for (int i=0; i<n; i++) {
        cin>>vec1[i];
    }
    for (int i=0; i<n; i++) {
        cin>>vec2[i];
    }
    float naiveTimeTaken = 0;
    float SIMDTimeTaken = 0;
    float dotProduct = 0;
    for (int i=0; i<1000; i++) {
        dotProduct = 0;
        auto start = chrono::high_resolution_clock::now();
        //NAIVE IMPLEMENTATION FOR COMPARISION PURPOSES
        for (int i=0; i<n; i++) {
            dotProduct += vec1[i]*vec2[i];
        }
        //NAIVE IMPLEMENTATION ENDS
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
        naiveTimeTaken += (elapsed.count())/1000;
    }

    cout<<dotProduct<<" "<<naiveTimeTaken<<" ";
    
    for (int i=0; i<1000; i++) {
        dotProduct = 0;
        auto start2 = chrono::high_resolution_clock::now();
        //STUDENT CODE BEGINS HERE
        cout<<"STUDENT CODE NOT IMPLEMENTED!\n";
        exit(-1);
        //END OF STUDENT CODE
        auto end2 = chrono::high_resolution_clock::now();
        auto elapsed2 = chrono::duration_cast<chrono::duration<double>>(end2 - start2);
        SIMDTimeTaken += (elapsed2.count())/1000;
    }
    cout<<dotProduct<<" "<<SIMDTimeTaken<<" ";
}