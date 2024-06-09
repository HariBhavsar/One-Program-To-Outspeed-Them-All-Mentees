#include <iostream>
#include <chrono>

#define Loop(i,a,b) for (int i = a ; i < b ; i++)

typedef long long int ll;

using namespace std;
using namespace chrono;

ll Count_R = 0;
ll Count_M = 0;
ll* dp;

ll fibonacci_R(ll n){
    Count_R++;
    if (n == 0) return 1;
    if (n == 1) return 1;
    return fibonacci_R(n - 1) + fibonacci_R(n - 2);
}

ll fibonacci_M(ll n){
    Count_M++;
    if (n == 0){
        dp[0] = 1;
        return 1;
    } 
    if (n == 1){
        dp[1] = 1;
        return 1;
    } 
    if (dp[n] != 0) return dp[n];
    dp[n] = fibonacci_M(n - 1) + fibonacci_M(n - 2);
    return dp[n];
}

int main(int argc, char* argv[]){
    ll n;
    cin >> n;   
    auto start_R = high_resolution_clock::now();
    ll f_R = fibonacci_R(n);
    f_R %= 1000000;
    auto end_R = high_resolution_clock::now();
    auto elapsed_R = duration_cast<duration<double>>(end_R - start_R);
    dp = new ll[n + 1];
    auto start_M = high_resolution_clock::now();
    ll f_M = fibonacci_M(n);
    f_M %= 1000000;
    auto end_M = high_resolution_clock::now();
    auto elapsed_M = duration_cast<duration<double>>(end_M - start_M);
    cout << "\t\t\t Recursion \t" << "Memoization\n";
    cout << "Time spent \t\t" << elapsed_R.count() << "\t" << elapsed_M.count() << "\n";
    cout << "Number of recurive calls " << Count_R << "\t\t" << Count_M << "\n";
    delete [] dp;
    return 0;
}