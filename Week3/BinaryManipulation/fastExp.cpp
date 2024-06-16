#include <iostream>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

/*
Last week, we looked at dynamic programming (memoization) and how it speeds up the program.
This week, we'll look at other ways to optimize programs.
We'll first take a classic example of integer exponentiation i.e. Given two integers a, b calculate a to the power of b (a^b)
*/

/* First we'll take a look at the slow way of computing this - it's O(b) */
ll slowPower(ll a , ll b){ // Note - a^b shouldn't be more than 1e18 otherwise this function may return inaccurate results
    ll ans = 1;
    for(ll i = 0; i < b; i++) ans *= a;
    return ans;
}

/* 
Now there's a very efficient technique known as Fast Exponentiation that can compute a^b in O(log b) time.
This technique basically uses the binary representation of b to compute the answer
*/
ll fastPower(ll a , ll b){ // Note - a^b shouldn't be more than 1e18 otherwise this function may return inaccurate results
    ll ans = 1; 
    ll m = a;
    ll i = 1;
    while(b >= i){
        if(b&i) ans*= m; // if the (log i)th bit is set in b, then ans = ans*m
        m*=m; // update m so that m = a^(2^i)
        i= i<<1;
    }
    return ans;
}

int main(){

    ll a = 3;
    ll b = 30;
    auto startNaive = chrono::high_resolution_clock::now();
    ll c = slowPower(a,b);
    auto endNaive = chrono::high_resolution_clock::now();
    auto elapsedNaive = chrono::duration_cast<chrono::duration<double>>(endNaive - startNaive);

    auto startFast = chrono::high_resolution_clock::now();
    ll c2 = fastPower(a,b);
    auto endFast = chrono::high_resolution_clock::now();
    auto elapsedFast = chrono::duration_cast<chrono::duration<double>>(endFast - startFast);

    cout<<"c is : "<<c<<" while c2 is : "<<c2<<endl;
    cout<<"slow time taken : "<<elapsedNaive.count()<<" fast time taken : "<<elapsedFast.count()<<endl;

}