#include <iostream>
#include <thread>
#include <immintrin.h>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000000
#define MIN 0.000001

/*

TASK : Given an array of floats A, return an array of probabilities B, such that B[i] = softmax(1/sqrt(A[i]))
The softmax function is defined is follows:
softmax(A)[i] = A[i]/sum_{j=0}^{j=sizeof(A)}(A[j])
The "naive" way of doing this is implemented for you

*/

float quake3Algo (float number) {

    // check out https://en.wikipedia.org/wiki/Fast_inverse_square_root

    union {
        float f;
        uint32_t i;
    } conv;

    float x2;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    conv.f  = number;
    conv.i  = 0x5f3759df - ( conv.i >> 1 ); // evil floating point bit level hacking
    conv.f  = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );
    return conv.f;
}

void naive (float *A, float *B, int n) {
/*

INPUT : float *A, int n
OUTPUT : float *B = softmax(1/sqrt(A))
To be honest this algorithm is not quite naive, it uses the quake 3 algorithm to compute fast inverse square root in O(nlogn)
Then it computes softmax in O(n)

*/

    for (int i=0; i<n; i++) {
        B[i] = quake3Algo(A[i]); // yes u could just use math.sqrt instead but it would not be nearly this cool
    }
    float sum = 0;
    for (int i=0; i<n; i++) {
        B[i] = exp(-B[i]);
    }

    for (int i=0; i<n; i++) {
        sum += B[i];
    }

    for (int i=0; i<n; i++) {
        B[i] = B[i]/sum;
    }

}

void optimal (float *A, float *B, int n) {

/*

STUDENT CODE BEGINS HERE, ACHIEVE A SPEEDUP OVER NAIVE IMPLEMENTATION
YOU MAY EDIT THIS FILE HOWEVER YOU WANT
HINT : USE SIMD INSTRUCTIONS, YOU MAY FIND SOMETHING BEAUTIFUL ONLINE. THEN USE MULTITHREADING FOR SOFTMAX
(Note we do not expect to see a speedup for low values of n, but for n > 100000)

*/

    cout<<"Student code not implemented\n";
    exit(1);

}

int main () {

    int n;
    cin>>n;
    float A[n];
    for (int i=0; i<n; i++) {
        if (i%100 != 0) {
            A[i] = MIN;
        }
        else {
            A[i] = MAX;
        }
    }
    float BNaive[n];
    float BOptim[n];

    auto startNaive = chrono::high_resolution_clock::now();
    naive(A,BNaive,n);
    auto endNaive = chrono::high_resolution_clock::now();
    auto naiveTime = chrono::duration_cast<chrono::duration<double>>(endNaive - startNaive);

    auto startOptim = chrono::high_resolution_clock::now();
    optimal(A,BOptim,n);
    auto endOptim = chrono::high_resolution_clock::now();
    auto optimTime = chrono::duration_cast<chrono::duration<double>>(endOptim - startOptim);

    cout<<"Naive answer : ";
    for (int i=0; i<n; i++) {
        cout<<BNaive[i]<<" ";
    }
    cout<<endl;
    cout<<"Optim answer : ";
    for (int i=0; i<n; i++) {
        cout<<BOptim[i]<<" ";
    }
    cout<<endl;
    cout<<"Naive time : "<<naiveTime.count()<<endl;
    cout<<"Optim time : "<<optimTime.count()<<endl;

}