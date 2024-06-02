#include <iostream>
#include <thread>
#include <mutex>

#define Loop(i,a,b) for (int i = a ; i < b ; i++)

using namespace std;

mutex m;

void welcome(int id){
    m.lock();
    /*
        1. Try this code with both cout and printf
        2. Try uncommenting the second printf and observe the outputs
    */
    // cout << "I am thread " << id << endl;
    printf("I am thread %d\n",id);
    // printf("Bye %d\n",id);
    m.unlock();
    return;
}


int main(int argc, char* argv[]){
    int n;
    cin >> n;
    thread* t = new thread[n];
    int* id = new int[n];
    Loop(i,0,n){
        id[i] = i;
        int a = i;
        t[i] = thread(welcome,a);
    }
    Loop(i,0,n) t[i].join();    
    delete [] id;
    delete [] t;
    return 0;
}