#include<iostream>
#include <chrono>
using namespace std;

class vec {
    private:
    public:
    int size;
    int *arr;
    vec(int n) {
        size = n;
        arr = new int[n];
    }
    void free() {
        delete arr;
    }
    void set() {
        for (int i=0; i<size; i++) {
            cin>>arr[i];
        }
    }
};

vec schurProduct (vec v1, vec v2);