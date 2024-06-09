#include <iostream>
#include <chrono>

#define Loop(i,a,b) for (int i = a ; i < b ; i++)

typedef long long int ll;

using namespace std;

ll count = 0;
ll* dp;
ll fibonacci_R(ll n){
    count++;
    if (n == 0){
        dp[0] = 1;
        return 1;
    } 
    if (n == 1){
        dp[1] = 1;
        return 1;
    } 
    if (dp[n]!= 0) return dp[n];
    dp[n] = fibonacci_R(n - 1) + fibonacci_R(n - 2);
    return dp[n];
}
int main(){
    ll n;
    cin >> n;   
    dp = new ll[n + 1];
    auto start = chrono::high_resolution_clock::now();
    ll f = fibonacci_R(n);
    f %= 1000000;
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "Time spent " << elapsed.count() << "\n";
    cout << "Number of recurive calls " << count << "\n";
    delete [] dp;
    return 0;
}