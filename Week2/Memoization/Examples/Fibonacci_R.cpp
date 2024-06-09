#include <iostream>
#include <chrono>

#define Loop(i,a,b) for (int i = a ; i < b ; i++)

typedef long long int ll;

using namespace std;

ll count = 0;

ll fibonacci_R(ll n){
    count++;
    if (n == 0) return 1;
    if (n == 1) return 1;
    return fibonacci_R(n - 1) + fibonacci_R(n - 2);
}

int main(){
    ll n;
    cin >> n;   
    auto start = chrono::high_resolution_clock::now();
    ll f = fibonacci_R(n);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "Time spent " << elapsed.count() << "\n";
    cout << "Number of recurive calls " << count << "\n";
    return 0;
}