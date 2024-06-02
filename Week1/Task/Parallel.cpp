#include "matrix.h"
#define Loop(i,a,b) for (int i = a ; i < b ; i++)
#define MAX_THREADS 8
using namespace std;

Matrix::Matrix(int a, int b) { // generate a matrix (2D array) of dimensions a,b
    this->n = a;
    this->m = b;
    this->M = new int*[a];
    Loop(i, 0, n) this->M[i] = new int[b];
    this->initialiseMatrix();
}

Matrix::~Matrix() { // cleanup heap memory
    Loop(i, 0, this->n) delete[] this->M[i];
    delete[] this->M;
}

void Matrix::initialiseMatrix(){ // initialise entries to 0
    Loop(i, 0, this->n) {
        Loop(j, 0, this->m) this->M[i][j] = 0;
    }
}

void Matrix::inputMatrix() { // take input
    Loop(i, 0, this->n) {
        Loop(j, 0, this->m) cin >> this->M[i][j];
    }
}

void Matrix::displayMatrix() { // print matrix
    Loop(i, 0, this->n) {
        Loop(j, 0, this->m) cout << this->M[i][j] << " ";
        cout << "\n";
    }
}
int** Matrix::T(){
    int** MT = new int*[this->m];
    Loop(i,0,m) MT[i] = new int[this->n];
    Loop(i,0,m){
        Loop(j,0,n){
            MT[i][j] = this->M[j][i];
        }
    }
    return MT;
}

Matrix* Matrix::multiplyMatrix(Matrix* N) {
    if (this->m != N->n) {
        return NULL;
    }
    Matrix *c = new Matrix(this->n,N->m);

    /*
    
    BEGIN STUDENT CODE
    INPUT : this : pointer to matrix A
            N    : pointer to matrix B

    OUTPUT : C   : pointer to matrix C = A*B

    matrix multiplication is defined as following:
    if input matrix A is a matrix of dimensions n1 by n2 and B is a matrix of dimension n2 by n3 then matrix product C = A*B is defined as
    C[i][j] = sum over k = 0 to n2-1 {A[i][k]*B[k][j]}

    */
    cout<<"STUDENT CODE NOT IMPLEMENTED!\n";
    exit(1);
    return c;
}

