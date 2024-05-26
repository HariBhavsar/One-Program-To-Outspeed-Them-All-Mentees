#include "template.h"

/*

given two d-dimensional vectors a,b
schur product of a,b is a vector whose ith dimensional component has magnitude a[i]*b[i]
i.e. c = schurProduct(a,b) iff c[i] = a[i]*b[i] for all i 

*/

vec schurProduct(vec v1, vec v2) {
    if (v1.size != v2.size) {
        cout<<"dot product not possible";
        exit(-1);
    }

    // implemented for you, vectorized schur product
    vec v(v1.size);
    #pragma omp parallel for
    for (int i=0; i<v1.size; i++) {
        v.arr[i] = v1.arr[i]*v2.arr[i];
    }
    return v;
}

int sum (vec v) {
    int num = 0;
    for (int i=0; i<v.size; i++) {
        num += v.arr[i];
    }
    return num;
}

int main() {
    int num;
    cin>>num;
    vec v1(num);
    vec v2(num);
    for (int i=0; i<num; i++) {
        v1.arr[i] = i+1;
        v2.arr[i] = i*2;
    }
    int logger = 0; // to prevent compiler optimizations
    auto start = chrono::high_resolution_clock::now();
    for (int i=0; i<1000; i++) {
        schurProduct(v1,v2);
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout<<logger<<" "<<elapsed.count()<<endl;
    v1.free();
    v2.free();
}